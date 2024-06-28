#ifndef LINE_SENSOR_H
#define LINE_SENSOR_H

#include <Zumo32U4.h>

class Line_sensor {
public:
    Line_sensor(); // Constructor declaration

    void detectColor();
    uint16_t sensor1();
    uint16_t sensor2();
    uint16_t sensor3();
    uint16_t sensor4();
    uint16_t sensor5();
    void calibrateSensors(Zumo32U4Motors& motors);

    // New method declaration
    int16_t readLineSensor();

private:
    Zumo32U4LineSensors lineSensors;
    uint16_t sensorValues[3];
    uint16_t sensor11;
    uint16_t sensor22;
    uint16_t sensor33;
    uint16_t sensor44;
    uint16_t sensor55;
};

#endif
