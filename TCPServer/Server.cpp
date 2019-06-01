#include "Server.h"

Server::Server(QObject *parent,int port)
    :QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
}

//出现一个新的连接时触发
void Server::incomingConnection(int socketDescriptor)
{
    TcpClientSocket *tcpClientSocket = new TcpClientSocket(this);
    connect(tcpClientSocket, SIGNAL(updateClients(QString,int)), this, SLOT(updateClients(QString,int)));
    connect(tcpClientSocket, SIGNAL(disconnected(int)), this, SLOT(slotDisconnected(int)));

    tcpClientSocket->setSocketDescriptor(socketDescriptor);

    //把新连接的客户端加入到 客户端的链表中
    tcpClientSocketList.append(tcpClientSocket);
}

//将任意客户端发来的信息进行广播
void Server::updateClients(QString msg,int length)
{
    emit updateServer(msg,length);
    for(int i=0; i<tcpClientSocketList.count(); i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->write(msg.toLatin1(),length) != length)
        {
            continue;
        }
    }
}

//将断开连接的TcpSocket对象删除
void Server::slotDisconnected(int descriptor)
{
    for(int i=0;i<tcpClientSocketList.count();i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->socketDescriptor()==descriptor)
        {
            tcpClientSocketList.removeAt(i);
            return;
        }
    }
    return;
}
