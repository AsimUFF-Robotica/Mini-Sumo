#include "constants.h"
#include "task.h"
#include "driver.h"

// ---------------[BEGIN] Tasks Time Handler Section
Task tasks[] = {
  // {time in ms, test function, aux}
  {20000, qreSensorTest, false},
  {20000, jsSensorTest, false},
  {20000, dipSwitchTest, false},
  {20000, microStartTest, false},
  // Driver tests:
  {10000, Driver::forward, false}, // Move forward for 10 seconds
  {10000, Driver::coast, false}, // Coast stop for 10 seconds
  {10000, Driver::forward, false}, // Move forward for 10 seconds
  {10000, Driver::brake, false}, // Brake stop for 10 seconds
  {10000, Driver::backward, false}, // Move backward for 10 seconds
  {10000, Driver::brake, false}, // Brake stop for 10 seconds
  {10000, Driver::spinToLeft, false}, // Spin to the left for 10 seconds
  {10000, Driver::spinToRight, false} // Spin to the right for 10 seconds
};

int tasksSize = (int)(sizeof(tasks) / sizeof(Task));
// ---------------[END] Tasks Time Handler Section

void setup() {
  Serial.begin(9600);
  initComponents();
}

void loop() {
  executeSequentialTasks(tasks, tasksSize);
}

// ---------------[BEGIN] PinMode Section
void initQre(){
  pinMode(LEFT_LINE_SENSOR, INPUT);
  pinMode(RIGHT_LINE_SENSOR, INPUT);
  pinMode(BACK_LINE_SENSOR, INPUT);
}

void initJs(){
  pinMode(JS_SENSOR_0, INPUT);
  pinMode(JS_SENSOR_1, INPUT);
  pinMode(JS_SENSOR_2, INPUT);
  pinMode(JS_SENSOR_3, INPUT);
  pinMode(JS_SENSOR_4, INPUT);
}

void initDipSwitch(){
  pinMode(SWITCH_ONE, INPUT_PULLUP);
  pinMode(SWITCH_TWO, INPUT_PULLUP);
  pinMode(SWITCH_THREE, INPUT_PULLUP);
  pinMode(SWITCH_FOUR, INPUT_PULLUP);
}

void initMicroStart(){
  pinMode(MICRO_START_PIN, INPUT);
}

void initComponents(){
  initQre();
  initJs();
  initDipSwitch();
  initMicroStart();
  Driver::initDriver();
}
// ---------------[END] PinMode Section

// ---------------[BEGIN] Tests Section
void qreSensorTest() {
  Serial.println("RIGHT_LINE_SENSOR: " + String(analogRead(RIGHT_LINE_SENSOR)) + 
  "\tLEFT_LINE_SENSOR:" + String(analogRead(LEFT_LINE_SENSOR)) + 
  "\tBACK_LINE_SENSOR:" + String(analogRead(BACK_LINE_SENSOR)));
}

void jsSensorTest(){
  Serial.println("JS_SENSOR_0 Pin: "+ String(JS_SENSOR_0) +"\tOutput: "+ String(digitalRead(JS_SENSOR_0)) + 
  "\tJS_SENSOR_1 Pin: "+ String(JS_SENSOR_1) +"\tOutput: "+ String(digitalRead(JS_SENSOR_1)) + 
  "\tJS_SENSOR_2 Pin: "+ String(JS_SENSOR_2) +"\tOutput: "+ String(digitalRead(JS_SENSOR_2)) + 
  "\tJS_SENSOR_3 Pin: "+ String(JS_SENSOR_3) +"\tOutput: "+ String(digitalRead(JS_SENSOR_3)) + 
  "\tJS_SENSOR_4 Pin: "+ String(JS_SENSOR_4) +"\tOutput: "+ String(digitalRead(JS_SENSOR_4)));
}

void dipSwitchTest(){
  Serial.println("SWITCH_ONE Pin: "+ String(SWITCH_ONE) +"\tOutput: "+ String(digitalRead(SWITCH_ONE)) + 
  "\tSWITCH_TWO Pin: "+ String(SWITCH_TWO) +"\tOutput: "+ String(digitalRead(SWITCH_TWO)) + 
  "\tSWITCH_THREE Pin: "+ String(SWITCH_THREE) +"\tOutput: "+ String(digitalRead(SWITCH_THREE)) + 
  "\tSWITCH_FOUR Pin: "+ String(SWITCH_FOUR) +"\tOutput: "+ String(digitalRead(SWITCH_FOUR)));
}

void microStartTest(){
    Serial.println("MICRO_START_PIN Pin: " + String(MICRO_START_PIN) + "\tOutput: " + String(digitalRead(MICRO_START_PIN)));
}
// ---------------[END] Tests Section
