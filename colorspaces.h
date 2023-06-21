#ifndef COLORSPACES_H
#define COLORSPACES_H

#include "sketch.h"

class ColorSpaces : public Sketch
{
public:
    ColorSpaces(QImage *image);
    void RGBSpace(float red, float green, float blue);
    void HSVSpace(int hue,int saturation, int value);
};

#endif // COLORSPACES_H
