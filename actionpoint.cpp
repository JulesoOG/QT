#include "actionpoint.h"

ActionPoint::ActionPoint(QPoint pos, int radius, QImage *image)
{
    im = image;
    this->pos = pos;
    this->radius=radius;
    drawActionPoint(this->pos,this->radius);
}

void ActionPoint::drawActionPoint(QPoint pos, int radius){
    QPoint leftUpperCorner(pos.x()-radius,pos.y()-radius);
    QPoint rightUpperCorner(pos.x()+radius,pos.y()+radius);
    //new ShapeInCircle(leftUpperCorner,rightUpperCorner,4,im);
    drawShapeInCircle(leftUpperCorner.x(), leftUpperCorner.y(), rightUpperCorner.x(),rightUpperCorner.y(),4);
}



