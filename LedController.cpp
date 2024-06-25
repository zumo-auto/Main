#include "LedController.h"

LedController::LedController() {}

void LedController::startLed() {
    // De gele led gaat aan en uit
    ledYellow(1);
    delay(1000);
    ledYellow(0);
    delay(1000);
}
