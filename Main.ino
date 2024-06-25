#include <Wire.h>
#include "BuzzerController.h"
#include "LedController.h"
#include "BatteryController.h"
#include "XBeeCommunicator.h"

// De Serial1 verbinding wordt hier verklaard naar xbee
#define xbee Serial1

BuzzerController buzzerController;
LedController ledController;
BatteryController batteryController;
XBeeCommunicator xbeeCommunicator(xbee);

void setup() {
    xbee.begin(9600);
    ledController.startLed();
    batteryController.setXBeeCommunicator(&xbeeCommunicator);
}

void loop() {
    // Check de batterijstatus en print naar xbee
    batteryController.checkBattery();
}
