#ifndef Sensors_h
#define Sensors_h

void getDIPSwitchValues(uint8_t *strategy);
void startAllSensors();
unsigned char isRobotInEdge(int leftLineSensor, int rightLineSensor, int backLineSensor);
void startLED();
void ledOn();
void ledOff();
void waitForStartSignal();


struct SensorValues {
  uint8_t microStartPin;
  uint8_t jsFrontSensor;
  uint8_t jsFrontLeftSensor;
  uint8_t jsFrontRightSensor;
  uint8_t jsSideLeftSensor;
  uint8_t jsSideRightSensor;
  int rightLineSensor;
  int leftLineSensor;
  int backLineSensor;
};

// Global
extern SensorValues loopSensorsValues;

void getLoopSensorsValues(SensorValues& values);

#endif