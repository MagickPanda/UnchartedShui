#ifndef USSOCKETSERVER_H
#define USSOCKETSERVER_H

#include "usplatform.h"
#include "uslogger.h"
#include "usnetwork.h"

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

#endif // USSOCKETSERVER_H
