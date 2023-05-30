#ifndef SCANLINE_H
#define SCANLINE_H

#include<vector>

#include "actionpoint.h"
#include "line.h"
#include "curvecreator.h"

class ScanLine:public Line, public CurveCreator
{
public:
    ScanLine(QImage *image);
    ScanLine* drawScanLine(QRgb colorRGB);
    void drawCurves() override;
private:

};

#endif // SCANLINE_H
