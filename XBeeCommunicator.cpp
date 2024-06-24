#include "XBeeCommunicator.h"

XBeeCommunicator::XBeeCommunicator(HardwareSerial& serialPort) : serial(serialPort) {}

void XBeeCommunicator::begin(int baudrate) {
  serial.begin(baudrate);
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
