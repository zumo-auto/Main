#include "IMU.h"
#include "XBeeCommunicator.h"

XBeeCommunicator xbeeCommunicator(Serial1);
IMU imu(xbeeCommunicator);

void setup() {
  xbeeCommunicator.begin(9600);
  imu.init();
}

void loop() {
  imu.sendIMUReport();
}

