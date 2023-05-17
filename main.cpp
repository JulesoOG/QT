#include "mainwindow.h"
#include "drawer.h"
#include "sketch.h"



#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Drawer drawer;
    //drawer.DrawPixel(100,100,255,255,255);
    //drawer.PaintEvent()
    //drawer.show();

    return a.exec();
}
