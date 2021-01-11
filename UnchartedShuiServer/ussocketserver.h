#ifndef USSOCKETSERVER_H
#define USSOCKETSERVER_H

#include "usplatform.h"
#include "uslogger.h"
#include "usnetwork.h"

static const qint32 US_MAX_CLIENTS = 32;

class UsSocketServer : public QObject
{
public:
    UsSocketServer();



    virtual void serverStart();
    virtual void serverRun();

    virtual void newConnection();

    virtual void sendMsgToClient(QString msg,QTcpSocket *target);
    virtual void broadcastMsg(QString msg);
public:
    QSharedPointer<QTcpSocket> mClientSockets[US_MAX_CLIENTS];
private:
    bool bClientInUse[US_MAX_CLIENTS];

    QSharedPointer<QTcpSocket> mTcpSocket;
    QSharedPointer<QTcpServer> mTcpServer;

    friend class MainWindow;
};

#ifdef US_NETWORK_NG
using namespace qtng;

class UsSocketServer : public QObject
{
public:
    UsSocketServer();

    void start()
    {
        USLOG("server starting...\n");
        this->run();
    }
    void run()
    {
        while (true)
        {
            QSharedPointer<Socket> request(mSocket.accept());
            if (request.isNull())
            {
                break;
            }
            mOperations.spawn([request] {
                request->sendall("hello!");
                request->close();
            });
        }
    }

private:
    Socket mSocket;
    CoroutineGroup mOperations;

};
#endif

#endif // USSOCKETSERVER_H
