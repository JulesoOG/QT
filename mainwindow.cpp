#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Podpiecie guzikow z formularza
    connect(ui->UndoButton,SIGNAL(clicked()),ui->widget,SLOT(undoButton()));
    ui->UndoButton->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    connect(ui->ColorButton,SIGNAL(clicked()),ui->widget,SLOT(colorButton()));
    ui->ColorButton->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    connect(ui->PixelButton,SIGNAL(clicked()),ui->widget,SLOT(pixelButton()));
    ui->PixelButton->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    connect(ui->LineButton,SIGNAL(clicked()),ui->widget,SLOT(lineButton()));
    ui->LineButton->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    connect(ui->CircleButton,SIGNAL(clicked()),ui->widget,SLOT(circleButton()));
    ui->CircleButton->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    connect(ui->FloodFillButton,SIGNAL(clicked()),ui->widget,SLOT(floodFillButton()));
    ui->FloodFillButton->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    connect(ui->ShapeInCircleButton,SIGNAL(clicked()),ui->widget,SLOT(shapeInCircleButton()));
    ui->ShapeInCircleButton->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    connect(ui->BezierButton,SIGNAL(clicked()),ui->widget,SLOT(bezierButton()));
    ui->BezierButton->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    connect(ui->BSplineButton,SIGNAL(clicked()),ui->widget,SLOT(bSplineButton()));
    ui->BSplineButton->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

}

MainWindow::~MainWindow()
{
    delete ui;
}

