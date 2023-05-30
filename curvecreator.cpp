#include "curvecreator.h"

CurveCreator::CurveCreator()
{

}

ActionPoint* CurveCreator::getActionPoint(QPoint pos)
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

void CurveCreator::addActionPoint(QPoint pos){
    if(getActionPoint(pos)==NULL){
        actionPoints.push_back(new ActionPoint(pos,10,im));
        drawCurves();
        cout<<"dodaje punkcik"<<endl;
    }
}

void CurveCreator::moveActionPoint(QPoint pos){
    ActionPoint *pointToMove;
    pointToMove = getActionPoint(pos);
    if(pointToMove!=NULL){
        pointToMove->pos = pos;
        pointToMove->clean();
        pointToMove->drawActionPoint(pos,10);
        drawCurves();
    }
}

void CurveCreator::removeActionPoint(QPoint pos){
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
        drawCurves();
        //cout<<"usuwam punkcik"<<endl;
    }
}


void CurveCreator::eraiseCurves()
{
    //cout<<"usuwam bezeirki: "<< bezierSketches.size()<<endl;
    for(int i=0;i<(int)curvesSketches.size();i++){
        //delete bezierSketches[i];
        delete curvesSketches.back();
        curvesSketches.pop_back();
        redrawAll(actionPoints);
        //redrawAll(actionPoints);
    }
}

void CurveCreator::redrawAll(vector<ActionPoint*> skeachesToRedraw)
{
    for(int i = 0;i<(int)skeachesToRedraw.size();i++){
        skeachesToRedraw[i]->clean();
        skeachesToRedraw[i]->drawActionPoint(skeachesToRedraw[i]->pos,10);
    }
}

void CurveCreator::hidePoints(vector<ActionPoint*> polygonPoints)
{
    for(int i = 0;i<(int)polygonPoints.size();i++){
        polygonPoints[i]->clean();
    }
}
