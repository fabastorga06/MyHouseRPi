#ifndef _LIGHTHANDLER_H
#define _LIGHTHANDLER_H

#include "../include/constants.h"
#include "../include/gpio_handler.h"

void enable_lights();
void disable_lights();
int read_light_status(char* gpio);
void turn_light_on(char* gpio);
void turn_light_off(char* gpio);
void change_lights_state(unsigned short allOn);
char* generate_lights_report();

#endif