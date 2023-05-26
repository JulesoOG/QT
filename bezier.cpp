#include "bezier.h"

Bezier::Bezier(int nLines, QPoint P1, QPoint P2, QPoint P3, QPoint P4,QRgb colorRGB, QImage *image)
{
    im = image;
    drawBezier(nLines,P1,P2,P3,P4,colorRGB);
}
void Bezier::drawBezier(int nLines, QPoint P1, QPoint P2, QPoint P3, QPoint P4,QRgb colorRGB)
{
    QPoint prevPos = calculatePointOnCurve(0,P1,P2,P3,P4);
    for(int i=1; i<=nLines;i++)
    {
        float t = (float)i/nLines;
        QPoint currentPos = calculatePointOnCurve(t,P1,P2,P3,P4);

        //drawPixel(Pixel(currentPos.x(),currentPos.y(),255,255,255));
        drawLine(prevPos.x(),prevPos.y(),currentPos.x(),currentPos.y(),colorRGB);

        prevPos=currentPos;
    }
    //drawLine(prevPos.x(), prevPos.y(), P4.x(), P4.y()); wystarczylo zamienic i<nLines na i<=nLines
}

QPoint Bezier::calculatePointOnCurve(float t ,QPoint P1, QPoint P2, QPoint P3, QPoint P4)
{
    int x, y;
    x = pow((1-t),3)*P1.x()+3*pow((1-t),2)*P2.x()*t+3*(1-t)*P3.x()*pow(t,2)+pow(t,3)*P4.x();
    y = pow((1-t),3)*P1.y()+3*pow((1-t),2)*P2.y()*t+3*(1-t)*P3.y()*pow(t,2)+pow(t,3)*P4.y();
    //cout<<x<<", "<<y<<endl;
    QPoint resoltPos(x,y);
    return resoltPos;
}
