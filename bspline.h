#ifndef BSPLINE_H
#define BSPLINE_H

#include "line.h"
#include <cmath>

class BSpline : public Line
{
public:
    BSpline(int tResolutin, QPoint P1, QPoint P2, QPoint P3, QPoint P4, QRgb colorRGB, QImage *image);
    void drawBSpline(int tResolutin, QPoint P1, QPoint P2, QPoint P3, QPoint P4, QRgb colorRGB);
private:
    QPoint calculatePointOnCurve(float t ,QPoint P1, QPoint P2, QPoint P3, QPoint P4);
};

#endif // BSPLINE_H
