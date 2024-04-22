#ifndef DRIVER_H
#define DRIVER_H

class Driver {
public:
    static void initDriver();
    static void forward();
    static void backward();
    static void spinToLeft();
    static void spinToRight();
    static void coast();
    static void brake();
};

#endif
