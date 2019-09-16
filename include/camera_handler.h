#ifndef _CAMERAHANDLER_H
#define _CAMERAHANDLER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/constants.h"

const char b64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char *take_picture_house(size_t *img_size);
char *process_image(size_t *img_size);
char* b64_encode(const unsigned char *in, size_t len);
size_t b64_encoded_size(size_t inlen);

#endif