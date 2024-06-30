#ifndef BATTERY_CONTROLLER_H
#define BATTERY_CONTROLLER_H

#include <Zumo32U4.h>
#include "XBeeCommunicator.h"

// BatteryController voor de batterij
class BatteryController {
public:
    BatteryController();
    void checkBattery();
    void setXBeeCommunicator(XBeeCommunicator* communicator);

private:
    XBeeCommunicator* xbeeCommunicator;
};

#endif // BATTERY_CONTROLLER_H
