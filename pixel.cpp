#include "pixel.h"

Pixel::Pixel(int x, int y, int red, int green, int blue)
{
   SetValues(x,y,red,green,blue);
}

Pixel::Pixel()
{

}

void Pixel::SetValues(int x, int y, int red, int green, int blue){
    this->x = x;
    this->y = y;
    this->red = red;
    this->blue = blue;
    this->green = green;
}

