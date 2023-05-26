#include "bsplinecreator.h"

BSplineCreator::BSplineCreator(QRgb colorRGB,QImage *image)
{
    curveColor = colorRGB;
    im = image;
}

void BSplineCreator::drawCurves(){
    eraiseCurves();
    if(actionPoints.size()>3)
    {
        for(int i=4;i<=(int)actionPoints.size();i++){
            Sketch *newSketch;
            newSketch = new BSpline(20,actionPoints[i-4]->pos, actionPoints[i-3]->pos, actionPoints[i-2]->pos, actionPoints[i-1]->pos,curveColor, im);
            curvesSketches.push_back(newSketch);
        }
    }
}
