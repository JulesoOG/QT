#include "beziercreator.h"

BezierCreator::BezierCreator(QImage *image)
{
    im = image;
}

ActionPoint* BezierCreator::getActionPoint(QPoint pos)
{
    if(actionPoints.size()>0){
        for(int i = 0;i<(int)actionPoints.size(); i++){
            if(PixelMetrics::calculateDisntance(pos, actionPoints[i]->pos)<actionPoints[i]->radius){
                return actionPoints[i];
            }
        }
    }
    return NULL;
}

void BezierCreator::addActionPoint(QPoint pos){
    if(getActionPoint(pos)==NULL){
        actionPoints.push_back(new ActionPoint(pos,10,im));
        drawBeziers();
        //cout<<"dodaje punkcik"<<endl;
    }
}

void BezierCreator::moveActionPoint(QPoint pos){
    ActionPoint *pointToMove;
    pointToMove = getActionPoint(pos);
    if(pointToMove!=NULL){
        pointToMove->pos = pos;
        pointToMove->clean();
        pointToMove->drawActionPoint(pos,10);
        drawBeziers();
    }
}

void BezierCreator::removeActionPoint(QPoint pos){
    ActionPoint *pointToReomve;
    pointToReomve = getActionPoint(pos);
    if(pointToReomve!=NULL){
        for(int i=0; i<(int)actionPoints.size();i++)
        {
            if(actionPoints[i]->pos == pointToReomve->pos){
                delete actionPoints[i];
                actionPoints.erase(actionPoints.begin()+i);
                break;
            }
        }
        drawBeziers();
        //cout<<"usuwam punkcik"<<endl;
    }
}

void BezierCreator::drawBeziers()
{
    //cout<<"actionPoints.size() "<<actionPoints.size()<<endl;
    eraiseBeziers();
    if(actionPoints.size()>3)
    {
        Sketch* newSketch;
        for(int i=4; i<=(int)actionPoints.size(); i+=3){
            //cout<<actionPoints[0]->pos.x()<<", "<<actionPoints[0]->pos.x()<<", "<<actionPoints[0]->pos.x()<<", "<<actionPoints[0]->pos.x()<<", "<<endl;
            newSketch = new Bezier(20, actionPoints[i-4]->pos, actionPoints[i-3]->pos, actionPoints[i-2]->pos, actionPoints[i-1]->pos, im);
            //newSketch = new Bezier(20,actionPoints[0]->pos,actionPoints[1]->pos,actionPoints[0]->pos,actionPoints[1]->pos,im);
            bezierSketches.push_back(newSketch);
        }
    }
}

void BezierCreator::eraiseBeziers()
{
    //cout<<"usuwam bezeirki: "<< bezierSketches.size()<<endl;
    for(int i=0;i<(int)bezierSketches.size();i++){
        //delete bezierSketches[i];
        delete bezierSketches.back();
        bezierSketches.pop_back();
        redrawAll(actionPoints);
    }
}

void BezierCreator::redrawAll(vector<ActionPoint*> skeachesToRedraw)
{
    for(int i = 0;i<(int)skeachesToRedraw.size();i++){
        skeachesToRedraw[i]->clean();
        skeachesToRedraw[i]->drawActionPoint(skeachesToRedraw[i]->pos,10);
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
