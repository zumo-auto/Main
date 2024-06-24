#ifndef MYZUMO32U4PROXIMITY_H
#define MYZUMO32U4PROXIMITY_H

#include <Zumo32U4.h>

class MyZumo32U4Proximity
{
public:
    MyZumo32U4Proximity();
    void begin();
    void readSensors();
    int getFrontLeftSensorValue();
    int getFrontRightSensorValue();

private:
    Zumo32U4ProximitySensors proxSensors;
    int frontLeftSensorValue;
    int frontRightSensorValue;
};

#endif // MYZUMO32U4PROXIMITY_H
