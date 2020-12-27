#ifndef USSOCKETSERVER_H
#define USSOCKETSERVER_H

///TODO: move to config header
#define US_WIN32

///imports socket related stuff in WIN platform
#ifdef US_WIN32
    #pragma comment(lib,"ws2_32.lib")
    #pragma comment  (lib,"User32.lib")
    #pragma comment  (lib,"Gdi32.lib")
#endif

#include "include/qtnetworkng.h"
#include <iostream>
#include <QAbstractSocket>
#include <QObject>

#include "uslogger.h"

using namespace qtng;

static const qint32 US_PORT = 23323;

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

#endif // USSOCKETSERVER_H
