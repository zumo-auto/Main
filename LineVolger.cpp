#include "LineVolger.h"

void LineVolger::setup() {
    lastError = 0;
}

void LineVolger::calibrateSensors() {
    lineSensor.calibrateSensors(motors.getMotors());
}

void LineVolger::loop() {
    followLine();
}

void LineVolger::followLine() {
    // Assuming readLineSensor() now exists and reads the line sensor
    int16_t position = lineSensor.readLineSensor();

    // Calculate the error based on the position
    int16_t error = position - 2000;

    computeAndSetSpeeds(error, lastError);

    lastError = error;
}

void LineVolger::computeAndSetSpeeds(int16_t error, int16_t lastError) {
    int16_t speedDifference = error / 0.75 + 20 * (error - lastError);

    // Adjust motor speeds based on the computed error
    int16_t leftSpeed = motors.maxSpeed + speedDifference;
    int16_t rightSpeed = motors.maxSpeed - speedDifference;

    // Constrain speeds to the allowed range
    leftSpeed = constrain(leftSpeed, 0, motors.maxSpeed);
    rightSpeed = constrain(rightSpeed, 0, motors.maxSpeed);

    // Set the constrained speeds to the motors
    motors.setSpeeds(leftSpeed, rightSpeed);
}
