#include "line.h"

Line::Line(QPoint startPos, QPoint endPos, QImage *image)
{
    std::cout<<"Line"<<std::endl;
    im = image;
    drawLine(startPos.x(), startPos.y(), endPos.x(), endPos.y());
}

Line::Line(){

}
void Line::drawLine(int x1,int y1,int x2,int y2)
{
    int x, y;
    if(abs(y2-y1) <= abs(x2-x1))
    {

        //Pojawienie sie problemu z rysowaniem linii w z prawej do lewej czyli zmniejszanie wartościssss
        //aby to zrobić należało zmienić kolejność aby uzyskiwac poprawne wartości co gwarantuje nam podany warunek

        if (x1 > x2)
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        for(x=x1; x<x2; x++)
        {
            y=y1+(x-x1)*(y2-y1)/(x2-x1);
            drawPixel(*(new Pixel(x, y, 200, 200, 200)));
        }
    }
    else
    {

         //Pojawienie sie problemu z rysowaniem linii w z góry na dół czyli zmniejszanie wartości
         //aby to zrobić należało zmienić kolejność aby uzyskiwac poprawne wartości co gwarantuje nam podany warunek

        if (y1 > y2)
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        for(y=y1; y<y2; y++)
        {
            x=x1+(y-y1)*(x2-x1)/(y2-y1);
            drawPixel(*(new Pixel(x, y, 200, 200, 200)));
        }
    }
}


