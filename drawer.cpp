#include "drawer.h"
#include "bspline.h"

Drawer::Drawer(QWidget *parent) : QWidget{parent}
{
    brashColorRGB = qRgb(255,255,255);

    im = QImage(720, 720, QImage::Format_RGB32);
    im.fill(0);
    im2 = QImage(720, 720, QImage::Format_RGB32);

    setWindowTitle("Rysowanie pikseli w Qt");
    setMouseTracking(true);

    scanLine = new ScanLine(&im2);
    colorSpaces = new ColorSpaces(&im2);

    //new ShapeInCircle(QPoint(10,10),QPoint(150,150), 16,brashColorRGB,&im);
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
        if (e->buttons() & Qt::LeftButton)
        {
            cout<<"x = "<<e->pos().x()<<"y = "<<e->pos().y()<<endl;
        }
        break;
    case lineSelected:
        if (e->buttons() & Qt::LeftButton)
        {
            m_startPos = e->pos();
        }
        break;
    case circleSelected:
        if (e->buttons() & Qt::LeftButton)
        {
            m_startPos = e->pos();
        }
        break;
    case shapeInCircleSelected:
        if (e->buttons() & Qt::LeftButton)
        {
            m_startPos = e->pos();
        }
        break;
    case bezierSelected:
        if(bezierCreator==NULL){
            bezierCreator = new BezierCreator(brashColorRGB,&im2);
        }
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
    case bSplineSelected:        
        if(bSplineCreator==NULL){
            bSplineCreator = new BSplineCreator(brashColorRGB,&im2);
        }

        if (e->buttons() & Qt::LeftButton)
        {
            bSplineCreator->addActionPoint(e->pos());
        }
        else if(e->buttons() & Qt::RightButton){
            bSplineCreator->removeActionPoint(e->pos());
        }
        im=im2;
        update();
        break;
    case floodFillSelected:
        if (e->buttons() & Qt::LeftButton)
        {
            sketches.push_back(new FloodFill(e->pos(),brashColorRGB, im.pixel(e->pos().x(),e->pos().y()) ,&im2));
            im=im2;
            update();
        }
        break;
    case scanLineSelected:
        if (e->buttons() & Qt::LeftButton)
        {

            //cout<<scanLine->actionPoints.size()<<endl;
            scanLine->addActionPoint(e->pos());
        }
        else if(e->buttons() & Qt::RightButton){
            //scanLine->drawScanLine(brashColorRGB);
            //sketches.push_back(scanLine->drawScanLine(brashColorRGB));
            scanLine->drawScanLine(brashColorRGB);
            sketches.push_back(scanLine);
            scanLine = new ScanLine(&im2);
        }
        im=im2;
        update();
        break;
    default:
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
            new Line(m_startPos, m_endPos,brashColorRGB, &im);
            update(); //odświeżenie widgetu
        }
        break;
    case circleSelected:

        if (e->buttons() & Qt::LeftButton) //reakcja na klikniecie lewego przycisku myszy
        {
            im=im2;
            m_endPos = e->pos(); //ustawienie koncowej pozycji na miejsce naszego kursora
            new Circle(m_startPos, m_endPos,brashColorRGB, &im);
            update(); //odświeżenie widgetu
        }
        break;
    case shapeInCircleSelected:

        if (e->buttons() & Qt::LeftButton) //reakcja na klikniecie lewego przycisku myszy
        {
            //im=im2;
            m_endPos = e->pos(); //ustawienie koncowej pozycji na miejsce naszego kursora
            //new ShapeInCircle(m_startPos, m_endPos, 360,brashColorRGB, &im);
            //update(); //odświeżenie widgetu
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
    case bSplineSelected:
        if (e->buttons() & Qt::LeftButton)
        {
            bSplineCreator->moveActionPoint(e->pos());
            im=im2;
            update();
        }
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
        newSketch = new Line(m_startPos, m_endPos,brashColorRGB,&im2);
        im = im2;
        sketches.push_back(newSketch); //emplace_back
        //cout<<"sketches.emplace_back(*newSketch)"<<endl;
        update();
        break;
    case circleSelected:

        newSketch = new Circle(m_startPos, m_endPos,brashColorRGB, &im2);
        im = im2;
        sketches.push_back(newSketch);
        update();

        break;
    case shapeInCircleSelected:
        m_endPos=e->pos();
        newSketch = new ShapeInCircle(m_startPos, m_endPos, 6, brashColorRGB, &im2);
        im = im2;
        sketches.push_back(newSketch);
        update();

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
    if(sketches.size()>0)
    {
        /*
        if (sketches.back() == nullptr) {
              std::cout << "Wskaznik jest pusty (NULL)." << std::endl;
        }
        else {
            std::cout << "Wskaznik nie jest pusty." << std::endl;
        }
        */
        delete sketches.back(); //usuwam obiekt
        sketches.pop_back(); //usuwam wskaznik na obiekt a nie sam obiekt bez powyzszej linjki nie wywola by sie destruktor
        redrawAll(sketches);
        im = im2;
        update();
    }
}

void Drawer::colorButton()
{
    cout<<"wybrano kolor"<<endl;
    brashColorRGB=(QColorDialog::getColor(Qt::white, this, "Choose Color")).rgb();
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

void Drawer::scanLineButton(){
    cout<<"wybrano scan line"<<endl;
    menuMode = scanLineSelected;
}


void Drawer::redSlider(int n){
    cout<<"R: "<<n<<endl;
    colorSpaces->RGBSpace(n,0,0);
    im=im2;
    update();
}

void Drawer::greenSlider(int n){
    cout<<"G: "<<n<<endl;
    colorSpaces->RGBSpace(0,n,0);
    im=im2;
    update();
}
void Drawer::blueSlider(int n){
    cout<<"B: "<<n<<endl;
    colorSpaces->RGBSpace(0,0,n);
    im=im2;
    update();
}

void Drawer::hueSlider(int n){
    //cout<<"H: "<<n<<endl;
    colorSpaces->HSVSpace(n,0,0);
    im=im2;
    update();
}
void Drawer::saturationSlider(int n){
    //cout<<"S: "<<n<<endl;
    colorSpaces->HSVSpace(0,n,0);
    im=im2;
    update();
}

void Drawer::valueSlider(int n){
    //cout<<"V: "<<n<<endl;
    colorSpaces->HSVSpace(0,0,n);
    im=im2;
    update();
}
