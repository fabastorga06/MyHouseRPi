 /****************************************/
 /*            GPIO Library              */
/*****************************************/

#include "../include/gpio_handler.h"

 void exportPin(char* pin) {
    char cmd[64] = "echo ";
    strcat(cmd, pin);
    strcat(cmd, " > /sys/class/gpio/export");
    system(cmd);
}

void unexportPin(char* pin) {    
    char cmd[64] = "echo ";
    strcat(cmd, pin);
    strcat(cmd, " > /sys/class/gpio/unexport");
    system(cmd);
}

void pinMode (char* pin, char* MODE) {    
    char cmd[64] = "echo ";
	strcat(cmd, MODE);
	strcat(cmd, " > /sys/class/gpio/gpio");
	strcat(cmd, pin);
	strcat(cmd, "/direction");
	system(cmd);

}

void digitalWrite(char* pin, char* value) {
    char cmd[64] = "echo ";
    strcat(cmd, value);
    strcat(cmd, " > /sys/class/gpio/gpio");
    strcat(cmd, pin);
    strcat(cmd, "/value");
    system(cmd);
}

int digitalRead(char* pin) {
    char cmd[64] = "cat /sys/class/gpio/gpio";
    strcat(cmd, pin);
    strcat(cmd, "/value");
    FILE* f = popen(cmd, "r");
    char data[32];
    fgets(data, sizeof(data), f);
	fclose(f);
	int pin_value = atoi(data);
	return pin_value;
}

void blink(char* pin, int freq, unsigned int duration) {
    for(int i = 0; i < freq ; ++i) {
        digitalWrite(pin, "1");
        sleep(duration);
        digitalWrite(pin, "0");
        sleep(duration);
    }
}