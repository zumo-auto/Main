#ifndef LINE_SENSOR_H
#define LINE_SENSOR_H

#include <Zumo32U4.h>

class Line_sensor {

public:
  ColorSensor();
  void begin();
  void detectColor();
  uint16_t sensor1();
  uint16_t sensor2();
  uint16_t sensor3();

private:
  Zumo32U4LineSensors lineSensors;
  uint16_t sensorValues[3];
  uint16_t sensor11;
  uint16_t sensor22;
  uint16_t sensor33;

};

#endif
