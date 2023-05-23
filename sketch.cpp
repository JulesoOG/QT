#include "sketch.h"

Sketch::Sketch()
{
    //std::cout<<"Sketch"<<std::endl;
}
Sketch::~Sketch()
{
    std::cout<<"Sketch destructor"<<std::endl;
    clean();
}
//void Sketch::drawPixel(int x, int y, int r, int g, int b)
void Sketch::drawPixel(Pixel pixel)
{
    if(pixel.x<im->width()){
        uchar *pix = im->scanLine(pixel.y)+4*pixel.x;
        pix[0] = pixel.blue;
        pix[1] = pixel.green;
        pix[2] = pixel.red;
        pixels.push_back(pixel);
    }
}

void Sketch::redraw()
{
    for(int i = 0; i<(int)pixels.size(); i++)
    {
        uchar *pix = im->scanLine(pixels[i].y)+4*pixels[i].x;
        pix[0] = pixels[i].blue;
        pix[1] = pixels[i].green;
        pix[2] = pixels[i].red;
    }
}


void Sketch::clean()
{
    for(int i = 0; i<(int)pixels.size(); i++)
    {
        uchar *pix = im->scanLine(pixels[i].y)+4*pixels[i].x;
        pix[0] = 0;
        pix[1] = 0;
        pix[2] = 0;
    }
}
