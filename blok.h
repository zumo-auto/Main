#ifndef BLOK_H
#define BLOK_H

#include "MyZumo32U4Proximity.h"
#include "XBeeCommunicator.h"
#include <Zumo32U4Motors.h>
#include <Zumo32U4Buttons.h> // Include Zumo32U4Buttons header

// Forward declaration of Zumo32U4Motors class
class Zumo32U4Motors;

const uint8_t sensorThreshold = 1;
const uint16_t turnSpeedMax = 150;
const uint16_t turnSpeedMin = 100;
const uint16_t deceleration = 10;
const uint16_t acceleration = 10;
const uint16_t forwardSpeed = 200; // Speed for moving forward

#define LEFT 0
#define RIGHT 1

class Blok
{
public:
    Blok();
    void init();
    void turnRight();
    void turnLeft();
    void stop();
    void loop();
    void scan360();
    void moveForward(); // Declaration of the moveForward function

private:
    Zumo32U4Motors motors;
    Zumo32U4ButtonA buttonA;
    MyZumo32U4Proximity proxSensors;
    XBeeCommunicator xbee;

    bool senseDir = RIGHT;
    bool turningLeft = false;
    bool turningRight = false;
    uint16_t turnSpeed = turnSpeedMax;
    uint16_t lastTimeObjectSeen = 0;
};

#endif // BLOK_H
