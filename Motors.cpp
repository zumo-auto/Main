#include "Motors.h"

// Initialize the static member maxSpeed
const uint16_t Motors::maxSpeed = 320;

Motors::Motors(int lSpeed, int rSpeed, String h) : links(lSpeed), rechts(rSpeed), kleure(h) {
    // Initialization of member variables done in the initializer list
}

void Motors::setSpeeds() {
    if (kleure == "Groen") {
        links = 200;
        rechts = 200;
    } else if (kleure == "Zwart") {
        links = 400;
        rechts = 400;
    } else if (kleure == "GrijsLinks") {
        links = 400;
        rechts = -400;
    } else if (kleure == "Grijsrecht") {
        links = -400;
        rechts = 400;
    } else if (kleure == "Grijsrecht" && kleure == "GrijsLinks") {
        links = 0;
        rechts = 0;
    }
}

Zumo32U4Motors& Motors::getMotors() {
    return motors;
}
