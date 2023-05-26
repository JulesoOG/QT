#ifndef BSPLINECREATOR_H
#define BSPLINECREATOR_H

#include "curvecreator.h"
#include "bspline.h"

class BSplineCreator:public CurveCreator
{
public:
    void drawCurves() override;
    BSplineCreator(QRgb colorRGB,QImage *image);
    QRgb curveColor;
};

#endif // BSPLINECREATOR_H
