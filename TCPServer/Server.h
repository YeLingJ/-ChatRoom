#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QObject>
#include "TcpClientSocket.h"

//TCP服务器，监听指定端口的TCP连接
class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent=0,int port=0);
    QList<TcpClientSocket*> tcpClientSocketList;
signals:
    void updateServer(QString,int);
public slots:
    void updateClients(QString,int);
    void slotDisconnected(int);
protected:
    void incomingConnection(int socketDescriptor);
};

#endif // SERVER_H
