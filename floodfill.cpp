#include "floodfill.h"

FloodFill::FloodFill(QPoint pos, QRgb fillColor, QRgb backgroundColor, QImage *image)
{
    im = image;
    drawFloodFill(pos,fillColor,backgroundColor);
}

void FloodFill::drawFloodFill(QPoint pos, QRgb fillColor, QRgb backgroundColor)
{
    int x,y;

    if(fillColor==backgroundColor) return;
    pixelPosStack.push(pos);
    while(!pixelPosStack.empty())
    {
        x=pixelPosStack.top().x();
        y=pixelPosStack.top().y();

        pixelPosStack.pop();

        if(im->pixel(x,y)==backgroundColor){
            drawPixel(Pixel(x,y,fillColor));
            if(y>=0&&y<im->height())
            {
                if(x+1>=0 && x+1<im->width()){
                    pixelPosStack.push(QPoint(x+1,y));
                }

                if(x-1>=0 && x-1<im->width()){
                    pixelPosStack.push(QPoint(x-1,y));
                }
            }
            if(x>=0&&x<im->width())
            {
                if(y+1>=0 && y+1<im->height()){
                    pixelPosStack.push(QPoint(x,y+1));
                }

                if(y-1>=0 && y-1<im->height()){
                    pixelPosStack.push(QPoint(x,y-1));
                }
            }
        }
    }
}

/*
void FloodFill::drawFloodFill(x,y,zamieniany_kolor,nowy_kolor)
{
    if (kolor(x,y) == zamieniany_kolor)
    {
        ustaw_kolor(x,y, nowy_kolor);
        flood_fill(x-1,y,zamieniany_kolor,nowy_kolor);
        flood_fill(x+1,y,zamieniany_kolor,nowy_kolor);
        flood_fill(x,y+1,zamieniany_kolor,nowy_kolor);
        flood_fill(x,y-1,zamieniany_kolor,nowy_kolor);
    }
    else return;

}
*/
