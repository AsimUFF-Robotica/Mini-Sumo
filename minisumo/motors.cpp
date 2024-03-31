#include <Arduino.h>
#include "motors.h"
#include "constants.h"

void startMotors(){
  pinMode(RIGHT_WHEEL_IN_1, OUTPUT);
  pinMode(RIGHT_WHEEL_IN_2, OUTPUT);
  pinMode(LEFT_WHEEL_IN_1, OUTPUT);
  pinMode(LEFT_WHEEL_IN_2, OUTPUT);
}

/* -------move-------
Controla a ponte H para movimentar o robô e ajusta o ângulo de viragem.
- `pwm` deve ser um valor entre 0 e 255 e define a velocidade máxima do motor
- `angular` determina a direção e intensidade da virada (entre -1 e 1):
  - `0`: Movimento reto, sem virar.
  - `> 0`: Vira à direita. A intensidade da virada aumenta quanto mais próximo de 1.
    - Entre 0 e 0.5: Roda esquerda sempre acelera o máximo. Para angular = 0, a roda direita acelera o máximo. Conforme angular aumenta, a roda direita diminui a força, até em 0.5 onde a roda direita para de acelerar.
    - Acima de 0.5: Roda esquerda sempre acelera o máximo. A roda da direita começa a acelerar no sentido contrário, aumentando a eficácia da virada à direita. Quanto mais próximo de 1, maior a velocidade inversa da roda direita, facilitando uma virada mais rápida e acentuada.
  - `< 0`: Vira à esquerda. A intensidade da virada aumenta quanto mais próximo de -1.
    - Entre -0.5 e 0: Roda direita sempre acelera o máximo. Conforme angular diminui de 0 para -0.5, a roda esquerda diminui a força, até em -0.5 onde a roda esquerda para de acelerar, permitindo uma virada suave à esquerda.
    - Abaixo de -0.5: Roda direita sempre acelera o máximo. A roda esquerda começa a acelerar no sentido contrário, aumentando a eficácia da virada à esquerda. Quanto mais próximo de -1, maior a velocidade inversa da roda esquerda, facilitando uma virada mais rápida e acentuada.
*/
void move(float angular, int pwm, bool reverse){

  // Calcula a velocidade linear com base na magnitude do angular; quanto maior o angular, menor a componente linear.
  float linear = (1 - abs(angular));

  // Se o movimento deve ser reverso, inverte o sinal da velocidade linear.
  if(reverse)
    linear = -linear;

  // Calcula a velocidade da roda esquerda combinando as componentes linear e angular.
  float leftSpeed = (linear + angular);

  // Calcula a velocidade da roda direita subtraindo a componente angular da linear.
  float rightSpeed  = (linear - angular);

  int leftPWM = constrain(map(abs(leftSpeed), 0, 1, 0, pwm), 0, maxPWM);
  int rightPWM = constrain(map(abs(rightSpeed), 0, 1, 0, pwm), 0, maxPWM);

  // TODO: Verificar, com os testes, se o sentido de rotação está correto.
  // Configura a direção e a velocidade da roda esquerda.
  if (leftSpeed < 0) { // se roda da esquerda gira pra trás
    analogWrite(leftWheelIN1, leftPWM);
    digitalWrite(leftWheelIN2, LOW);
  } else {
    digitalWrite(leftWheelIN1, LOW);
    analogWrite(leftWheelIN2, leftPWM);
  }

  // Configura a direção e a velocidade da roda direita.
  if (rightSpeed < 0) { // se roda da direita gira pra trás
    analogWrite(rightWheelIN1, rightPWM);
    digitalWrite(rightWheelIN2, LOW);
  } else {
    digitalWrite(rightWheelIN1, LOW);
    analogWrite(rightWheelIN2, rightPWM);
  }
}

/* -------stop-------
*/
void stop(int stopType){
  switch (stopType) {
    case 0: // Parar de acelerar as 2 rodas (Coast)
      digitalWrite(rightWheelIN1, LOW);
      digitalWrite(rightWheelIN2, LOW);
      digitalWrite(leftWheelIN1, LOW);
      digitalWrite(leftWheelIN2, LOW);
      break;
    case 1: // Freiar as 2 rodas (Brake)
      digitalWrite(leftWheelIN1, HIGH);
      digitalWrite(leftWheelIN2, HIGH);
      digitalWrite(rightWheelIN3, HIGH);
      digitalWrite(rightWheelIN4, HIGH);
      break;
    case 2: // Parar de acelerar somente roda direita (Coast)
      digitalWrite(rightWheelIN1, LOW);
      digitalWrite(rightWheelIN2, LOW);
      break;
    case 3: // Parar de acelerar somente roda esquerda (Coast)
      digitalWrite(leftWheelIN1, LOW);
      digitalWrite(leftWheelIN2, LOW);
      break;
    case 4: // Freiar somente a roda esquerda (Brake)
      digitalWrite(leftWheelIN1, HIGH);
      digitalWrite(leftWheelIN2, HIGH);
      break;
    case 5: // Freiar somente a roda direita (Brake)
      digitalWrite(rightWheelIN3, HIGH);
      digitalWrite(rightWheelIN4, HIGH);
      break;
  }
}

/* -------spin-------
*/
void spin(bool toRightDirection, int pwm){
  if (toRightDirection) {
    analogWrite(leftWheelIN1, pwm);
    digitalWrite(leftWheelIN2, LOW);
    digitalWrite(rightWheelIN1, LOW);
    analogWrite(rightWheelIN2, pwm);
  } else {
    digitalWrite(leftWheelIN1, LOW);
    analogWrite(leftWheelIN2, pwm);
    digitalWrite(rightWheelIN1, pwm);
    analogWrite(rightWheelIN2, LOW);
  }
};

/* -------forward-------
*/
void forward(int pwm){
  move(0, pwm);
};