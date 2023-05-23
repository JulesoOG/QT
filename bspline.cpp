#include "bspline.h"

BSpline::BSpline(int nLines, QPoint P1, QPoint P2, QPoint P3, QPoint P4, QImage *image)
{
    im = image;
    drawBSpline(nLines,P1,P2,P3,P4);
}
void BSpline::drawBSpline(int nLines, QPoint P1, QPoint P2, QPoint P3, QPoint P4)
{
    QPoint prevPos = calculatePointOnCurve(0,P1,P2,P3,P4);
    for(int i=1; i<nLines;i++)
    {
        float t = (float)i/nLines;
        QPoint currentPos = calculatePointOnCurve(t,P1,P2,P3,P4);
        drawLine(prevPos.x(),prevPos.y(),currentPos.x(),currentPos.y());

        prevPos=currentPos;
    }
}

QPoint BSpline::calculatePointOnCurve(float t ,QPoint P1, QPoint P2, QPoint P3, QPoint P4)
{
    int x, y;
    x = (float)1/6*(-pow(t,3)+3*pow(t,2)-3*t+1)*P1.x()
            +(float)1/6*(3*pow(t,3)-6*pow(t,2)+4)*P2.x()
            +(float)1/6*(-3*pow(t,3)+3*pow(t,2)+3*t+1)*P3.x()
            +(float)1/6*pow(t,3)*P4.x();
    y = (float)1/6*(-pow(t,3)+3*pow(t,2)-3*t+1)*P1.y()
            +(float)1/6*(3*pow(t,3)-6*pow(t,2)+4)*P2.y()
            +(float)1/6*(-3*pow(t,3)+3*pow(t,2)+3*t+1)*P3.y()
            +(float)1/6*pow(t,3)*P4.y();

    cout<<x<<", "<<y<<endl;
    QPoint resoltPos(x,y);
    return resoltPos;
}

