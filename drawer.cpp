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

}
/*e
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

/*
void Drawer::mousePressEvent(QMouseEvent *e){
    clickedPoints.push_back(e->pos());

    if(clickedPoints.size()>3){
        cout<<clickedPoints[0].x()<<", "<<clickedPoints[1].x()<<", "<<clickedPoints[2].x()<<", "<<clickedPoints[3].x()<<", "<<endl;
        new Bezier(20,clickedPoints[0], clickedPoints[1], clickedPoints[2], clickedPoints[3], &im);
        //new Bezier(20,clickedPoints);
        //cout<<"moge rysowac bezjera"<<endl;
        update();
    }
}
//nie wazne ktory przycisk myszy puszcze i tak sie wykona
void Drawer::mouseReleaseEvent(QMouseEvent *e){


}

void Drawer::mouseMoveEvent(QMouseEvent *e)
{



}
*/

//Linia i kolo
/*
void Drawer::mousePressEvent(QMouseEvent *e){
    if (e->buttons() & Qt::LeftButton){
        m_startPos = e->pos(); //ustawienie początkowej pozycji na miejsce naszego kursora
    }
}

void Drawer::mouseReleaseEvent(QMouseEvent *e){

        Sketch *newSketch = NULL;
        //m_endPos = e->pos(); //ustawienie koncowej pozycji na miejsce naszego kursora
        newSketch = new Line(m_startPos, m_endPos, &im2);
        //newSketch = new ShapeInCircle(m_startPos, m_endPos, 360, &im);
        im = im2;

        sketches.push_back(*newSketch);
        cout<<sketches.size()<<endl;
        update();
}

void Drawer::mouseMoveEvent(QMouseEvent *e)
{

    if (e->buttons() & Qt::LeftButton) //reakcja na klikniecie lewego przycisku myszy
    {
        im=im2;
        m_endPos = e->pos(); //ustawienie koncowej pozycji na miejsce naszego kursora
        //new Line(m_startPos, m_endPos, &im);
        update(); //odświeżenie widgetu
    }

}
*/


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
        sketches.emplace_back(newSketch);
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
        clickedPoints.push_back(e->pos());
        cout<<clickedPoints.size()%4<<endl;
        if(clickedPoints.size()>3)
        {
            cout<<clickedPoints[0].x()<<", "<<clickedPoints[1].x()<<", "<<clickedPoints[2].x()<<", "<<clickedPoints[3].x()<<", "<<endl;
            newSketch = new Bezier(20,clickedPoints[clickedPoints.size()-4], clickedPoints[clickedPoints.size()-3], clickedPoints[clickedPoints.size()-2], clickedPoints[clickedPoints.size()-1], &im2);
            im = im2;
            sketches.push_back(newSketch);
            update();
        }
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

void Drawer::lineButton()
{
    cout<<"wybrano linie"<<endl;
    menuMode = lineSelected;
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


