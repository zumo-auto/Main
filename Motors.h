#ifndef MOTORS_H
#define MOTORS_H

#include "Arduino.h"
#include <Wire.h>
#include <Zumo32U4.h>

class Motors {
public:
    Motors(int, int, String);
    void setSpeeds();
    Zumo32U4Motors& getMotors();
    static uint16_t getMaxSpeed() { return maxSpeed; } // Add this line

private:
    int links;
    int rechts;
    String kleure;
    Zumo32U4Motors motors;
    static const uint16_t maxSpeed;
};

#endif // MOTORS_H
