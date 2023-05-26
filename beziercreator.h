#ifndef BEZIERCREATOR_H
#define BEZIERCREATOR_H

#include<QImage>
#include "curvecreator.h"
#include "bezier.h"
class BezierCreator : public CurveCreator
{
public:
    BezierCreator(QRgb colorRGB,QImage *image);
    void drawCurves() override;
    QRgb curveColor;

};

#endif // BEZIERCREATOR_H
