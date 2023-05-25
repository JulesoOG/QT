#ifndef BEZIERCREATOR_H
#define BEZIERCREATOR_H

#include<QImage>
#include "curvecreator.h"
#include "bezier.h"
class BezierCreator : public CurveCreator
{
public:
    BezierCreator(QImage *image);
    void drawCurves() override;
private:
    //int bezierPointsCounter=0;
};

#endif // BEZIERCREATOR_H
