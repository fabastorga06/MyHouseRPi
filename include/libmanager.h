#ifndef _LIBMANAGER_H
#define _LIBMANAGER_H

void exportPin(char* pin );
void unexportPin(char* pin ) ;
void pinMode (char* pin, char* MODE );
void digitalWrite(char* pin, char* value );
int digitalRead(char* pin);
void blink(char* pin, int freq, unsigned int duration);

#endif