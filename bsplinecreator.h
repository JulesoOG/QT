#ifndef BSPLINECREATOR_H
#define BSPLINECREATOR_H

#include "curvecreator.h"
#include "bspline.h"

class BSplineCreator:public CurveCreator
{
public:
    void drawCurves() override;
    BSplineCreator(QImage *image);
};

#endif // BSPLINECREATOR_H
