#include "ussocketserver.h"

UsSocketServer::UsSocketServer()
{
    USLOG("server created.\n");
    mSocket.bind(US_PORT);
    mSocket.listen(100);
}
