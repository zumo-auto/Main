#include "Motors.h"

Motors::Motors() : leftSpeed(0), rightSpeed(0), maxSpeed(320) {}

void Motors::setSpeeds(int16_t leftSpeed, int16_t rightSpeed) {
    motors.setSpeeds(leftSpeed, rightSpeed);
    this->leftSpeed = leftSpeed;
    this->rightSpeed = rightSpeed;
}

void Motors::updateSpeedsBasedOnColor(const String& color) {
    if (color == "Groen") {
        maxSpeed = 160;
    } else if (color == "Zwart") {
        maxSpeed = 320;
    } else if (color == "GrijsLinks") {
        leftSpeed = 320;
        rightSpeed = -320;
        setSpeeds(leftSpeed, rightSpeed);
    } else if (color == "GrijsRechts") {
        leftSpeed = -320;
        rightSpeed = 320;
        setSpeeds(leftSpeed, rightSpeed);
    } else if (color == "GrijsRechts" && color == "GrijsLinks") {
        leftSpeed = 0;
        rightSpeed = 0;
        setSpeeds(leftSpeed, rightSpeed);
    }
}

Zumo32U4Motors& Motors::getMotors() {
    return motors;
}

int16_t Motors::getLeftSpeed() const {
    return leftSpeed;
}

int16_t Motors::getRightSpeed() const {
    return rightSpeed;
}

