#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::serverStart()
{
    USLOG("server starting...\n");
    serverRun();
}
void MainWindow::serverRun()
{
    while (true)
    {

    }
}
