#ifndef ACTIONPOINT_H
#define ACTIONPOINT_H

#include "shapeincircle.h"

class ActionPoint : public ShapeInCircle
{
public:
    ActionPoint(QPoint pos, int radius, QImage *image);

     void drawActionPoint(QPoint pos,int radius);

    QPoint pos;
    int radius;
private:

};

#endif // ACTIONPOINT_H
