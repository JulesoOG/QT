#include "pixel.h"

Pixel::Pixel(int x, int y, QRgb colorRGB)
{
   SetValues(x,y,colorRGB);
}

Pixel::Pixel()
{

}

void Pixel::SetValues(int x, int y,QRgb colorRGB){
    this->x = x;
    this->y = y;
    this->colorRGB = colorRGB;
}

