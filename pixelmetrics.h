#ifndef PIXELMETRICS_H
#define PIXELMETRICS_H


#include<QImage>
#include<vector>
#include "pixel.h"
class PixelMetrics
{
public:
    static int calculateDisntance(QPoint firstPos, QPoint secondPos);
    static Pixel* findAdjacentPixels(QPoint pos, QImage *im);
};

#endif // PIXELMETRICS_H
