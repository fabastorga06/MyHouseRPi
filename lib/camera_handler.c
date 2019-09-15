#include "../include/camera_handler.h"

char* take_picture_house(char* img) 
{
    if (system(CMD_WEBCAM) < 0) {
        perror("Camera is not working...");
    } else  {
        process_image(img);
    }
    return img;
}

void process_image(char* img) 
{
    size_t size = 0;
    FILE* img_data = fopen("myhouse.jpg", "r");
    fseek(img_data, 0, SEEK_END);
    size = ftell(img_data);
    rewind(img_data);
    img = malloc((size + 1) * sizeof(*img) );
    fread(img, size, 1, img_data);
    img[size] = '\0';
    printf("IMAGE: %s\n", img);
}