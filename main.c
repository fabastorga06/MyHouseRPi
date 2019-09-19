#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#include "../include/constants.h"
#include "../include/light_handler.h"
#include "../include/door_handler.h"
#include "../include/camera_handler.h"

void light_manager(int socket, char *gpio, unsigned short on)
{
    if (on)
    {
        turn_light_on(gpio);
    }
    else
    {
        turn_light_off(gpio);
    }
    int response = write(socket, OK, 2);
    if (response < 0)
    {
        perror("Writing on socket failed.");
    }
}

void make_house_report(char *rep)
{
    for (int i = 0; i < AMOUNT_LIGHTS; ++i)
    {
        if (light_report(i + 1))
        {
            rep[i] = '1';
        }
        else
        {
            rep[i] = '0';
        }
    }

    for (int j = AMOUNT_DOORS + 1; j < REPORT_SIZE; ++j)
    {
        if (door_report(j + 1))
        {
            rep[j] = '1';
        }
        else
        {
            rep[j] = '0';
        }
    }
}

void house_alert(int socket, char *report)
{
    puts("Generating house report...");
    make_house_report(report);

    if (write(socket, report, REPORT_SIZE) < 0)
    {
        perror("Writing on socket failed.");
    }
}

void check_house_by_camera(int socket, char *image)
{
    size_t img_size = 0;
    image = take_picture_house(&img_size);
    printf("IMAGE: %s\n", image);
    if (write(socket, image, img_size) < 0)
    {
        perror("Writing on socket failed.");
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        puts("Error: insert port number");
        return 0;
    }
    int port = atoi(argv[1]);

    int server_fd, my_house_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char msg_rcv[BUFFER_SIZE] = {0};
    char *house_report = malloc(sizeof(char) * REPORT_SIZE);
    char *img = NULL;

    /****************** Create socket ********************************/
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    puts("Socket created...");

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    /**********  Attach socket to the port **************************/
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    // if ((my_house_socket = accept(server_fd, (struct sockaddr *)&address,
    //                    (socklen_t*)&addrlen)) < 0)   {
    //     perror("accept");
    //     exit(EXIT_FAILURE);
    // }

    /************* Set communication among app and server *************************/

    enable_lights();
    enable_doors();

    while (TRUE)
    {
        if ((my_house_socket = accept(server_fd, (struct sockaddr *)&address,
                                      (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        valread = read(my_house_socket, msg_rcv, BUFFER_SIZE);
        printf("%s\n", msg_rcv);

        switch (atoi(msg_rcv))
        {

            /******************** LIGHTS ON/OFF *******************************************/
        case LIGHT1_ON:
            puts("Light 1 ON\n");
            light_manager(my_house_socket, LIGHT1_GPIO, TRUE);
            close(my_house_socket);
            break;

        case LIGHT2_ON:
            puts("Light 2 ON\n");
            light_manager(my_house_socket, LIGHT2_GPIO, TRUE);
            close(my_house_socket);
            break;

        case LIGHT3_ON:
            puts("Light 3 ON\n");
            light_manager(my_house_socket, LIGHT3_GPIO, TRUE);
            close(my_house_socket);
            break;

        case LIGHT4_ON:
            puts("Light 4 ON\n");
            light_manager(my_house_socket, LIGHT4_GPIO, TRUE);
            close(my_house_socket);
            break;

        case LIGHT5_ON:
            puts("Light 5 ON\n");
            light_manager(my_house_socket, LIGHT5_GPIO, TRUE);
            close(my_house_socket);
            break;

        case LIGHT1_OFF:
            puts("Light 1 OFF\n");
            light_manager(my_house_socket, LIGHT1_GPIO, FALSE);
            close(my_house_socket);
            break;

        case LIGHT2_OFF:
            puts("Light 2 OFF\n");
            light_manager(my_house_socket, LIGHT2_GPIO, FALSE);
            close(my_house_socket);
            break;

        case LIGHT3_OFF:
            puts("Light 3 OFF\n");
            light_manager(my_house_socket, LIGHT3_GPIO, FALSE);
            close(my_house_socket);
            break;

        case LIGHT4_OFF:
            puts("Light 4 OFF\n");
            light_manager(my_house_socket, LIGHT4_GPIO, FALSE);
            close(my_house_socket);
            break;

        case LIGHT5_OFF:
            puts("Light 5 OFF\n");
            light_manager(my_house_socket, LIGHT5_GPIO, FALSE);
            close(my_house_socket);
            break;

        case ALL_LIGHTS_OFF:
            change_lights_state(FALSE);
            close(my_house_socket);
            break;

        case ALL_LIGHTS_ON:
            change_lights_state(TRUE);
            close(my_house_socket);
            break;

        /******************** DOORS STATUS OPEN/CLOSE ******************************/
        case HOUSE_STATUS:
            puts("Checking doors...\n");
            house_alert(my_house_socket, house_report);
            close(my_house_socket);
            break;

        /*********************** WEBCAM ***********************************/
        case WEBCAM:
            puts("Checking house...\n");
            check_house_by_camera(my_house_socket, img);
            puts("Picture taken.");
            close(my_house_socket);
            break;

        default:
            close(my_house_socket);
            break;
        }

        sleep(0.25);
    }
    disable_lights();
    disable_doors();
    free(img);
    close(my_house_socket);
    return 0;
}