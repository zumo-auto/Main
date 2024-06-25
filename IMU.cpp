#include "IMU.h"

IMU::IMU(XBeeCommunicator& xbeeCom) : xbeeCom(xbeeCom) {}

void IMU::init() {
  Wire.begin();
  if (!imu.init()) {
    while(1) {
      xbeeCom.println("Failed to initialize IMU sensors.");
      delay(100);
    }
  }
  imu.enableDefault();
}

void IMU::read() {
  imu.read();
}

int IMU::getMagX() {
  return imu.m.x;
}

int IMU::getMagY() {
  return imu.m.y;
}

int IMU::getGyroX() {
  return ((float)(imu.a.x) / ( 32767/180 ));
}

int IMU::getGyroY() {
  return ((float)(imu.a.y) / (32767/180 ));
}

void IMU::sendIMUReport() {
  read();
  snprintf(report, sizeof(report), "Gyroscope: X:%d Y:%d", 
  getGyroX(), getGyroY());
  xbeeCom.println(report);
  delay(100);
}
