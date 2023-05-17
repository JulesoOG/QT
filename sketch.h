#ifndef SKETCH_H
#define SKETCH_H

#include <QImage>
#include <iostream>
#include <queue>
#include "pixel.h"

using namespace std;

class Sketch
{
public:
    Sketch();
    void drawPixel(Pixel pixel);
    QImage *im;
    queue<Pixel> pixels;
};

#endif // SKETCH_H
