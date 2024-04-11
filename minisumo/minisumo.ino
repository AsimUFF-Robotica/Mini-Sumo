// TODO: Falta atualizar o codigo pois passamos a usar 5 x JS40F em vez dos 3 x VL53L0X.
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
