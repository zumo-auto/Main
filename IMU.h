#ifndef IMU_H
#define IMU_H

#include <Wire.h>
#include <Zumo32U4.h>
#include "XBeeCommunicator.h"

class IMU {
public:
  IMU(XBeeCommunicator& xbeeCom);
  void init();
  void read();
  int getMagX();
  int getMagY();
  int getGyroX();
  int getGyroY();
  void sendIMUReport();

private:
  Zumo32U4IMU imu;
  XBeeCommunicator& xbeeCom;
  char report[120];
};

#endif
