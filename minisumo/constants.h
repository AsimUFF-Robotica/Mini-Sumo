#ifndef CONSTANTS_H
#define CONSTANTS_H

// Drivers
#define RIGHT_WHEEL_IN_1 9
#define RIGHT_WHEEL_IN_2 10
#define LEFT_WHEEL_IN_1 5
#define LEFT_WHEEL_IN_2 6
#define MAX_PWM 255

// DIP Switch
// Para ligar/desligar o robo -> SWITCH_ONE 1 
// Para estrategias:
#define SWITCH_TWO 2
#define SWITCH_THREE 3
#define SWITCH_FOUR 4

// QRE line sensor 
#define QRE_WHITE_LINE_MENOR_THAN 600 // TODO: Revisar esse valor
#define RIGHT_LINE_SENSOR A0 //PF7
#define LEFT_LINE_SENSOR A1 //PF6
#define BACK_LINE_SENSOR A2 //PF5

// JS
#define JS_SENSOR_FRONT 3 //PD0
#define JS_SENSOR_FRONT_LEFT 4 //PD4
#define JS_SENSOR_FRONT_RIGHT 7 //PE6
#define JS_SENSOR_SIDE_LEFT 8 //PB4
#define JS_SENSOR_SIDE_RIGHT 11 //PB7

// Micro Start
#define MICRO_START_PIN A3 //PF4

// Strategies
#define SPIN_180_DURATION_MS_WITH_MAXPW 1000

#endif