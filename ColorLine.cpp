#include "ColorLine.h"

ColorLine::ColorLine(int L, int M, int R) : iets(L), iets1(M), iets2(R)// construeren van de int naar iets toe
{

}

bool ColorLine::isWithinRange(int value,int lowerBound,int upperBound){
  return value > lowerBound && value < upperBound;
}

void ColorLine::Color(){ // het kiezen in welke kleur het zicht bevind
  
    if (isWithinRange(iets, 50, 200) && isWithinRange(iets1, 50, 200) && isWithinRange(iets2, 50, 150)) {//if else statement becaus an switch statement can't do number range with in the statement
        // if this is true then the color is Green
        Groen = true;
        Grijsrecht = false;
        GrijsLinks = false;
        Zwart = false;
        niks = false;
    } else if (isWithinRange(iets, 200, 400)) {
        // if this is true then the color is Gray left and we need to go left
        Groen = false;
        Grijsrecht = false;
        GrijsLinks = true;
        Zwart = false;
        niks = false;
    } else if (isWithinRange(iets2, 150, 250)) {
        // if this is true then the color is Gray right and we need to go right
        Groen = false;
        Grijsrecht = true;
        GrijsLinks = false;
        Zwart = false;
        niks = false;
    } else if (isWithinRange(iets, 900, 1000) && isWithinRange(iets1, 900, 1000) && isWithinRange(iets2, 900, 1000)) {
        // if this is true then the color is Black
        Groen = false;
        Grijsrecht = false;
        GrijsLinks = false;
        Zwart = true;
        niks = false;
    } else {
        // if none of the above is true then the color is nothing
        Groen = false;
        Grijsrecht = false;
        GrijsLinks = false;
        Zwart = false;
        niks = true;
    }


}

String ColorLine::kleure(){ // Geeft mee in een string welke kleur er actief is

switch(Groen,Grijsrecht,GrijsLinks,Zwart,niks){

 case 'Groen':
   return "Groen";
 break;

 case 'Grijsrecht':
   return "Grijsrecht";
 break;

 case 'GrijsLinks':
   return "GrijsLinks";
 break;

 case 'Zwart':
   return "Zwart";
 break;

 case 'niks':
   return "niks";
 break;

}

}