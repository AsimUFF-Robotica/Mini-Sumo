#include "motors.h"
#include "constants.h"
#include "sensors.h"
#include "strategies.h"

static unsigned char strategy;
SensorValues loopSensorsValues;

void setup() {
  // LED OFF
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  startAllSensors();
  startMotors();
  strategy = getDIPSwitchValues();

  // LED ON
  digitalWrite(LED_BUILTIN, HIGH);

  // Codigo para o juiz iniciar
  while (loopSensorsValues.microStartPin == 0) {
  }
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
