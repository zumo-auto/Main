#ifndef LINEVOLGER_H
#define LINEVOLGER_H

#include "LineSensor.h"
#include "Motors.h"

class LineVolger {
public:
    void setup();
    void loop();
    void calibrateSensors();

private:
    LineSensor lineSensor;
    Motors motors;
    int16_t lastError;

    void followLine();
    void computeAndSetSpeeds(int16_t error, int16_t lastError);
};

#endif // LINEVOLGER_H
