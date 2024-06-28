#ifndef WipWap_h
#define WipWap_h

#include <Wire.h>
#include <Arduino.h>
#include <Zumo32U4IMU.h>
#include <Zumo32U4Motors.h>

class WipWap {
public:
    WipWap();
    void setup();
    void loop();

private:
    const int16_t motorSpeed = 80;
    const int16_t deadzone = 67;
    const unsigned long hysteresisTime = 40;

    Zumo32U4IMU imu;
    Zumo32U4Motors motors;

    unsigned long inDeadzoneStartTime;
    unsigned long lastPrintTime;
};

#endif
