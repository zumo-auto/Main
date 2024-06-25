#include "BuzzerController.h"

BuzzerController::BuzzerController() {
    // Constructor om een melodie te spelen bij initiatie
    buzzer.play(F("l8 cdefgab>c"));
}
