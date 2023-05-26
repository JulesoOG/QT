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
        pix[0] = qBlue(pixel.colorRGB);
        pix[1] = qGreen(pixel.colorRGB);
        pix[2] = qRed(pixel.colorRGB);
        pixels.push_back(pixel);
    }
}
void Sketch::drawPixel(int x, int y, QRgb colorRGB){
    Pixel pixel = Pixel(x,y,colorRGB);
    if(pixel.x<im->width()){
        uchar *pix = im->scanLine(pixel.y)+4*pixel.x;
        pix[0] = qBlue(pixel.colorRGB);
        pix[1] = qGreen(pixel.colorRGB);
        pix[2] = qRed(pixel.colorRGB);
        pixels.push_back(pixel);
    }
}

void Sketch::redraw()
{
    for(int i = 0; i<(int)pixels.size(); i++)
    {
        uchar *pix = im->scanLine(pixels[i].y)+4*pixels[i].x;
        pix[0] = qBlue(pixels[i].colorRGB);
        pix[1] = qGreen(pixels[i].colorRGB);
        pix[2] = qRed(pixels[i].colorRGB);
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
