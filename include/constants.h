#ifndef _CONSTANTS_H
#define _CONSTANTS_H

/****** Socket message indicators *******/
#define LIGHT1_ON 1
#define LIGHT2_ON 2
#define LIGHT3_ON 3
#define LIGHT4_ON 4
#define LIGHT5_ON 5
#define LIGHT1_OFF 6
#define LIGHT2_OFF 7
#define LIGHT3_OFF 8
#define LIGHT4_OFF 9
#define LIGHT5_OFF 10
#define ALL_LIGHTS_ON 11
#define ALL_LIGHTS_OFF 12
#define HOUSE_STATUS 13
#define WEBCAM 14

/****** Util constants *******/
#define OK "ok"

#define IN "in"
#define OUT "out"

#define ON "1"
#define OFF "0"

#define CMD_WEBCAM "fswebcam -r 1280x720 --no-banner -d /dev/video0 myhouse.jpg"

#define BUFFER_SIZE 1024

#define TRUE 1
#define FALSE 0

#define REPORT_SIZE 9
#define AMOUNT_LIGHTS 5
#define AMOUNT_DOORS 4

#define DOOR1 6
#define DOOR2 7
#define DOOR3 8
#define DOOR4 9

/****** GPIO Pins *******/
#define LIGHT1_GPIO "2"
#define LIGHT2_GPIO "3"
#define LIGHT3_GPIO "4"
#define LIGHT4_GPIO "17"
#define LIGHT5_GPIO "27"

#define DOOR1_GPIO "14"
#define DOOR2_GPIO "15"
#define DOOR3_GPIO "18"
#define DOOR4_GPIO "23"

#endif