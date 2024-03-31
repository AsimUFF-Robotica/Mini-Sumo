/* A estrutura desse projeto foi baseada em:
https://github.com/MinervaBots/ZePequeno

Componentes:
- 2 x DRIVER (PONTE H) DRV8833
- 2 x MOTORES N20 (MENOR) ou 2 x MOTORES MAIOR
- 3 SENSORES DE LINHA QRE1113
- 3 SENSORES DE DISTANCIA(2 x VL53L0X e 1 x JS40F) 
- MICROSTART
- CHAVE SELETORA
- ARDUINO
*/

#include "motors.h"
#include "constants.h"
#include "sensors.h"

unsigned char strategy;
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
