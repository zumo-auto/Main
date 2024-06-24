#include <Wire.h>
#include <Zumo32U4.h>

const int16_t maxSpeed = 120;
const int16_t motorSpeed = 80; // Versnelde motor snelheid
const int16_t deadzone = 69;
const unsigned long stillTime = 5000; // 5 seconden stilstaan
const unsigned long hysteresisTime = 40; // Versnelde hysteresis tijd

Zumo32U4IMU imu;
Zumo32U4Motors motors;
Zumo32U4Encoders encoders;

unsigned long lastMovementTime = 0;
unsigned long inDeadzoneStartTime = 0;
unsigned long lastPrintTime = 0;
const unsigned long printInterval = 200; // Print interval in milliseconds (0.2 seconds)

void setup() {
Serial1.begin(4800); // Gebruik Serial1 voor de XBee of andere module
Wire.begin();
delay(50);
imu.init();
imu.enableDefault();
imu.configureForFaceUphill();
}

void loop() {
unsigned long currentMillis = millis();
int16_t x = 0; // Declare x outside the print interval block

// Check if it's time to read and print gyroscopic data
if (currentMillis - lastPrintTime >= printInterval) {
imu.readAcc(); // Lees de accelerometergegevens
x = imu.a.x / 22; // Gebruik imu.a.x als gyroscopische waarde

Serial1.println(x); // Stuur de waarde naar Serial1 (XBee)

lastPrintTime = currentMillis; // Update last print time
}

int16_t forwardSpeed = -(encoders.getCountsLeft() + encoders.getCountsRight());
forwardSpeed = constrain(forwardSpeed, -maxSpeed, maxSpeed);

if (abs(x) <= deadzone) {
if (inDeadzoneStartTime == 0) {
inDeadzoneStartTime = millis();
}
if (millis() - inDeadzoneStartTime >= hysteresisTime) {
motors.setSpeeds(0, 0);
if (millis() - lastMovementTime >= stillTime) {
motors.setSpeeds(0, 0); // Stop de motoren
}
}
} else {
// Buiten de deadzone, beweeg de Zumo
if (x > deadzone) {
motors.setSpeeds(motorSpeed, motorSpeed);
} else if (x < -deadzone) {
motors.setSpeeds(-motorSpeed, -motorSpeed);
delay(50);
}
// Reset de timer voor het stilstaan
lastMovementTime = millis();
inDeadzoneStartTime = 0;
}
}
