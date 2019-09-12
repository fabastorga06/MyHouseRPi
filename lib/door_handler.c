#include "../include/door_handler.h"

void enable_doors()
{
    /* enable gpio doors */
    exportPin(DOOR1_GPIO);
    exportPin(DOOR2_GPIO);
    exportPin(DOOR3_GPIO);
    exportPin(DOOR4_GPIO);
    /* change door mode to in */
    pinMode(DOOR1_GPIO, IN);
    pinMode(DOOR2_GPIO, IN);
    pinMode(DOOR3_GPIO, IN);
    pinMode(DOOR4_GPIO, IN);
}

void disable_doors() 
{
    /* disable gpio doors */
    unexportPin(DOOR1_GPIO);
    unexportPin(DOOR2_GPIO);
    unexportPin(DOOR3_GPIO);
    unexportPin(DOOR4_GPIO);
}

int read_door_status(char* gpio) 
{
   return digitalRead(gpio);
}

int door_report(unsigned int door)
{
    switch (door)  {
    case DOOR1:
        return digitalRead(DOOR1_GPIO);
    case DOOR2:
        return digitalRead(DOOR2_GPIO);
    case DOOR3:
        return digitalRead(DOOR3_GPIO);
    case DOOR4:
        return digitalRead(DOOR4_GPIO);
    default: 
        break;
    }    
}