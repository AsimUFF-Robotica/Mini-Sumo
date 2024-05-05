#ifndef CONSTANTS_H
#define CONSTANTS_H

// Drivers
#define RIGHT_WHEEL_IN_1 9
#define RIGHT_WHEEL_IN_2 10
#define LEFT_WHEEL_IN_1 5
#define LEFT_WHEEL_IN_2 6
#define MAX_PWM 255

// DIP Switch
#define SWITCH_ONE 1
#define SWITCH_TWO 2
#define SWITCH_THREE 3
#define SWITCH_FOUR 4

// QRE line sensor 
#define RIGHT_LINE_SENSOR A0
#define LEFT_LINE_SENSOR A1
#define BACK_LINE_SENSOR A2

// JS
#define JS_SENSOR_0 3
#define JS_SENSOR_1 4
#define JS_SENSOR_2 7
#define JS_SENSOR_3 8
#define JS_SENSOR_4 11

// Micro Start
#define MICRO_START_PIN 13

// functions to task
void qreSensorTest();
void jsSensorTest();
void dipSwitchTest();
void microStartTest();

#endif