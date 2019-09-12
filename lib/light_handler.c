#include "../include/light_handler.h"

void enable_lights() 
{
    /* export gpios */
    exportPin(LIGHT1_GPIO);
    exportPin(LIGHT2_GPIO);
    exportPin(LIGHT3_GPIO);
    exportPin(LIGHT4_GPIO);
    exportPin(LIGHT5_GPIO);

    /* set lights mode */
    pinMode(LIGHT1_GPIO, OUT);
    pinMode(LIGHT2_GPIO, OUT);
    pinMode(LIGHT3_GPIO, OUT);
    pinMode(LIGHT4_GPIO, OUT);
    pinMode(LIGHT5_GPIO, OUT);
}

void disable_lights() 
{
    /* unexport gpios */
    unexportPin(LIGHT1_GPIO);
    unexportPin(LIGHT2_GPIO);
    unexportPin(LIGHT3_GPIO);
    unexportPin(LIGHT4_GPIO);
    unexportPin(LIGHT5_GPIO);
}

int read_light_status(char* gpio) 
{
    return digitalRead(gpio);
}

void turn_light_on(char* gpio) 
{
    digitalWrite(gpio, ON);
}

void turn_light_off(char* gpio) 
{
    digitalWrite(gpio, OFF);    
}

void change_lights_state( unsigned short allOn) 
{    
    if (allOn) {
        digitalWrite(LIGHT1_GPIO, ON);
        digitalWrite(LIGHT2_GPIO, ON);
        digitalWrite(LIGHT3_GPIO, ON);
        digitalWrite(LIGHT4_GPIO, ON);
        digitalWrite(LIGHT5_GPIO, ON);

    } 
    else {
        digitalWrite(LIGHT1_GPIO, OFF);
        digitalWrite(LIGHT2_GPIO, OFF);
        digitalWrite(LIGHT3_GPIO, OFF);
        digitalWrite(LIGHT4_GPIO, OFF);
        digitalWrite(LIGHT5_GPIO, OFF);
    }
}

int light_report(unsigned int light) 
{
    switch (light)  {
    case LIGHT1_ON:
        return digitalRead(LIGHT1_GPIO);
    case LIGHT2_ON:
        return digitalRead(LIGHT2_GPIO);
    case LIGHT3_ON:
        return digitalRead(LIGHT3_GPIO);
    case LIGHT4_ON:
        return digitalRead(LIGHT4_GPIO);
    case LIGHT5_ON:
        return digitalRead(LIGHT5_GPIO);
    default: 
        break;
    }
}