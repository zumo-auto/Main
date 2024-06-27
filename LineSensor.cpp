#include "Line_sensor.h"


Line_sensor::ColorSensor() {}

void Line_sensor::begin() {
  lineSensors.initThreeSensors();
}

void Line_sensor::detectColor() {
  lineSensors.read(sensorValues);

  // Print sensor values
  sensor11 = (sensorValues[0]);
  sensor22 = (sensorValues[1]);
  sensor33 = (sensorValues[2]);

}

  uint16_t Line_sensor::sensor1(){
  return sensor11/2;
  }
  uint16_t Line_sensor::sensor2(){
  return sensor22/2;
  }
  uint16_t Line_sensor::sensor3(){
  return sensor33/2;
  }
