#include "XBeeCommunicator.h"

XBeeCommunicator::XBeeCommunicator(HardwareSerial& serialPort) : serial(serialPort) {}

void XBeeCommunicator::begin(unsigned long baudrate) {
  serial.begin(baudrate);
  serial.println("Xbee is ready. Please try something.");
}

bool XBeeCommunicator::available() {
  return serial.available();
}

char XBeeCommunicator::read() {
  return serial.read();
}

void XBeeCommunicator::println(const char* message) {
  serial.println(message);
}
