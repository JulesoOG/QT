#include "drawer.h"
#include "bspline.h"

Drawer::Drawer(QWidget *parent) : QWidget{parent}
{
    im = QImage(720, 720, QImage::Format_RGB32);
    im.fill(0);
    im2 = QImage(720, 720, QImage::Format_RGB32);

    //s.drawPixel(10, 10,im, 255,255,255);
    setWindowTitle("Rysowanie pikseli w Qt");
    setMouseTracking(true);

    if(bezierCreator==NULL){
        bezierCreator = new BezierCreator(&im2);
    }
}
/*
Drawer::~Drawer()
{
    delete im;
    //std::cout<<"zdychaj"<<std::endl;
}
*/
void Drawer::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.fillRect(0,0, width(), height(), Qt::green);
    p.drawImage(0,0,im);
}

void Drawer::mousePressEvent(QMouseEvent *e){
    switch (menuMode)
    {
    case pixelSelected:

        break;
    case lineSelected:
        if (e->buttons() & Qt::LeftButton)
        {
            m_startPos = e->pos(); //ustawienie początkowej pozycji na miejsce naszego kursora
        }
        break;
    case shapeInCircleSelected:
        if (e->buttons() & Qt::LeftButton)
        {
            m_startPos = e->pos(); //ustawienie początkowej pozycji na miejsce naszego kursora
        }
        break;
    case bezierSelected:
        if (e->buttons() & Qt::LeftButton)
        {
            bezierCreator->addActionPoint(e->pos());
        }
        else if(e->buttons() & Qt::RightButton){
            bezierCreator->removeActionPoint(e->pos());
        }
        im=im2;
        update();
        break;
    default:
        break;
    }
}

void Drawer::mouseReleaseEvent(QMouseEvent *e){

    Sketch* newSketch;

    switch (menuMode)
    {
    case pixelSelected:

        break;
    case lineSelected:
        newSketch = new Line(m_startPos, m_endPos, &im2);
        im = im2;
        sketches.push_back(newSketch); //emplace_back
        //cout<<"sketches.emplace_back(*newSketch)"<<endl;
        update();
        break;
    case shapeInCircleSelected:
        newSketch = new ShapeInCircle(m_startPos, m_endPos, 360, &im2);
        im = im2;
        sketches.push_back(newSketch);
        update();
        break;
    case bezierSelected:


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
        break;
    case bSplineSelected:
        clickedPoints.push_back(e->pos());
        cout<<clickedPoints.size()%4<<endl;
        if(clickedPoints.size()>3)
        {
            cout<<clickedPoints[0].x()<<", "<<clickedPoints[1].x()<<", "<<clickedPoints[2].x()<<", "<<clickedPoints[3].x()<<", "<<endl;
            //newSketch = new BSpline
            newSketch = new BSpline(20,clickedPoints[clickedPoints.size()-4], clickedPoints[clickedPoints.size()-3], clickedPoints[clickedPoints.size()-2], clickedPoints[clickedPoints.size()-1], &im2);
            im = im2;
            sketches.push_back(newSketch);
            update();
        }
        break;
    }
}

void Drawer::mouseMoveEvent(QMouseEvent *e)
{
    switch (menuMode)
    {
    case pixelSelected:

        break;
    case lineSelected:
        if (e->buttons() & Qt::LeftButton) //reakcja na klikniecie lewego przycisku myszy
        {
            im=im2;
            m_endPos = e->pos(); //ustawienie koncowej pozycji na miejsce naszego kursora
            new Line(m_startPos, m_endPos, &im);
            update(); //odświeżenie widgetu
        }
        break;
    case shapeInCircleSelected:
        if (e->buttons() & Qt::LeftButton) //reakcja na klikniecie lewego przycisku myszy
        {
            im=im2;
            m_endPos = e->pos(); //ustawienie koncowej pozycji na miejsce naszego kursora
            new ShapeInCircle(m_startPos, m_endPos, 360, &im);
            update(); //odświeżenie widgetu
        }
        break;
    case bezierSelected:
        if (e->buttons() & Qt::LeftButton)
        {
            bezierCreator->moveActionPoint(e->pos());
            im=im2;
            update();
        }
        break;
    }

}

void Drawer::redrawAll(vector<Sketch*> skeachesToRedraw)
{
    for(int i = 0;i<(int)skeachesToRedraw.size();i++){
        skeachesToRedraw[i]->redraw();
    }
}

void Drawer::undoButton()
{
    delete sketches.back(); //usuwam obiekt
    sketches.pop_back(); //usuwam wskaznik na obiekt a nie sam obiekt bez powyzszej linjki nie wywola by sie destruktor
    cout<<sketches.size()<<endl;
    redrawAll(sketches);
    im = im2;
    update();
}

void Drawer::pixelButton()
{
    cout<<"wybrano pixel"<<endl;
    menuMode = pixelSelected;
}
void Drawer::lineButton()
{
    cout<<"wybrano linie"<<endl;
    menuMode = lineSelected;
}

void Drawer::circleButton()
{
    cout<<"wybrano circle"<<endl;
    menuMode = circleSelected;
}

void Drawer::floodFillButton()
{
    cout<<"wybrano flood fill"<<endl;
    menuMode = floodFillSelected;
}

void Drawer::shapeInCircleButton(){
    cout<<"wybrano ShapeInCircle"<<endl;
    menuMode = shapeInCircleSelected;
}
void Drawer::bezierButton()
{
    cout<<"wybrano bezier"<<endl;
    menuMode = bezierSelected;
}

void Drawer::bSplineButton()
{
    cout<<"wybrano b-Spline"<<endl;
    menuMode = bSplineSelected;
}


