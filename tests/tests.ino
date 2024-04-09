#include "constants.h"

// Definindo variáveis dos sensores globalmente
int rightLineSensor;
int leftLineSensor;
int backLineSensor;

int MICRO_START_PIN;


unsigned long tempoInicial = millis();

void startQre1113(){
  pinMode(LEFT_LINE_SENSOR, INPUT);
  pinMode(RIGHT_LINE_SENSOR, INPUT);
  pinMode(BACK_LINE_SENSOR, INPUT);
}

void startMicroStart(){
  pinMode(MICRO_START_PIN 13,INPUT);
}

void setup() {
  // Inicialização do Serial para comunicação
  Serial.begin(9600);
  startQre1113();
  startMicroStart();
  while(digitalRead(MICRO_START_PIN) == 0){
    Serial.println("standby");
  }
  
}

void loop() {
  qreTest(20000);
  microStartTest();
  
}


void microStartTest(){
  // Implemente o teste para o componente MICROSTART
  while(digitalRead(MICRO_START_PIN) == 1){
    Serial.println("start running");
  }
}

void driverTest(){
  // Implemente o teste para os 2 x DRIVER (PONTE H) DRV8833
}


void qreTest(int time) {
  if (millis() - tempoInicial >= time) { 
    qreSensorTest();
  }
}

void qreSensorTest() {
  // Leitura dos sensores de linha
  rightLineSensor = analogRead(RIGHT_LINE_SENSOR);
  leftLineSensor = analogRead(LEFT_LINE_SENSOR);
  backLineSensor = analogRead(BACK_LINE_SENSOR);
  
  Serial.println("sensor de linha qre direita: " + String(rightLineSensor) + 
  "sensor de linha qre esquerda:" + String(leftLineSensor) + 
  "sensor de linha qre traseiro:" + String(backLineSensor));

  delay(200);
}

void dipSwitchTest(){
  // Implemente o teste para a CHAVE SELETORA de 3 pinos
}

void jsSensorTest(){
  // Implemente o teste para os 5 SENSORES DE DISTANCIA (5 x JS40F)
}
