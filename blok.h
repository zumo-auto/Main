#ifndef BLOK_H
#define BLOK_H

#include <Zumo32U4.h>
#include "MyZumo32U4Proximity.h"
#include "XBeeCommunicator.h"

const uint8_t sensorThreshold = 1;
const uint16_t turnSpeedMax = 400;
const uint16_t turnSpeedMin = 100;
const uint16_t deceleration = 10;
const uint16_t acceleration = 10;

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
