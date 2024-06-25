#ifndef XBEE_COMMUNICATOR_H
#define XBEE_COMMUNICATOR_H
#include <Arduino.h>

class XBeeCommunicator {
  public:
    XBeeCommunicator(HardwareSerial& serialPort);
    void begin(int baudrate);
    bool available();
    char read();
    void println(const char* message);

  private:
    HardwareSerial& serial;
};

#endif
