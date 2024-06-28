#include "BatteryController.h"

BatteryController::BatteryController() : xbeeCommunicator() {}

void BatteryController::setXBeeCommunicator(XBeeCommunicator* communicator) {
    xbeeCommunicator = communicator;
}

void BatteryController::checkBattery() {
    delay(200);
    // Controleren of er USB-stroom aanwezig is
    bool usbPower = usbPowerPresent();

    // Lezen van het batterijniveau in millivolt
    uint16_t batteryLevel = readBatteryMillivolts();

    // Maak een buffer voor het bericht
    char message[50];

    // Format het bericht
    snprintf(message, sizeof(message), "USB=%c B=%u mV", usbPower ? 'Y' : 'N', batteryLevel);

    // Verstuur het bericht via XBee
    if (xbeeCommunicator != nullptr) {
        xbeeCommunicator->println(message);
    }
}