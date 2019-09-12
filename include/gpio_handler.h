#ifndef _GPIOHANDLER_H
#define _GPIOHANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void exportPin(char* pin);
void unexportPin(char* pin) ;
void pinMode (char* pin, char* MODE);
void digitalWrite(char* pin, char* value);
int digitalRead(char* pin);
void blink(char* pin, int freq, unsigned int duration);

#endif