#include "Server.h"

Server::Server(QObject *parent,int port)
    :QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
}

//����һ���µ�����ʱ����
void Server::incomingConnection(int socketDescriptor)
{
    TcpClientSocket *tcpClientSocket = new TcpClientSocket(this);
    connect(tcpClientSocket, SIGNAL(updateClients(QString,int)), this, SLOT(updateClients(QString,int)));
    connect(tcpClientSocket, SIGNAL(disconnected(int)), this, SLOT(slotDisconnected(int)));

    tcpClientSocket->setSocketDescriptor(socketDescriptor);

    //�������ӵĿͻ��˼��뵽 �ͻ��˵�������
    tcpClientSocketList.append(tcpClientSocket);
}

//������ͻ��˷�������Ϣ���й㲥
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

//���Ͽ����ӵ�TcpSocket����ɾ��
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
