#include "motors.h"
#include "constants.h"
#include "sensors.h"
#include "strategies.h"

uint8_t strategy;
SensorValues loopSensorsValues;

void setup() {
  startLED();
  ledOn();

  startAllSensors();
  startMotors();

  getDIPSwitchValues(&strategy);

  waitForStartSignal();
  ledOff();
}

void loop() {
  if (loopSensorsValues.microStartPin){
    getLoopSensorsValues(loopSensorsValues);
    runnigStrategy(&strategy);
  }
  else{
    stop(0);
    getLoopSensorsValues(loopSensorsValues);
  }
}
