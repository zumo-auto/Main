#ifndef LINEVOLGER_H
#define LINEVOLGER_H

#include "Motors.h"
#include "LineSensor.h"
#include <Zumo32U4.h>

class LineVolger {
public:
    LineVolger(Motors& motors);
    void setupMotors();
    void controlMotors(int16_t speedDifference);
    int16_t getLastError() const;
    void setLastError(int16_t error);
    void readSensors();

private:
    Motors& rij;
    LineSensor lineSensor; // Add this line
    Zumo32U4ButtonA buttonA;
    int16_t lastError;
};

#endif // LINEVOLGER_H
