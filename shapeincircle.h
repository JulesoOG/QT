#ifndef SHAPEINCIRCLE_H
#define SHAPEINCIRCLE_H

#include"line.h"

class ShapeInCircle : public Line
{
public:
    ShapeInCircle(QPoint startPos, QPoint endPos,int nKontow,QRgb colorRGB, QImage *image);
    ShapeInCircle();
    void drawShapeInCircle(int x1, int y1, int x2, int y2, int nKontow, QRgb colorRGB);
};

#endif // SHAPEINCIRCLE_H
