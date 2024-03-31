/*
Este código define diferentes estratégias de combate para nosso robô, categorizadas em dois grandes grupos: Defensivas e Ofensivas, e subdivididas em Full, Start, Search. Já para a defesa de borda (linha branca) temos as estratégias do tipo: Safety.

- Estratégias Defensivas (Defensive): Passivas ou de evasão. 
- Estratégias Ofensivas (Offensive): Visam a agressão direta ao adversário, buscando dominar a arena e aplicar danos.

- Start: Estratégias iniciais (de abertura) que definem o primeiro movimento. Como por exemplo estabelecer uma posição vantajosa desde o início.
- Search: Táticas de busca para localizar o oponente na arena, utilizando movimentos específicos para maximizar a chance de encontro e ataque.
- Full: Representa uma estratégia completa, englobando elementos de 'Start' e 'Search' para uma abordagem integrada.

- Safety: Projetadas para responder a situações de risco iminente, como a proximidade com a linha branca da arena, ativando manobras de segurança para evitar a desqualificação.

Cada tipo de estratégia pode ser usado isoladamente ou em combinação com outros, dependendo das condições da luta e da estratégia do oponente. 
Por exemplo, uma estratégia 'Start' pode iniciar o combate, seguida pela ativação de uma estratégia 'Search' para continuar a pressão sobre o adversário. Juntamente da 'Safe' para
ser a resposta a situações de perigo imediato, como o reconhecimento da linha branca, garantindo a segurança do robô.
*/

#include <Arduino.h>
#include "motors.h"
#include "constants.h"
#include "sensors.h"
#include "strategies.h"

/* DEFENSIVE_FULL_STRATEGY
Inicialmente da ré em maxima velocidade até a linha branca e para assim que avista-la.
Virado para o centro da pista, busca o inimigo. 
Caso o encontre, não acelera, somente vira em direção a ele.
Assim que o oponente estiver proximo/colado ao robo, acelera o maximo.
Caso perca o inimigo de vista, da ré até a linha branca novamente.

Essa estratégia permite que o robô se defenda de ataques imprevisíveis, usando a borda da arena para
limitar as direções de onde o ataque pode vir. 
Ela também aumenta as chances de que o oponente cometa um erro e saia da arena por conta própria.
*/
void whiteLineRetreat(){
// TODO
/*  Pseudocódigo:

*/

}

/* OFFENSIVE_SEARCH_STRATEGY
Busca o inimigo em velocidade maxima.
Mas, assim que o encontra, freia o robo.
Segue no movimento "woodpecker" onde o robo é acelerado por pouco tempo e depois parado, continuamente e super devagar.
A vantagem é que com a baixa velocidade, a lâmina não se eleva com a alta velocidade.
*/
void fastWoodpecker(){
// TODO
/*  Pseudocódigo:
    1) Ativa aceleração para frente em velocidade maxima. Use a função move()
    2) Busca o inimigo olhando os 3 sensores de distancia:
      sensor frontal: loopSensorsValues.jsFrontSensor
      sensor lateral esquerdo: loopSensorsValues.leftVl53l0xSensorValue
      sensor lateral direito: loopSensorsValues.rightVl53l0xSensorValue
    3) assim que o encontra o oponente, freia o robo.
    4) Segue em direção ao inimigo no movimento "woodpecker". Onde o robo é acelerado por pouco tempo e depois parado, continuamente e super devagar.

*/

}

/* OFFENSIVE_SEARCH_STRATEGY
Busca o inimigo enquanto segue no movimento "woodpecker" onde o robo é acelerado por pouco tempo e depois parado, continuamente e super devagar.
A vantagem é que com a baixa velocidade, a lâmina não se eleva com a alta velocidade.
*/
void slowWoodpecker(){
// TODO
/*  Pseudocódigo:
    1) Busca o inimigo olhando os 3 sensores de distancia:
      sensor frontal: loopSensorsValues.jsFrontSensor
      sensor lateral esquerdo: loopSensorsValues.leftVl53l0xSensorValue
      sensor lateral direito: loopSensorsValues.rightVl53l0xSensorValue
    2) Se o sensor frontal detectar o inimigo -> Segue em direção reta no movimento "woodpecker". Onde o robo é acelerado por pouco tempo e depois parado, continuamente e super devagar.
    3) Se o sensor lateral esquerdo detectar o inimigo -> girar pro lado esquerdo até o sensor frontal detectar o inimigo. 
    4) Se o sensor lateral direito detectar o inimigo -> girar pro lado direito até o sensor frontal detectar o inimigo. 

*/

}

/* OFFENSIVE_SEARCH_STRATEGY
Gira o robo em torno do proprio eixo, buscando o oponente. 
Assim que o encontra, acelera com tudo em direção a ele. 
Caso perca de vista, volta a girar.
*/
void tornado(){
// TODO
/*  Pseudocódigo:
    1) ativa o giro (spin) do robo com: 
    2) busca o inimigo olhando os 3 sensores de distancia:
      sensor frontal: loopSensorsValues.jsFrontSensor
      sensor lateral esquerdo: loopSensorsValues.leftVl53l0xSensorValue
      sensor lateral direito: loopSensorsValues.rightVl53l0xSensorValue
    3) Se o sensor frontal detectar o inimigo -> andar reto
    4) Se o sensor lateral esquerdo detectar o inimigo -> girar pro lado esquerdo até o sensor frontal detectar o inimigo. 
    5) Se o sensor lateral direito detectar o inimigo -> girar pro lado direito até o sensor frontal detectar o inimigo. 
*/

}

/* OFFENSIVE_START_STRATEGY
https://www.youtube.com/watch?v=GwlxHs8RGWw
Primeiro passo para fazer o código dessa tática é entender o quanto o robô consegue
ir para frente com 100% pwm por um tempo (50ms por exemplo).
Depois entender quanto tempo demora para fazer uma girada rápida.
*/
void zigzag(){
// TODO
/* Pseudocódigo:

*/

}

/* OFFENSIVE_START_STRATEGY
Segue reto na velocidade maxima por um tempo.
*/
void direct(){
  move(0, MAX_PWM);
  delay(DIRECT_SPIN_DURATION_MS);
}

/* OFFENSIVE_SEARCH_STRATEGY
Robô vai até um lado da pista, gira e vai até o outro lado. E repete esse
movimento, indo de um lado pro outro. A inércia adquirida por estar
sempre em movimento pode ajudar a empurrar o oponente, mas pode
nos atrapalhar e derrubar o nosso próprio robô.
*/
void randomSearch(){
  move(0, MAX_PWM);
}

/* SAFETY_STRATEGY
Caso encontre a linha branca, da ré por um tempo, gira 180 graus e reinicia a estratégia.
*/
void reverseAndSpinWhenInEdge(void (*strategyFunc)()) {
  static bool isSpinning = false;
  static unsigned long spinStartTime = 0;
  static bool wasReversing = false;
  bool isSpinDirectionRight = false;

  if (isSpinning) {
    if (millis() - spinStartTime >= SPIN_180_DURATION_MS_WITH_MAXPW) {
      isSpinning = false;
    }
    return;
  }

  unsigned char edgeDetected = isRobotInEdge(loopSensorsValues.rightLineSensor, loopSensorsValues.leftLineSensor, loopSensorsValues.backLineSensor);
  if (edgeDetected == 0b100) { // Detectou somente sensor traseiro.
    strategyFunc();
  } 
  else if ((edgeDetected == 0b11) || (edgeDetected == 0b111)) { // Detectou sensor direito e esquerdo. Ou, sensor direito, esquerdo e traseiro.
    move(0, MAX_PWM, true);
    isSpinDirectionRight = true;
    wasReversing = true;
  }
  else if ((edgeDetected == 0b01) || (edgeDetected == 0b101)) { // Detectou somente sensor esquerdo. Ou, sensor esquerdo e traseiro.
    move(0, MAX_PWM, true);
    isSpinDirectionRight = true;
    wasReversing = true;
  }
  else if ((edgeDetected == 0b10) || (edgeDetected == 0b110)) { // Detectou somente sensor direito. Ou, sensor direito e traseiro.
    move(0, MAX_PWM, true);
    isSpinDirectionRight = false;
    wasReversing = true;
  } 
  else if (wasReversing){
    isSpinning = true;
    spinStartTime = millis();
    spin(isSpinDirectionRight, MAX_PWM);
    wasReversing = 0;
  }
  else {
    strategyFunc();
  }
}

/* É responsável por selecionar e executar uma estratégia de combate específica para o robô, baseando-se em uma chave seletora fornecida como argumento. 
Esta chave determina qual das estratégias pré-definidas será ativada, permitindo ao robô adaptar seu comportamento de acordo com as condições e estratégias do oponente encontradas na arena. 
As estratégias variam entre defensivas e ofensivas, incluindo manobras evasivas, ataques diretos e padrões de busca. 
*/
void runnigStrategy(unsigned char strategy){
switch(strategy) {
  case 0b1:
    whiteLineRetreat();
    break;
  case 0b10:
    zigzag();
    reverseAndSpinWhenInEdge(tornado);
    break;
  case 0b11:
    direct();
    reverseAndSpinWhenInEdge(randomSearch);
    break;
  case 0b100:
    direct();
    reverseAndSpinWhenInEdge(tornado);
    break;
  case 0b101:
    zigzag();
    reverseAndSpinWhenInEdge(randomSearch);
    break;
  case 0b110:
    reverseAndSpinWhenInEdge(randomSearch);
    break;
  case 0b111:
    reverseAndSpinWhenInEdge(tornado);
    break;
  case 0b1000:
    reverseAndSpinWhenInEdge(woodpecker);
    break;
  default:
    break;
}
}