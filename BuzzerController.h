#ifndef BUZZER_CONTROLLER_H
#define BUZZER_CONTROLLER_H

#include <Zumo32U4.h>

// Buzzer controller voor de buzzer
class BuzzerController {
private:
    Zumo32U4Buzzer buzzer;
public:
    BuzzerController();
};

#endif // BUZZER_CONTROLLER_H
