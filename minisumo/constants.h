#ifndef CONSTANTS_H
#define CONSTANTS_H

// Drivers
#define RIGHT_WHEEL_IN_1 5
#define RIGHT_WHEEL_IN_2 6
#define LEFT_WHEEL_IN_1 10
#define LEFT_WHEEL_IN_2 9
#define MAX_PWM 255

// DIP Switch
// TODO: Encontrar pinos livres para o DIP Switch
#define SWITCH_ONE 100
#define SWITCH_TWO 101
#define SWITCH_THREE 102
#define SWITCH_FOUR 103

// QRE line sensor 
#define QRE_WHITE_LINE_MENOR_THAN 600 // TODO: Revisar esse valor
#define RIGHT_LINE_SENSOR A6
#define LEFT_LINE_SENSOR A7
#define BACK_LINE_SENSOR A8

// JS
#define JS_FRONT_SENSOR 13

// VL53L0X
#define VL53L0X_SDA A4
#define VL53L0X_SCL A5
#define VL53L0X_XSHUT_LEFT 7
#define VL53L0X_XSHUT_RIGHT 8

// Micro Start
#define MICRO_START_PIN A3

// Strategies
#define SPIN_180_DURATION_MS_WITH_MAXPW 1000
#define DIRECT_SPIN_DURATION_MS 2000

#endif