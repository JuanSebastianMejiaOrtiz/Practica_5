
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    nivel = new game;

    nivel->setSceneRect(0, 0, ui->Vista_Juego->width()-2, ui->Vista_Juego->height()-2);

    ui->Vista_Juego->setScene(nivel);

    connect(ui->Reset, SIGNAL(clicked(bool)), this, SLOT(Reset_Game()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete nivel;
}

void MainWindow::Reset_Game()
{
    ui->Reset->setText("Reset");

    delete nivel;

    nivel = new game;

    nivel->setSceneRect(0, 0, ui->Vista_Juego->width()-2, ui->Vista_Juego->height()-2);

    ui->Vista_Juego->setScene(nivel);
}

