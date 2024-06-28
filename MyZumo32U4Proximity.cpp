#include "MyZumo32U4Proximity.h"
#include <Arduino.h>

MyZumo32U4Proximity::MyZumo32U4Proximity() {
    // Constructor
}

void MyZumo32U4Proximity::begin() {
    proxSensors.initThreeSensors(); // Initialize proximity sensors
}

void MyZumo32U4Proximity::readSensors() {
    proxSensors.read(); // Read proximity sensors
    frontLeftSensorValue = proxSensors.countsFrontWithLeftLeds();
    frontRightSensorValue = proxSensors.countsFrontWithRightLeds();

    Serial1.print("Front Left: ");
    Serial1.print(frontLeftSensorValue);
    Serial1.print(" ");
    Serial1.print("Front Right: ");
    Serial1.println(frontRightSensorValue);
    delay(200);
}


int MyZumo32U4Proximity::getFrontLeftSensorValue() {
    return frontLeftSensorValue;
}

int MyZumo32U4Proximity::getFrontRightSensorValue() {
    return frontRightSensorValue;
}
