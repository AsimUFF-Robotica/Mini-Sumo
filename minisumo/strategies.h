#ifndef Strategies_h
#define Strategies_h

void whiteLineRetreat();
void woodpecker();
void tornado();
void zigzag();
void direct();
void randomSearch();
void reverseAndSpinWhenInEdge(void (*strategyFunc)());
void runnigStrategy(unsigned char strategy);

#endif