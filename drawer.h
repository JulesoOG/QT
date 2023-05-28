#ifndef DRAWER_H
#define DRAWER_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QColorDialog>

#include <iostream>

#include <vector>
#include <queue>
#include <list>

#include "sketch.h"
#include "line.h"
#include "circle.h"
#include "shapeincircle.h"
#include "bezier.h"
#include "bspline.h"
#include "actionpoint.h"
#include "beziercreator.h"
#include "bsplinecreator.h"
#include "floodfill.h"
#include "scanline.h"

using namespace std;


class Drawer : public QWidget
{
    Q_OBJECT
public:
    explicit Drawer(QWidget *parent = nullptr);
    //~Drawer();
    void redrawAll(vector<Sketch*> skeachesToRedraw);
    vector<Sketch*> sketches; //uzywam tablic wskaznikow aby nie kopiowac obiektow, w przeciwnym wypatku destrukto tych obiektow sie wykona
    QRgb brashColorRGB;
protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);


private slots:

private:
    enum MenuMode
    {
        pixelSelected,
        lineSelected,
        circleSelected,
        floodFillSelected,
        shapeInCircleSelected,
        bezierSelected,
        bSplineSelected,
        scanLineSelected
    };
    MenuMode menuMode;

    //std::queue<Sketch> sketches;
    QImage im, im2;
    QPoint m_startPos, m_endPos;

    vector<QPoint> clickedPoints;
    void createBezier();

    BezierCreator *bezierCreator;
    BSplineCreator *bSplineCreator;
    ScanLine *scanLine;

public slots:
    //guziki
    void undoButton();
    void colorButton();
    void pixelButton();
    void lineButton();
    void circleButton();
    void floodFillButton();
    void bezierButton();
    void shapeInCircleButton();
    void bSplineButton();
    void scanLineButton();
signals:

};

#endif // DRAWER_H


