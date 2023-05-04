
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->botonn,SIGNAL(clicked()),this,SLOT(prueba()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::prueba()
{
    ui->botonn->setText("asdfgl");
}

