#include "sketch.h"

Sketch::Sketch()
{
    std::cout<<"Sketch"<<std::endl;
}

//void Sketch::drawPixel(int x, int y, int r, int g, int b)
void Sketch::drawPixel(Pixel pixel)
{
    if(pixel.x<im->width()){
        uchar *pix = im->scanLine(pixel.y)+4*pixel.x;
        pix[0] = pixel.blue;
        pix[1] = pixel.green;
        pix[2] = pixel.red;
        pixels.push(pixel);
    }
}
