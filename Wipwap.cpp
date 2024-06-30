#include "WipWap.h"

WipWap::WipWap() {
    inDeadzoneStartTime = 0;
    lastPrintTime = 0;
}

void WipWap::setup() {
    Wire.begin();
    imu.init();
    imu.enableDefault();
    imu.configureForFaceUphill();
}

void WipWap::loop() {
    unsigned long currentMillis = millis();
    int16_t x = 0;

    if (currentMillis - lastPrintTime >= 200) {
        imu.readAcc();
        x = imu.a.x / 22;
        Serial.println(x);
        lastPrintTime = currentMillis;
    }

    if (abs(x) <= deadzone) {
        if (inDeadzoneStartTime == 0) {
            inDeadzoneStartTime = millis();
        }
        if (millis() - inDeadzoneStartTime >= hysteresisTime) {
            motors.setSpeeds(0, 0);
        }
    } else {
        if (x > deadzone) {
            motors.setSpeeds(motorSpeed, motorSpeed);
        } else if (x < -deadzone) {
            motors.setSpeeds(-motorSpeed, -motorSpeed);
            delay(50);
        }
        inDeadzoneStartTime = 0;
    }
}
