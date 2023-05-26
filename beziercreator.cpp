#include "beziercreator.h"

BezierCreator::BezierCreator(QRgb colorRGB,QImage *image)
{
    curveColor = colorRGB;
    im = image;
}


void BezierCreator::drawCurves()
{
    //cout<<"actionPoints.size() "<<actionPoints.size()<<endl;
    eraiseCurves();
    if(actionPoints.size()>3)
    {
        Sketch* newSketch;
        for(int i=4; i<=(int)actionPoints.size(); i+=3){
            //cout<<actionPoints[0]->pos.x()<<", "<<actionPoints[0]->pos.x()<<", "<<actionPoints[0]->pos.x()<<", "<<actionPoints[0]->pos.x()<<", "<<endl;
            newSketch = new Bezier(20, actionPoints[i-4]->pos, actionPoints[i-3]->pos, actionPoints[i-2]->pos, actionPoints[i-1]->pos,curveColor, im);
            //newSketch = new Bezier(20,actionPoints[0]->pos,actionPoints[1]->pos,actionPoints[0]->pos,actionPoints[1]->pos,im);
            curvesSketches.push_back(newSketch);
        }
    }
}

/*
clickedPoints.push_back(e->pos());
cout<<clickedPoints.size()%4<<endl;
licznik++;
if(clickedPoints.size()>3 && licznik>2)
{
    cout<<clickedPoints[0].x()<<", "<<clickedPoints[1].x()<<", "<<clickedPoints[2].x()<<", "<<clickedPoints[3].x()<<", "<<endl;
    newSketch = new Bezier(20,clickedPoints[clickedPoints.size()-4], clickedPoints[clickedPoints.size()-3], clickedPoints[clickedPoints.size()-2], clickedPoints[clickedPoints.size()-1], &im2);
    im = im2;
    sketches.push_back(newSketch);
    update();
    licznik=0;
}
*/
