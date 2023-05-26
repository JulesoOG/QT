#ifndef PIXEL_H
#define PIXEL_H

#include <QColor>
class Pixel
{
public:
    Pixel(int x, int y, QRgb colorRGB);
    Pixel();
    void SetValues(int x, int y, QRgb colorRGB);
    int x,y;
    QRgb colorRGB;
};

#endif // PIXEL_H
