#include "motors.h"
#include "constants.h"
#include "sensors.h"
#include "strategies.h"

static unsigned char strategy;
SensorValues loopSensorsValues;

void setup() {
  startLED();
  ledOn();

  startAllSensors();
  startMotors();

  strategy = getDIPSwitchValues();

  waitForStartSignal();
  ledOff();
}

void loop() {
  if (loopSensorsValues.microStartPin){
    loopSensorsValues = getLoopSensorsValues();
    runnigStrategy(strategy);
  }
  else{
    stop(0);
  }
}
