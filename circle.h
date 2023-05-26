#ifndef CIRCLE_H
#define CIRCLE_H

#include "sketch.h"
#include "pixelmetrics.h"
#include "pixel.h"
class Circle : public Sketch
{
public:
    Circle(QPoint center, QPoint edge,QRgb colorRGB, QImage *image);
    Circle();
    void drawCircle(QPoint center, QPoint edge,QRgb colorRGB);
};

#endif // CIRCLE_H
