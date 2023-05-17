#include "shapeincircle.h"

ShapeInCircle::ShapeInCircle(QPoint startPos, QPoint endPos, int nKontow, QImage *image)
{
    im = image;
    drawShapeInCircle(startPos.x(), startPos.y(), endPos.x(), endPos.y(), nKontow);
}
void ShapeInCircle::drawShapeInCircle(int x1, int y1, int x2, int y2, int nKontow)
{
    int srodekX = (x1+x2)/2;
    int srodekY = (y1+y2)/2;
    int rPoziom = abs(x2-x1)/2;
    int rPion = abs(y2-y1)/2;

    int x,y;
    float alpha = 0;
    int xOld = rPoziom*cos(alpha);
    int yOld = rPion*sin(alpha);
    for(int i = 1; i<=nKontow;i++){
        alpha = 6.28 * i/nKontow; // 2Pi/n*i
        x = rPoziom * cos(alpha);
        y = rPion * sin(alpha);
        drawLine(x+srodekX,y+srodekY,xOld+srodekX,yOld+srodekY);
        xOld=x;
        yOld=y;
    }
}
