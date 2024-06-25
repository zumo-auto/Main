
#include "IMU.h"
#include "XBeeCommunicator.h"
#include "blok.h"

XBeeCommunicator xbeeCommunicator(Serial1);
IMU imu(xbeeCommunicator);
Blok blok;

void setup() {
  xbeeCommunicator.begin(9600);
  imu.init();
  blok.init();
}

void loop() {
  imu.sendIMUReport();
   blok.loop();
}
