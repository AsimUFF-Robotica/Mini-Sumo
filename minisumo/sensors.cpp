#include <Arduino.h>
#include "sensors.h"
#include "constants.h"

/* -------getDIPSwitchValues-------
*/
unsigned char getDIPSwitchValues() {
  // TODO: remover leitura do SWITCH_ONE pois ele sera usado para ligar/desligar robo, e não para estrategias.
  unsigned char result = 0;  // tem 8 bits
  // Lê o estado de cada Switch e configura o bit correspondente
  result |= !digitalRead(SWITCH_ONE);         // Configura o bit 0
  result |= !digitalRead(SWITCH_TWO) << 1;    // Configura o bit 1
  result |= !digitalRead(SWITCH_THREE) << 2;  // Configura o bit 2
  result |= !digitalRead(SWITCH_FOUR) << 3;   // Configura o bit 3
  return result;
}


// TODO: Otimizar essa função recebendo os dados dos pinos de uma vez só (via PORTB, PORTC, etc)
SensorValues getLoopSensorsValues(){
  SensorValues values;

  // Micro Start
  values.microStartPin = digitalRead(MICRO_START_PIN);

  // js sensor de distancia frontal que retorna 1 caso encontre algo a menos de 40(?)cm
  values.jsFrontSensor = digitalRead(JS_SENSOR_FRONT);
  values.jsFrontLeftSensor = digitalRead(JS_SENSOR_FRONT_LEFT);
  values.jsFrontRightSensor = digitalRead(JS_SENSOR_FRONT_RIGHT);
  values.jsSideLeftSensor = digitalRead(JS_SENSOR_SIDE_LEFT);
  values.jsSideRightSensor = digitalRead(JS_SENSOR_SIDE_RIGHT);

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


void startJs(){
  pinMode(JS_SENSOR_FRONT, INPUT);
  pinMode(JS_SENSOR_FRONT_LEFT, INPUT);
  pinMode(JS_SENSOR_FRONT_RIGHT, INPUT);
  pinMode(JS_SENSOR_SIDE_LEFT, INPUT);
  pinMode(JS_SENSOR_SIDE_RIGHT, INPUT);
}


void startMicroStart(){
  pinMode(MICRO_START_PIN, INPUT);
}


void startQre1113(){
  pinMode(LEFT_LINE_SENSOR, INPUT);
  pinMode(RIGHT_LINE_SENSOR, INPUT);
  pinMode(BACK_LINE_SENSOR, INPUT);
}


void startDIPSwitch(){
  pinMode(SWITCH_ONE, INPUT_PULLUP);
  pinMode(SWITCH_TWO, INPUT_PULLUP);
  pinMode(SWITCH_THREE, INPUT_PULLUP);
  pinMode(SWITCH_FOUR, INPUT_PULLUP);
}


void startLED(){
  pinMode(LED_BUILTIN, OUTPUT);
}


void ledOn() {
    digitalWrite(LED_BUILTIN, HIGH);
}


void ledOff() {
    digitalWrite(LED_BUILTIN, LOW);
}


void startAllSensors(){
  startQre1113();
  startMicroStart();
  startJs();
  startDIPSwitch();
}

void waitForStartSignal() {
  while (digitalRead(MICRO_START_PIN) == LOW) {
  }
}