#ifndef DRAWER_H
#define DRAWER_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>
#include <vector>
#include <queue>
#include <iostream>
#include "sketch.h"
#include "line.h"
#include "shapeincircle.h"
#include "bezier.h"

using namespace std;


class Drawer : public QWidget
{
    Q_OBJECT
public:
    explicit Drawer(QWidget *parent = nullptr);
    //~Drawer();
    //void PaintEvent(QPaintEvent *);
    //void MouseMoveEvent(QMouseEvent *e);


    void drawPixel(int x, int y, int r, int g, int b);
    void drawShapeInCircle(int x1, int y1, int x2, int y2, int nKontow);

    //bool amIDrawing();
    queue<Sketch> sketches;

    //void drawLine(int x1,int y1,int x2,int y2);
protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private slots:

private:

    //std::queue<Sketch> sketches;
    QImage im, im2;
    QPoint m_startPos, m_endPos;

    vector<QPoint> clickedPoints;
public slots:
    void buttonTest();

signals:

};

#endif // DRAWER_H


