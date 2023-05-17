#ifndef BEZIER_H
#define BEZIER_H

#include"line.h"
#include <cmath>

class Bezier : public Line
{
public:
    Bezier(int tResolutin, QPoint P1, QPoint P2, QPoint P3, QPoint P4, QImage *image);
    void drawBezier(int tResolutin, QPoint P1, QPoint P2, QPoint P3, QPoint P4);
private:
    QPoint calculatePointOnCurve(float t ,QPoint P1, QPoint P2, QPoint P3, QPoint P4);
};

#endif // BEZIER_H
