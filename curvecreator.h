#ifndef CURVECREATOR_H
#define CURVECREATOR_H

#include "sketch.h"
#include "actionpoint.h"
#include "pixelmetrics.h"


class CurveCreator
{
public:
    QImage *im;
    CurveCreator();
    ~CurveCreator();
    ActionPoint* getActionPoint(QPoint pos);
    void moveActionPoint(QPoint pos);
    void addActionPoint(QPoint pos);
    void removeActionPoint(QPoint pos);
    void redrawAll(vector<ActionPoint*> skeachesToRedraw);
    void eraiseCurves();
    void hidePoints(vector<ActionPoint*> polygonPoints);
    vector<Sketch*> curvesSketches;


    vector<ActionPoint*> actionPoints;
    //virtualna funkcja do nadpisania przez bezierCreator czy bsplineCreator
    virtual void drawCurves()=0;
protected:
    //protected konstruktor gdyz ta klasa nie powinna istniec samodzeilnie
    //jest jedynie rodzicem

};


#endif // CURVECREATOR_H
