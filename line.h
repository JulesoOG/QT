#ifndef LINE_H
#define LINE_H

#include "sketch.h"


class Line : public Sketch
{
public:
Line(QPoint startPos, QPoint endPos,QRgb colorRGB, QImage *image);
Line();
void drawLine(int x1, int y1, int x2, int y2, QRgb colorRGB);
};

#endif // LINE_H
