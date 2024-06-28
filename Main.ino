#include "Arduino.h"
#include "IMU.h"
#include "XBeeCommunicator.h"
#include "WipWap.h"
#include "BatteryController.h"
#include "blok.h"
#include "MyZumo32U4Proximity.h"
#include "Line_sensor.h"
#include "ColorLine.h"
#include "Motors.h"
#include "LineVolger.h"


XBeeCommunicator xbeeCommunicator(Serial1);
XBeeCommunicator xbeeComm(Serial1);
BatteryController batteryController;
IMU imu(xbeeCommunicator);
WipWap WipWap;
Blok blok;
Line_sensor liner;
LineVolger lineFollower;
Motors mot;

char Test;
int waarde;
int hoor1 = 0;
int hoor2 = 0;
int hoor3 = 0;


void setup() {
  xbeeCommunicator.begin(4800);
  Serial.begin(4800);
  imu.init();
  batteryController.setXBeeCommunicator(&xbeeCommunicator);
  WipWap.setup();
  blok.init();
  lineFollower.setup();
}

enum State {
  STATE_NONE,
  STATE_IMU,
  STATE_WIPWAP,
  STATE_BLOK,
  STATE_VOLGEN,
  STATE_VOLGENCALI,
  STATE_KLEURENCHECK
};

State currentState = STATE_NONE;

void loop() {
  if (xbeeComm.available()) {
    Test = xbeeComm.read();
    switch (Test) {
      case '1':
        xbeeComm.println("test");
        break;
      case '2':
    currentState = STATE_IMU;
        break;
      case '3':
    currentState = STATE_WIPWAP;
       break;
      case '4':
    currentState = STATE_BLOK;
        break;
      case '5':
    currentState = STATE_VOLGEN;
      break;
      case '0':
    currentState = STATE_VOLGENCALI;
      break;
      case '9':
      currentState = STATE_KLEURENCHECK;
      break;
    }
  }
  
  
  
  if (currentState == STATE_IMU) {
    imu.sendIMUReport();
    batteryController.checkBattery();
  } 
  else if (currentState == STATE_WIPWAP) {
    WipWap.loop();
  }
  else if (currentState == STATE_BLOK) {
    blok.loop();
  }
  else if (currentState == STATE_VOLGEN){
    lineFollower.loop();
    
  }
  else if (currentState == STATE_VOLGENCALI){
   lineFollower.calibrateSensors();
  }
  else if (currentState == STATE_KLEURENCHECK){
    liner.detectColor();
  hoor1 = liner.sensor1();
  hoor2 = liner.sensor2();
  hoor3 = liner.sensor3();

  ColorLine color(hoor1, hoor2, hoor3);
  color.Color();

  Serial1.println(color.kleure1());
  Serial1.println(color.kleure2());
  Serial1.println(color.kleure3());
  Serial1.println(hoor1);
  Serial1.println(hoor2);
  Serial1.println(hoor3);
  color.Color();
  mot.updateSpeedsBasedOnColor(color.kleure2());
  delay(300);
  }
  }
  
