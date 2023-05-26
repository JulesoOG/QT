#ifndef FLOODFILL_H
#define FLOODFILL_H

#include <stack>

#include "sketch.h"
#include "pixel.h"

class FloodFill : public Sketch
{
public:
    FloodFill(QPoint pos, QRgb fillColor, QRgb backgroundColor, QImage *image);
    void drawFloodFill(QPoint pos, QRgb fillColor, QRgb backgroundColor);
private:
    stack<QPoint> pixelPosStack;
};

#endif // FLOODFILL_H
