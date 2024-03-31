#ifndef Motors_h
#define Motors_h

void move(float angular, int maxPwm, bool reverse = false);
void stop(int stopType);
void spin(bool toRightDirection, int pwm)
void forward();

#endif