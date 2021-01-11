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

class MainWindow : public QMainWindow, UsSocketServer
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ///server initialization
    void serverStart();
    ///server logic loop
    void serverRun();
    ///On new connection callback function
    void serverNewConnection();
    ///Function to send message to a single socket client
    void sendMsgToClient(QString msg, QTcpSocket *target);
    ///Broadcast message to all connected clients
    void broadcastMsg(QString msg);

private:
    Ui::MainWindow *ui;

    UsSocketServer *socketServer;
};

#endif // MAINWINDOW_H
