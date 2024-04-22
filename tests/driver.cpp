#include "driver.h"
#include "Arduino.h"
#include "constants.h"

void Driver::initDriver() {
    pinMode(RIGHT_WHEEL_IN_1, OUTPUT);
    pinMode(RIGHT_WHEEL_IN_2, OUTPUT);
    pinMode(LEFT_WHEEL_IN_1, OUTPUT);
    pinMode(LEFT_WHEEL_IN_2, OUTPUT);
}

void Driver::forward() {
    analogWrite(LEFT_WHEEL_IN_1, 255);
    digitalWrite(LEFT_WHEEL_IN_2, LOW);
    analogWrite(RIGHT_WHEEL_IN_1, 255);
    digitalWrite(RIGHT_WHEEL_IN_2, LOW);
    Serial.println("Driver test: Forwarding.");
}

void Driver::backward() {
    digitalWrite(LEFT_WHEEL_IN_1, LOW);
    analogWrite(LEFT_WHEEL_IN_2, 255);
    digitalWrite(RIGHT_WHEEL_IN_1, LOW);
    analogWrite(RIGHT_WHEEL_IN_2, 255);
    Serial.println("Driver test: Backwarding.")
}

void Driver::spinToLeft() {
    digitalWrite(LEFT_WHEEL_IN_1, LOW);
    analogWrite(LEFT_WHEEL_IN_2, 255);
    analogWrite(RIGHT_WHEEL_IN_1, 255);
    digitalWrite(RIGHT_WHEEL_IN_2, LOW);
    Serial.println("Driver test: Spinning to Left.");
}

void Driver::spinToRight() {
        analogWrite(LEFT_WHEEL_IN_1, 255);
        digitalWrite(LEFT_WHEEL_IN_2, LOW);
        digitalWrite(RIGHT_WHEEL_IN_1, LOW);
        analogWrite(RIGHT_WHEEL_IN_2, 255);
        Serial.println("Driver test: Spinning to Right.");
}

void Driver::coast() {
    digitalWrite(RIGHT_WHEEL_IN_1, LOW);
    digitalWrite(RIGHT_WHEEL_IN_2, LOW);
    digitalWrite(LEFT_WHEEL_IN_1, LOW);
    digitalWrite(LEFT_WHEEL_IN_2, LOW);
    Serial.println("Driver test: Coasting.");
}

void Driver::brake() {
    digitalWrite(LEFT_WHEEL_IN_1, HIGH);
    digitalWrite(LEFT_WHEEL_IN_2, HIGH);
    digitalWrite(RIGHT_WHEEL_IN_1, HIGH);
    digitalWrite(RIGHT_WHEEL_IN_2, HIGH);
    Serial.println("Driver test: Braking.");
}