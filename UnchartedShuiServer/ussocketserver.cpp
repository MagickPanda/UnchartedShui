#include "ussocketserver.h"

UsSocketServer::UsSocketServer()
{
    qint32 i;
    for (i = 0; i < US_MAX_CLIENTS; i++)
    {
        mClientSockets[i] = nullptr;
        bClientInUse[i] = false;
    }

    mTcpServer = QSharedPointer<QTcpServer>( new QTcpServer(this) );

    mTcpServer->listen(QHostAddress::Any,8888);

    //建立新连接触发槽函数
    connect(tcpServer,&QTcpServer::newConnection,
            this,&Widget::newconnection);

}

#ifdef US_NETWORK_NG
UsSocketServer::UsSocketServer()
{

    USLOG("server created.\n");
    mSocket.bind(US_PORT);
    mSocket.listen(100);

    mSocket.
}
#endif
