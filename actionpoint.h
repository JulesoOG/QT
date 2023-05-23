#ifndef ACTIONPOINT_H
#define ACTIONPOINT_H

#include "shapeincircle.h"

class ActionPoint : public ShapeInCircle
{
public:
    ActionPoint(QImage *image);
    void activate();
    void deactivate();

    QPoint pos;
};

#endif // ACTIONPOINT_H
