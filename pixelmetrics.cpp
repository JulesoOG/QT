#include "pixelmetrics.h"

int PixelMetrics::calculateDisntance(QPoint firstPos, QPoint secondPos){
    return sqrt((firstPos.x()-secondPos.x())*(firstPos.x()-secondPos.x())+(firstPos.y()-secondPos.y())*(firstPos.y()-secondPos.y()));
}

Pixel* PixelMetrics::findAdjacentPixels(QPoint pos, QImage *im){
    Pixel adjacentPixels[8];
    adjacentPixels[0].SetValues(pos.x(),pos.y()+1,0,0,0);
    adjacentPixels[1].SetValues(pos.x()+1,pos.y(),0,0,0);
    adjacentPixels[2].SetValues(pos.x(),pos.y()-1,0,0,0);
    adjacentPixels[3].SetValues(pos.x()-1,pos.y(),0,0,0);

    adjacentPixels[4].SetValues(pos.x()-1,pos.y()+1,0,0,0);
    adjacentPixels[5].SetValues(pos.x()+1,pos.y()+1,0,0,0);
    adjacentPixels[6].SetValues(pos.x()+1,pos.y()-1,0,0,0);
    adjacentPixels[7].SetValues(pos.x()-1,pos.y()-1,0,0,0);

    for(int i =0; i<8;i++){
        if(adjacentPixels[i].x<im->width()){
            uchar *pix = im->scanLine(adjacentPixels[i].y)+4*adjacentPixels[i].x;
            adjacentPixels[i].blue= pix[0];
            adjacentPixels[i].green = pix[1];
            adjacentPixels[i].red = pix[2];
        }
    }


}


