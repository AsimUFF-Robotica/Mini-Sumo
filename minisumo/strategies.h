#ifndef Strategies_h
#define Strategies_h

void passiveManeuver();
void whiteLineRetreat();
void stationarySearch();
void fastWoodpecker();
void slowWoodpecker();
void tornado();
void zigzag();
void direct();
void randomSearch();
void reverseAndSpinWhenInEdge(void (*strategyFunc)());
void runnigStrategy(unsigned char strategy);

#endif