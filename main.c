#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 

#include "./include/constants.h"
#include "./include/libmanager.h"

#define BUFFER_SIZE 1024

int main(int argc, char** argv ) { 

    if (argc == 1) {
        puts("Error: insert port number");
        return 0;
    }
    int _port = atoi(argv[1]);

    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char msg_rcv[BUFFER_SIZE] = {0}; 
       
    // Creating socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)  { 
        perror("Socket failed"); 
        exit(EXIT_FAILURE); 
    } 

    puts("Socket created...");
       
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( _port ); 
       
    // attach socket to the port 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address)) < 0) { 
        perror("Bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0)  { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen)) < 0)   { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 

    while (1) {
        valread = read( new_socket , msg_rcv, BUFFER_SIZE); 
        printf("%s\n", msg_rcv );  
        if ( LIGHT1 == atoi(msg_rcv) ) {
            printf("Cerrando conexion...\n");
            break;
        }
    }
    close( new_socket );
    return 0; 
} 