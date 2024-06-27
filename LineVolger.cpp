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
    int16_t position = lineSensor.readLineSensor();

    // Onze "error" is hoe ver we van het midden van de lijn verwijderd zijn,
    // wat overeenkomt met positie 2000.
    int16_t error = position - 2000;

    computeAndSetSpeeds(error, lastError);

    lastError = error;
}

void LineVolger::computeAndSetSpeeds(int16_t error, int16_t lastError) {
    int16_t speedDifference = error / 0.75 + 20 * (error - lastError);

    // Verkrijg individuele motorsnelheden. Het teken van speedDifference
    // bepaalt of de robot naar links of naar rechts draait.
    int16_t leftSpeed = motors.maxSpeed + speedDifference;
    int16_t rightSpeed = motors.maxSpeed - speedDifference;

    // Beperk onze motorsnelheden tot tussen 0 en maxSpeed.
    // Hierdoor draait hij niet om nadat hij wit of een andere kleur gemeten heeft.
    leftSpeed = constrain(leftSpeed, -100, motors.maxSpeed);
    rightSpeed = constrain(rightSpeed, -100, motors.maxSpeed);

    motors.setSpeeds(leftSpeed, rightSpeed);
}
