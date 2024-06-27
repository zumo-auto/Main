#ifndef COLORLINE_H
#define COLORLINE_H

#include "Arduino.h"

class ColorLine{
public:

ColorLine(int, int, int);
void Color();
bool isWithinRange(int, int, int);
String kleure1();
String kleure2();
String kleure3();

private:

char niks2;
char niks3;
char niks4;

int iets;
int iets1;
int iets2;

};

#endif
