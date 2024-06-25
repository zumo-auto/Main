#ifndef COLORLINE_H
#define COLORLINE_H

#include "Arduino.h"

class ColorLine{
public:

ColorLine(int, int, int);
void Color();
bool isWithinRange(int, int, int);
String kleure();

private:

bool Groen;
bool Grijsrecht;
bool GrijsLinks;
bool Zwart;
bool niks;
int iets;
int iets1;
int iets2;

};

#endif