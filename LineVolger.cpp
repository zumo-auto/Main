#include "LineVolger.h"

LineVolger::LineVolger(Motors& motors) : rij(motors), lastError(0) {}

void LineVolger::setupMotors() {
    buttonA.waitForButton();
}

void LineVolger::controlMotors(int16_t speedDifference) {
    int links = (int16_t)Motors::getMaxSpeed() + speedDifference;
    int rechts = (int16_t)Motors::getMaxSpeed() - speedDifference;

    links = constrain(links, 0, (int16_t)Motors::getMaxSpeed());
    rechts = constrain(rechts, 0, (int16_t)Motors::getMaxSpeed());

    rij.getMotors().setSpeeds(links, rechts);
}

int16_t LineVolger::getLastError() const {
    return lastError;
}

void LineVolger::setLastError(int16_t error) {
    lastError = error;
}

void LineVolger::readSensors() {
    int16_t position = lineSensor.readLineSensor(); // Use the LineSensor instance to read the position
    int16_t error = position - 2000;
    int16_t speedDifference = error / 0.75 + 20 * (error - getLastError());
    setLastError(error);
    controlMotors(speedDifference);
}
