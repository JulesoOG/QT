#ifndef CURVECREATOR_H
#define CURVECREATOR_H

#include "sketch.h"
#include "pixelmetrics.h"
#include "actionpoint.h"

class CurveCreator
{
public:
    QImage *im;

    ActionPoint* getActionPoint(QPoint pos);
    void moveActionPoint(QPoint pos);
    void addActionPoint(QPoint pos);
    void removeActionPoint(QPoint pos);
    void redrawAll(vector<ActionPoint*> skeachesToRedraw);
    void eraiseCurves();
    vector<Sketch*> curvesSketches;


    vector<ActionPoint*> actionPoints;
    //virtualna funkcja do nadpisania przez bezierCreator czy bsplineCreator
    virtual void drawCurves()=0;
protected:
    //protected konstruktor gdyz ta klasa nie powinna istniec samodzeilnie
    //jest jedynie rodzicem
    CurveCreator();
};


#endif // CURVECREATOR_H
