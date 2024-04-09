/* 
Componentes:
- 2 x DRIVER (PONTE H) DRV8833
- 2 x MOTORES N20 (MENOR) ou 2 x MOTORES MAIOR
- 3 SENSORES DE LINHA QRE1113
- 5 SENSORES DE DISTANCIA (5 x JS40F) 
- MICROSTART
- CHAVE SELETORA de 3 pinos
- ARDUINO
*/
#include "constants.h"

int sensores_js[] = {JS_SENSOR_0, JS_SENSOR_1, JS_SENSOR_2, JS_SENSOR_3, JS_SENSOR_4};
int sensores_js_size = sizeof(sensores_js)/sizeof(sensores_js[0]);

void startJs(){
    for(int i = 0; i < sensores_js_size; i++){
    pinMode(sensores_js[i], INPUT);
  }
}

void setup() {
  // put your setup code here, to run once:
  startJs();

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void microStartTest(){
// MICROSTART

}

void driverTest(){
// 2 x DRIVER (PONTE H) DRV8833
}

void qreSensorTest(){
// 3 SENSORES DE LINHA QRE1113
// jeremias


}

void dipSwitchTest(){
// CHAVE SELETORA de 3 pinos

}

void jsSensorTest(){
// 5 SENSORES DE DISTANCIA (5 x JS40F)

  if( (millis() - initialTime < TEMPO_DE_EXEC_QRE + TEMPO_DE_EXEC_JS) && (millis() - initialTime > TEMPO_DE_EXEC_QRE)) {
    for(int i = 0; i < sensores_js_size; i++){
    int value = digitalRead(sensores_js[i]);
    Serial.print("Sensor "+ String(i) +"Output: "+ String(value));
  }
  Serial.println("");
  
  delay(500);
  }  
}