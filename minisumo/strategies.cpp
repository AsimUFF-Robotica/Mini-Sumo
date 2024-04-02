/*
Este código define diferentes estratégias de combate para nosso robô, categorizadas em dois grandes grupos: Defensivas e Ofensivas, e subdivididas em Start, Mid, Full. Já para a defesa de borda (linha branca) temos as estratégias do tipo: Safety.

- Estratégias Defensivas (Defensive): Passivas ou de evasão. 
- Estratégias Ofensivas (Offensive): Visam a agressão direta ao adversário.

- Start: Estratégias iniciais (de abertura) que definem o primeiro movimento. Como por exemplo ir para uma posição vantajosa no início da partida. 
- Mid: Táticas a serem usadas logo apos a abertura, para localizar o oponente na arena, utilizando movimentos específicos para maximizar a chance de encontro e ataque/defesa.
- Full: Representa uma estratégia completa, englobando elementos de 'Start' e 'Mid' para uma abordagem integrada.

- Safety: Projetadas para responder a situações de risco iminente, como a proximidade com a linha branca da arena, ativando manobras de segurança para evitar a desqualificação. E

Obs: Uma função do tipo Start irá rodar somente uma vez, diferente das Mid ou Full que ficam infinitamente em loop.

Obs2: Cada tipo de estratégia pode ser usado isoladamente ou em combinação com outros, dependendo das condições da luta e da estratégia do oponente. 
Por exemplo, uma estratégia 'Start' pode iniciar o combate, seguida pela ativação de uma estratégia 'Mid' para continuar a busca pelo oponente. Enquanto a 'Safe' está encapsulando as demais para
ser a resposta a situações de perigo imediato, como o reconhecimento da linha branca, garantindo a segurança do robô.
*/

#include <Arduino.h>
#include "motors.h"
#include "constants.h"
#include "sensors.h"
#include "strategies.h"

/* DEFENSIVE_MID_STRATEGY
Essa estratégia é aplicada em um combate frontal com o oponente. 
Envolve a manipulação precisa das rodas do robô: uma roda é travada enquanto a outra fica livre. A roda, inicialmente livre, acelera para trás assim que oponente estiver muito próximo. 
Este método faz o robô girar no próprio eixo, permitindo que o oponente passe por ele. 
Assim que o adversário estiver em uma posição vulnerável, virado de costas para o robô, este acelera em direção ao inimigo para empurrá-lo. 
Este movimento estratégico aproveita a posição do adversário para tentar empurrá-lo para fora da arena. Mas é possivel que o inimigo não fique de costas, mas sim gire junto com a gente, nesse caso pode ser usado em conjunto com o whiteLineRetreat().
*/
void passiveManeuver() {
// TODO
/*  Pseudocódigo:
1) Travar uma roda e deixar a outra livre
2**) Caso inimigo esteja super perto, acelerar uma das rodas para trás. Utilizando o giro no próprio eixo para fazer o oponente passar por nós.
3) Assim que o oponente tiver passado a gente e estiver virado de costas, acelerar em sua direção e empurrá-lo.
**  Não sabemos ainda como faremos essa deteção, porém use a função imaginaria isEnemyVeryClose()
*/
}

/* DEFENSIVE_MID_STRATEGY
Busca o inimigo parado so olhando sensores.
Caso o encontre, vira o robo em direção ao inimigo, mas não acelera.
Somente quando o oponente estiver proximo/colado ao robo**, acelera o maximo seguindo em direção ao inimigo.
** Não sabemos ainda como faremos essa deteção, porém use a função imaginaria isEnemyVeryClose()
*/
void stationarySearch() {
// TODO

}

/* DEFENSIVE_START_STRATEGY
Da ré em maxima velocidade até a linha branca e para assim que avista-la. Anda um pouquinho pra frente pra nao ficar colado na linha branca, usando millis() pra andar por poucos milissegundos para frente.
*/
void whiteLineRetreat() {
// TODO

}

/* OFFENSIVE_MID_STRATEGY
Busca o inimigo em velocidade maxima.
Mas, assim que o encontra, freia o robo.
Segue no movimento "woodpecker" onde o robo é acelerado por pouco tempo e depois parado, continuamente e super devagar.
A vantagem é que com a baixa velocidade, a lâmina não se eleva com a alta velocidade.
*/
void fastWoodpecker() {
// TODO
/*  Pseudocódigo:
1) Busca o inimigo olhando os 3 sensores de distancia:
  sensor frontal: loopSensorsValues.jsFrontSensor
  sensor lateral esquerdo: loopSensorsValues.leftVl53l0xSensorValue
  sensor lateral direito: loopSensorsValues.rightVl53l0xSensorValue
2) Caso encontre o oponente, freia o robo (com stop(1)).
  Se foi o sensor frontal que detectou o inimigo -> Segue em direção reta no movimento "woodpecker". Onde o robo é acelerado por pouco tempo e depois parado, continuamente e super devagar.
  Se foi o sensor lateral esquerdo que detectou o inimigo -> girar pro lado esquerdo até o sensor frontal detectar o inimigo. E segue em direção reta no movimento "woodpecker".
  Se foi o sensor lateral direito que detectou o inimigo -> girar pro lado direito até o sensor frontal detectar o inimigo. E segue em direção reta no movimento "woodpecker".
3) Caso não veja o inimigo em nenhum sensor, ativa aceleração para frente em velocidade maxima para busca-lo. Use a função move()
*/
}

/* OFFENSIVE_MID_STRATEGY
Busca o inimigo enquanto segue no movimento "woodpecker" onde o robo é acelerado por pouco tempo e depois parado, continuamente e super devagar.
A vantagem é que com a baixa velocidade, a lâmina não se eleva com a alta velocidade.
*/
void slowWoodpecker() {
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

/* OFFENSIVE_MID_STRATEGY
Gira o robo em torno do proprio eixo, buscando o oponente. 
Assim que o encontra, acelera com tudo em direção a ele. 
Caso perca de vista, volta a girar.
*/
void tornado() {
// TODO
/*  Pseudocódigo:
1) busca o inimigo olhando os 3 sensores de distancia:
  sensor frontal: loopSensorsValues.jsFrontSensor
  sensor lateral esquerdo: loopSensorsValues.leftVl53l0xSensorValue
  sensor lateral direito: loopSensorsValues.rightVl53l0xSensorValue
2) ativa o giro do robo com: função spin()
3) Se o sensor frontal detectar o inimigo -> andar reto. Use a função move()
4) Se o sensor lateral esquerdo detectar o inimigo -> girar pro lado esquerdo até o sensor frontal detectar o inimigo. 
5) Se o sensor lateral direito detectar o inimigo -> girar pro lado direito até o sensor frontal detectar o inimigo.
6) Se perder o oponente de vista, volta a girar.
*/
}

/* OFFENSIVE_START_STRATEGY
https://www.youtube.com/watch?v=GwlxHs8RGWw
Primeiro passo para fazer o código dessa tática é entender o quanto o robô consegue
ir para frente com 100% pwm por um tempo (50ms por exemplo).
Depois entender quanto tempo demora para fazer uma girada rápida.
*/
void zigzag() {
// TODO
/* Pseudocódigo:
1) Usando millis() e move("coloque_aqui_algum_valor_entre_0_e_0.5", MAX_PWM), anda em curva para direita por um tempo (pode por 1 segundo de tempo, depois com testes saberemos quantos segundos serão necessarios);
2) Gira para esquerda até o sensor frontal "loopSensorsValues.jsFrontSensor" valer 1 (nosso robo fica de frente para o inimigo).

*/
}

/* OFFENSIVE_MID_STRATEGY
Segue reto na velocidade maxima, enquanto verifica sensores. Caso ache o inimigo, se direciona a ele e avança.
*/
void straightLockSearch() {
  static bool isSpinningLeft = false;
  static bool isSpinningRight = false;

  if (isSpinningRight){
    if (loopSensorsValues.jsFrontSensor){
      isSpinningRight = false;
    }
  }
  else if (isSpinningLeft){
    if (loopSensorsValues.jsFrontSensor){
      isSpinningLeft = false;
    }
  }
  else{
    if (loopSensorsValues.leftVl53l0xSensorValue < OPPONENT_FOUND_DISTANCE_VL53L0X){
      isSpinningLeft = true;
      spin(false, MAX_PWM);
    }
    else if (loopSensorsValues.rightVl53l0xSensorValue < OPPONENT_FOUND_DISTANCE_VL53L0X){
      isSpinningRight = true;
      spin(true, MAX_PWM);
    }
    else{
      move(0, MAX_PWM);
    }
  }
}

/* OFFENSIVE_MID_STRATEGY
Anda fazendo curva na velocidade maxima, enquanto verifica sensores. Caso ache o inimigo, se direciona a ele e avança.
*/
void curvedLockSearch() {
  static bool isSpinningLeft = false;
  static bool isSpinningRight = false;

  if (isSpinningRight){
    if (loopSensorsValues.jsFrontSensor){
      isSpinningRight = false;
    }
  }
  else if (isSpinningLeft){
    if (loopSensorsValues.jsFrontSensor){
      isSpinningLeft = false;
    }
  }
  else if (loopSensorsValues.jsFrontSensor){
    move(0, MAX_PWM);
  }
  else{
    if (loopSensorsValues.leftVl53l0xSensorValue < OPPONENT_FOUND_DISTANCE_VL53L0X){
      isSpinningLeft = true;
      spin(false, MAX_PWM);
    }
    else if (loopSensorsValues.rightVl53l0xSensorValue < OPPONENT_FOUND_DISTANCE_VL53L0X){
      isSpinningRight = true;
      spin(true, MAX_PWM);
    }
    else{
      move(0.25, MAX_PWM);
    }
  }
}

/* OFFENSIVE_MID_STRATEGY
Robô vai até um lado da pista, gira e vai até o outro lado. E repete esse
movimento, indo de um lado pro outro. A inércia adquirida por estar
sempre em movimento pode ajudar a empurrar o oponente, mas pode
nos atrapalhar e derrubar o nosso próprio robô.
*/
void randomSearch() {
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
  if (edgeDetected == 0b100) {  // Detectou somente sensor traseiro.
    move(0, MAX_PWM);
  } else if ((edgeDetected == 0b11) || (edgeDetected == 0b111)) {  // Detectou sensor direito e esquerdo. Ou, sensor direito, esquerdo e traseiro.
    move(0, MAX_PWM, true);
    isSpinDirectionRight = true;
    wasReversing = true;
  } else if ((edgeDetected == 0b01) || (edgeDetected == 0b101)) {  // Detectou somente sensor esquerdo. Ou, sensor esquerdo e traseiro.
    move(0, MAX_PWM, true);
    isSpinDirectionRight = true;
    wasReversing = true;
  } else if ((edgeDetected == 0b10) || (edgeDetected == 0b110)) {  // Detectou somente sensor direito. Ou, sensor direito e traseiro.
    move(0, MAX_PWM, true);
    isSpinDirectionRight = false;
    wasReversing = true;
  } else if (wasReversing) {
    isSpinning = true;
    spinStartTime = millis();
    spin(isSpinDirectionRight, MAX_PWM);
    wasReversing = false;
  } else {
    strategyFunc();
  }
}

/* É responsável por selecionar e executar uma estratégia de combate específica para o robô, baseando-se em uma chave seletora fornecida como argumento. 
Esta chave determina qual das estratégias pré-definidas será ativada, permitindo ao robô adaptar seu comportamento de acordo com as condições e estratégias do oponente encontradas na arena. 
As estratégias variam entre defensivas e ofensivas, incluindo manobras evasivas, ataques diretos e padrões de busca. 

DEFENSIVE_START_STRATEGY:
whiteLineRetreat

OFFENSIVE_START_STRATEGY:
zigzag

DEFENSIVE_MID_STRATEGY:
passiveManeuver
stationarySearch

OFFENSIVE_MID_STRATEGY:
fastWoodpecker
slowWoodpecker
tornado
straightLockSearch
curvedLockSearch
randomSearch

SAFETY_STRATEGY:
reverseAndSpinWhenInEdge
*/
void runnigStrategy(unsigned char strategy) {
  switch (strategy) {
    case 0b1:
      // TODO
      break;
    case 0b10:
      zigzag();
      reverseAndSpinWhenInEdge(tornado);
      break;
    case 0b11:
      reverseAndSpinWhenInEdge(straightLockSearch);
      break;
    case 0b100:
      reverseAndSpinWhenInEdge(curvedLockSearch);
      break;
    case 0b101:
      zigzag();
      reverseAndSpinWhenInEdge(curvedLockSearch);
      break;
    case 0b110:
      reverseAndSpinWhenInEdge(randomSearch);
      break;
    case 0b111:
      reverseAndSpinWhenInEdge(tornado);
      break;
    case 0b1000:
      reverseAndSpinWhenInEdge(fastWoodpecker);
      break;
    case 0b1001:
      reverseAndSpinWhenInEdge(slowWoodpecker);
      break;
    case 0b1010:
      whiteLineRetreat();
      reverseAndSpinWhenInEdge(stationarySearch);
      break;
    case 0b1011:
      zigzag();
      reverseAndSpinWhenInEdge(straightLockSearch);
      break;
    default:
      break;
  }
}