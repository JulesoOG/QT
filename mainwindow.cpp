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

    connect(ui->ScanLineButton,SIGNAL(clicked()),ui->widget,SLOT(scanLineButton()));
    ui->ScanLineButton->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    //RGBSpace
    connect(ui->RedSlider,SIGNAL(valueChanged(int)),ui->widget,SLOT(redSlider(int)));
    ui->RedSlider->setRange(0,255);
    connect(ui->GreenSlider,SIGNAL(valueChanged(int)),ui->widget,SLOT(greenSlider(int)));
    ui->GreenSlider->setRange(0,255);
    connect(ui->BlueSlider,SIGNAL(valueChanged(int)),ui->widget,SLOT(blueSlider(int)));
    ui->BlueSlider->setRange(0,255);
    //HSVSpace
    connect(ui->HueSlider,SIGNAL(valueChanged(int)),ui->widget,SLOT(hueSlider(int)));
    ui->HueSlider->setRange(0,255);
    connect(ui->SaturationSlider,SIGNAL(valueChanged(int)),ui->widget,SLOT(saturationSlide(int)));
    ui->SaturationSlider->setRange(0,255);
    connect(ui->ValueSlider,SIGNAL(valueChanged(int)),ui->widget,SLOT(valueSlider(int)));
    ui->ValueSlider->setRange(0,255);
}

MainWindow::~MainWindow()
{
    delete ui;
}

