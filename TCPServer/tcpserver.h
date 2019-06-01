#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include "Server.h"
#include <QWidget>
class TcpServer : public QWidget
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = 0,Qt::WindowFlags f=0);
    ~TcpServer();
private:
    QListWidget *ContentListWidget;
    QLabel *PortLabel;
    QLineEdit *PortLineEdit;
    QPushButton *CreateBtn;
    QGridLayout *mainLayout;
    int port;
    Server *server;
public slots:
    void slotCreateServer();
    void updateServer(QString,int);  //更新服务器上的信息显示
};

#endif // TCPSERVER_H
