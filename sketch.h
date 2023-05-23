#ifndef SKETCH_H
#define SKETCH_H

#include <QImage>
#include <iostream>
#include <vector>
#include "pixel.h"

using namespace std;

class Sketch
{
public:
    Sketch();
    ~Sketch();
    void drawPixel(Pixel pixel);
    void redraw();
    void clean();

    QImage *im;
    vector<Pixel> pixels;
private:
};

#endif // SKETCH_H
