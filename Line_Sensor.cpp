#include "Line_sensor.h"

Line_sensor::Line_sensor() { // Constructor definition
    lineSensors.initFiveSensors();
}

void Line_sensor::detectColor() {
    lineSensors.read(sensorValues);

    sensor11 = sensorValues[0];
    sensor22 = sensorValues[1];
    sensor33 = sensorValues[2];
    sensor44 = sensorValues[3];
    sensor55 = sensorValues[4];
}

uint16_t Line_sensor::sensor1() {
    return sensor11;
}

uint16_t Line_sensor::sensor2() {
    return sensor22;
}

uint16_t Line_sensor::sensor3() {
    return sensor33;
}

uint16_t Line_sensor::sensor4() {
return sensor44;
}

uint16_t Line_sensor::sensor5() {
   return sensor55;
}

void Line_sensor::calibrateSensors(Zumo32U4Motors& motors) {
    delay(1000);
    for (uint16_t i = 0; i < 120; i++) {
        if (i > 30 && i <= 90) {
            motors.setSpeeds(-200, 200);
        } else {
            motors.setSpeeds(200, -200);
        }
        lineSensors.calibrate();
    }
    motors.setSpeeds(0, 0);
}

// Implementation of the new method
int16_t Line_sensor::readLineSensor() {
    // Assuming lineSensorValues is a member variable of Line_sensor class
    return lineSensors.readLine(sensorValues);
}
