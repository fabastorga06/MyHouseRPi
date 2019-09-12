#ifndef _DOORHANDLER_H
#define _DOORHANDLER_H

#include "../include/constants.h"
#include "../include/gpio_handler.h"

void enable_doors();
void disable_doors();
int read_door_status(char* gpio);
int door_report(unsigned int door);

#endif