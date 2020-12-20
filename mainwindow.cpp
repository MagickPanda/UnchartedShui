#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "openglwidget.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    OpenGLWidget* openGLWidget = new OpenGLWidget();
    //为了便于让OpenGLWidget自动填充父窗口，这里为父窗口设置了一个布局

    qint32 w, h;

    w = openGLWidget->getScreenW();
    h = openGLWidget->getScreenH();

    setMinimumSize(w, h);
    setMaximumSize(w, h);

    QVBoxLayout* centralLayout = new QVBoxLayout();
    centralLayout->addWidget(openGLWidget);
    this->ui->centralWidget->setLayout(centralLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
