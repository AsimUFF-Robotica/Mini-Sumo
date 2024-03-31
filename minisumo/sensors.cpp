#include <Arduino.h>
#include "sensors.h"
#include "VL53L0X.h"
#include "constants.h"

VL53L0X leftVl53l0xSensor;
VL53L0X rightVl53l0xSensor;

/* -------getDIPSwitchValues-------
*/
unsigned char getDIPSwitchValues() {
  unsigned char result = 0;  // tem 8 bits
  // Lê o estado de cada Switch e configura o bit correspondente
  result |= !digitalRead(SWITCH_ONE);         // Configura o bit 0
  result |= !digitalRead(SWITCH_TWO) << 1;    // Configura o bit 1
  result |= !digitalRead(SWITCH_THREE) << 2;  // Configura o bit 2
  result |= !digitalRead(SWITCH_FOUR) << 3;   // Configura o bit 3
  return result;
}

void startVl53l0x(){
  pinMode(VL53L0X_SDA, OUTPUT);
  pinMode(VL53L0X_SCL, OUTPUT);
  pinMode(VL53L0X_XSHUT_LEFT, OUTPUT);
  pinMode(VL53L0X_XSHUT_RIGHT, OUTPUT);

  delay(500);
  Wire.begin();

  digitalWrite(VL53L0X_XSHUT_LEFT, HIGH);
  delay(150);
  leftVl53l0xSensor.init(true);

  delay(100);
  leftVl53l0xSensor.setAddress((uint8_t)01);

  digitalWrite(VL53L0X_XSHUT_RIGHT, HIGH);
  delay(150);
  rightVl53l0xSensor.init(true);

  delay(100);
  rightVl53l0xSensor.setAddress((uint8_t)02);

  leftVl53l0xSensor.startContinuous();
  rightVl53l0xSensor.startContinuous();
}

void startMicroStart(){
  pinMode(MICRO_START_PIN, INPUT);
}

void startQre1113(){
  pinMode(LEFT_LINE_SENSOR, INPUT);
  pinMode(RIGHT_LINE_SENSOR, INPUT);
  pinMode(BACK_LINE_SENSOR, INPUT);
}

void startJs(){
  pinMode(JS_FRONT_SENSOR, INPUT);
}

void startDIPSwitch(){
  pinMode(SWITCH_ONE, INPUT_PULLUP);
  pinMode(SWITCH_TWO, INPUT_PULLUP);
  pinMode(SWITCH_THREE, INPUT_PULLUP);
  pinMode(SWITCH_FOUR, INPUT_PULLUP);
}

void startAllSensors(){
  startQre1113();
  startMicroStart();
  startVl53l0x();
  startJs();
  startDIPSwitch();
}

// Essa função pode ser otimizada recebendo os dados dos pinos de uma vez só (via PORTB, PORTC, etc)
SensorValues getLoopSensorsValues(){
  SensorValues values;

  // Micro Start
  values.microStartPin = digitalRead(MICRO_START_PIN);
  
  // js (sensor de distancia frontal que retorna 1 caso encontre algo a menos de 40cm)
  values.jsFrontSensor = digitalRead(JS_FRONT_SENSOR);
  
  // 2 x VL53L0X
  values.leftVl53l0xSensorValue = leftVl53l0xSensor.readRangeContinuousMillimeters();
  values.rightVl53l0xSensorValue = rightVl53l0xSensor.readRangeContinuousMillimeters();

  // 3 x QRE1113
  values.rightLineSensor = analogRead(RIGHT_LINE_SENSOR);
  values.leftLineSensor = analogRead(LEFT_LINE_SENSOR);
  values.backLineSensor = analogRead(BACK_LINE_SENSOR);

  return values;
}

/* -------isRobotInEdge-------
A partir dos 3 sensores QRE1113. Retorna:
xx1 -> Sensor da esquerda ve linha branca
x1x -> Sensor da direita ve linha branca
1xx -> Sensor da traseiro ve linha branca
*/
unsigned char isRobotInEdge(int leftLineSensor, int rightLineSensor, int backLineSensor) {
  unsigned char result = 0;
  // TODO: A comparação abaixo pode estar invertida, verificar.
  if (leftLineSensor < QRE_WHITE_LINE_MENOR_THAN) result |= 1;
  if (rightLineSensor < QRE_WHITE_LINE_MENOR_THAN) result |= 2;
  if (backLineSensor < QRE_WHITE_LINE_MENOR_THAN) result |= 4;

  return result;
}