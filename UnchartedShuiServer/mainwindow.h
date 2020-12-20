#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QMessageBox>

class NetworkMod
{
public:
    void readMessage(void);
    void sendMessage(QString msg, QTcpSocket *socket);
    void processMessage(QString msg,QTcpSocket *socket);
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

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
};

#endif // MAINWINDOW_H
