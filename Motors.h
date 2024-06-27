#ifndef MOTORS_H
#define MOTORS_H

#include <Zumo32U4.h>

class Motors {
public:
    Motors();
    void setSpeeds(int16_t leftSpeed, int16_t rightSpeed);
    void updateSpeedsBasedOnColor(const String& color);
    Zumo32U4Motors& getMotors();
    int16_t getLeftSpeed() const;
    int16_t getRightSpeed() const;

    uint16_t maxSpeed;

private:
    Zumo32U4Motors motors;
    int16_t leftSpeed;
    int16_t rightSpeed;
};

#endif // MOTORS_H
