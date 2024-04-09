#ifndef Sensors_h
#define Sensors_h

unsigned char getDIPSwitchValues();
void startAllSensors();
void startVl53l0x();
unsigned char isRobotInEdge(int leftLineSensor, int rightLineSensor, int backLineSensor);

struct SensorValues {
  uint8_t microStartPin;
  uint8_t jsFrontSensor;
  uint16_t leftVl53l0xSensorValue;
  uint16_t rightVl53l0xSensorValue;
  int rightLineSensor;
  int leftLineSensor;
  int backLineSensor;
};

// Global
extern SensorValues loopSensorsValues;

SensorValues getLoopSensorsValues();
#endif