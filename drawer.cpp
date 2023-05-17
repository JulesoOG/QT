#include "drawer.h"

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

void Drawer::buttonTest(){
    cout<<"klikasz guzik dziwko"<<endl;
}

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
        sketches.push(*newSketch);
        update();
}

void Drawer::mouseMoveEvent(QMouseEvent *e)
{

    if (e->buttons() & Qt::LeftButton) //reakcja na klikniecie lewego przycisku myszy
    {
        im=im2;
        m_endPos = e->pos(); //ustawienie koncowej pozycji na miejsce naszego kursora
        new Line(m_startPos, m_endPos, &im);
        update(); //odświeżenie widgetu
    }

}
*/
