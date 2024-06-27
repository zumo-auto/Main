#include "ColorLine.h"

ColorLine::ColorLine(int L, int M, int R)
  : iets(L), iets1(M), iets2(R)  // construeren van de int naar iets toe
{
}

bool ColorLine::isWithinRange(int value, int lowerBound, int upperBound) {
  return value > lowerBound && value < upperBound;
}

void ColorLine::Color() {  // het kiezen in welke kleur het zicht bevind

  if (isWithinRange(iets, 50, 200)) {  //if else statement becaus an switch statement can't do number range with in the statement
    // if this is true then the color is Green
    niks2 = '1';

  } else if (isWithinRange(iets, 200, 400)) {
    // if this is true then the color is Gray left and we need to go left
    niks2 = '2';

    //} else if (isWithinRange(iets2, 150, 250)) {
    // if this is true then the color is Gray right and we need to go right
    // niks2 = '3';

  } else if (isWithinRange(iets, 900, 1000)) {
    // if this is true then the color is Black
    niks2 = '4';

  } else {
    // if none of the above is true then the color is nothing
    niks2 = '5';
  }

  if (isWithinRange(iets1, 50, 200)) {  //if else statement becaus an switch statement can't do number range with in the statement
    // if this is true then the color is Green
    niks3 = '1';

    //} else if (isWithinRange(iets, 200, 400)) {
    // if this is true then the color is Gray left and we need to go left
    //  niks3 = '2';

    //} else if (isWithinRange(iets2, 150, 250)) {
    // if this is true then the color is Gray right and we need to go right
    // niks3 = '3';

  } else if (isWithinRange(iets1, 900, 1000)) {
    // if this is true then the color is Black
    niks3 = '4';

  } else {
    // if none of the above is true then the color is nothing
    niks3 = '5';
  }

  if (isWithinRange(iets2, 50, 150)) {  //if else statement becaus an switch statement can't do number range with in the statement
    // if this is true then the color is Green
    niks4 = '1';

    // } else if (isWithinRange(iets, 200, 400)) {
    // if this is true then the color is Gray left and we need to go left
    // niks4 = '2';

  } else if (isWithinRange(iets2, 150, 250)) {
    // if this is true then the color is Gray right and we need to go right
    niks4 = '3';

  } else if (isWithinRange(iets2, 900, 1000)) {
    // if this is true then the color is Black
    niks4 = '4';

  } else {
    // if none of the above is true then the color is nothing
    niks4 = '5';
  }
}

String ColorLine::kleure1() {  // Geeft mee in een string welke kleur er actief is

  switch (niks2) {

    case '1':
      return "Groen";
      break;

      //case '2':
      //return "Grijsrecht";
      //break;

    case '3':
      return "GrijsLinks";
      break;

    case '4':
      return "Zwart";
      break;

    case '5':
      return "niks";
      break;
  }
}

String ColorLine::kleure2() {  // Geeft mee in een string welke kleur er actief is

  switch (niks3) {

    case '1':
      return "Groen";
      break;

      //case '2':
      //return "Grijsrecht";
      //break;

      //case '3':
      //return "GrijsLinks";
      //break;

    case '4':
      return "Zwart";
      break;

    case '5':
      return "niks";
      break;
  }
}

String ColorLine::kleure3() {  // Geeft mee in een string welke kleur er actief is

  switch (niks4) {

    case '1':
      return "Groen";
      break;

    case '2':
      return "Grijsrecht";
      break;

      //case '3':
      //return "GrijsLinks";
      //break;

    case '4':
      return "Zwart";
      break;

    case '5':
      return "niks";
      break;
  }
}
