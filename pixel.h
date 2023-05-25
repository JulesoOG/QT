#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
public:
    Pixel(int x, int y, int red, int green, int blue);
    Pixel();
    void SetValues(int x, int y, int red, int green, int blue);
    int x,y,red,green,blue;
};

#endif // PIXEL_H
