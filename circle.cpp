#include "circle.h"

Circle::Circle()
{

}
Circle::Circle(QPoint center, QPoint edge, QRgb colorRGB, QImage *image)
{
    im = image;
    drawCircle(center, edge, colorRGB);
}

void Circle::drawCircle(QPoint center, QPoint edge, QRgb colorRGB)
{

    float radius = PixelMetrics::calculateDisntance(center,edge);
    for(int i=-radius; i<=radius; i++)
    {
        double y = sqrt(radius*radius - i*i);
        drawPixel(i+center.x(),(int)floor(y+0.5)+edge.y(),colorRGB);      // prawy dół
        drawPixel(i+center.x(),-(int)floor(y+0.5)+edge.y(),colorRGB);    //prawa góra
        drawPixel(-i+center.x(),(int)floor(y+0.5)+edge.y(),colorRGB);   //lewy dół
        drawPixel(-i+center.x(),-(int)floor(y+0.5)+edge.y(),colorRGB);
        drawPixel((int)floor(y+0.5)+center.x(),i+edge.y(),colorRGB);       //prawy środek "dół"
        drawPixel(-(int)floor(y+0.5)+center.x(),i+edge.y(),colorRGB);     //lewy środek "dół"
        drawPixel((int)floor(y+0.5)+center.x(),-i+edge.y(),colorRGB);    //prawy środek "góra"
        drawPixel(-(int)floor(y+0.5)+center.x(),-i+edge.y(),colorRGB);  //lewy środek "góra"//lewa góra
    }

}
