#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QMessageBox>

#include "ussocketserver.h"

using namespace qtng;

class NetworkMod
{
public:
    void readMessage(void);
    void sendMessage(QString msg, Socket *socket);
    void processMessage(QString msg, Socket *socket);
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, private NetworkMod
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    UsSocketServer *socketServer;
};

#endif // MAINWINDOW_H
