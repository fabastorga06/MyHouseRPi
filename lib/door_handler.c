#include "../include/door_handler.h"

void enable_doors(){
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

void disable_doors() {
    /* disable gpio doors */
    unexportPin(DOOR1_GPIO);
    unexportPin(DOOR2_GPIO);
    unexportPin(DOOR3_GPIO);
    unexportPin(DOOR4_GPIO);
}

int read_door_status(char* gpio) {
   return digitalRead(gpio);
}

char* generate_doors_report(char* status) {
    char* door = (digitalRead(DOOR1_GPIO)) ? ON: OFF;
    strcat(status, door);
    door = (digitalRead(DOOR2_GPIO)) ? ON: OFF;
    strcat(status, door);
    door = (digitalRead(DOOR3_GPIO)) ? ON: OFF;
    strcat(status, door);
    door = (digitalRead(DOOR4_GPIO)) ? ON: OFF;
    strcat(status, door);
}