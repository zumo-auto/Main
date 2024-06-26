#include "blok.h"
#include <Arduino.h>
#include <Zumo32U4Motors.h>

Blok::Blok() : motors(), xbee(Serial1) {}

void Blok::init()
{
    proxSensors.begin();
}

void Blok::turnRight()
{
    motors.setSpeeds(turnSpeed, -turnSpeed);
    turningLeft = false;
    turningRight = true;
}

void Blok::turnLeft()
{
    motors.setSpeeds(-turnSpeed, turnSpeed);
    turningLeft = true;
    turningRight = false;
}

void Blok::stop()
{
    motors.setSpeeds(0, 0);
    turningLeft = false;
    turningRight = false;
}

void Blok::moveForward()
{
    motors.setSpeeds(forwardSpeed, forwardSpeed);
    turningLeft = false;
    turningRight = false;
}

void Blok::loop()
{
    proxSensors.readSensors();
    uint8_t leftValue = proxSensors.getFrontLeftSensorValue();
    uint8_t rightValue = proxSensors.getFrontRightSensorValue();

    bool objectSeen = leftValue >= sensorThreshold || rightValue >= sensorThreshold;

    if (objectSeen)
    {
        turnSpeed -= deceleration;
    }
    else
    {
        turnSpeed += acceleration;
    }

    turnSpeed = constrain(turnSpeed, turnSpeedMin, turnSpeedMax);

    if (leftValue >= 3 && rightValue >= 3)
    {
        moveForward();
    }
    else if (objectSeen)
    {
        lastTimeObjectSeen = millis();

        if (leftValue < rightValue)
        {
            turnRight();
            senseDir = RIGHT;
        }
        else if (leftValue > rightValue)
        {
            turnLeft();
            senseDir = LEFT;
        }
        else
        {
            stop();
        }
    }
    else
    {
        if (senseDir == RIGHT)
        {
            turnRight();
        }
        else
        {
            turnLeft();
        }
    }
}
