#include "actionpoint.h"

ActionPoint::ActionPoint(QImage *image)
{
    im = image;
}
void ActionPoint:: activate(){
    QPoint leftUpperCorner(pos.x()-10,pos.y()-10);
    QPoint rightUpperCorner(pos.x()+10,pos.y()+10);
    new ShapeInCircle(leftUpperCorner,rightUpperCorner,4,im);
}
void ActionPoint:: deactivate(){

}
