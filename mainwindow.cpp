#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->PBTest,SIGNAL(clicked()),ui->widget,SLOT(buttonTest()));
    ui->PBTest->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \
                           QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

