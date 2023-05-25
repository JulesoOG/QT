#ifndef BEZIERCREATOR_H
#define BEZIERCREATOR_H

#include<QImage>

#include "sketch.h"
#include "pixelmetrics.h"
#include "bezier.h"
#include "actionpoint.h"

class BezierCreator
{
public:
    QImage *im;

    BezierCreator(QImage *image);

    ActionPoint* getActionPoint(QPoint pos);
    void moveActionPoint(QPoint pos);
    void addActionPoint(QPoint pos);
    void removeActionPoint(QPoint pos);
    void drawBeziers();
    void eraiseBeziers();
    void redrawAll(vector<ActionPoint*> skeachesToRedraw);

    vector<ActionPoint*> actionPoints;
    vector<Sketch*> bezierSketches;
private:
    //int bezierPointsCounter=0;
};

#endif // BEZIERCREATOR_H
