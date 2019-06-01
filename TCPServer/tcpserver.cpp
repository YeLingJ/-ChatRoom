#include "TcpServer.h"

TcpServer::TcpServer(QWidget *parent,Qt::WindowFlags f)
    : QWidget(parent,f)
{
    setWindowTitle(tr("TCP Server"));

    ContentListWidget = new QListWidget;

    PortLabel = new QLabel(tr("�˿ڣ�"));
    PortLineEdit = new QLineEdit;

    CreateBtn = new QPushButton(tr("����������"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(ContentListWidget,0,0,1,2);
    mainLayout->addWidget(PortLabel,1,0);
    mainLayout->addWidget(PortLineEdit,1,1);
    mainLayout->addWidget(CreateBtn,2,0,1,2);

    port=8010;
    PortLineEdit->setText(QString::number(port));

    connect(CreateBtn, SIGNAL(clicked()), this, SLOT(slotCreateServer()));
}

TcpServer::~TcpServer()
{

}

void TcpServer::slotCreateServer()
{
    server = new Server(this, port);

    //������ͻ��˷�������Ϣ���й㲥
    connect(server, SIGNAL(updateServer(QString, int)), this, SLOT(updateServer(QString, int)));

    CreateBtn->setEnabled(false);
}

void TcpServer::updateServer(QString msg, int length)
{
    //��������������ӿͻ��˷��͵���Ϣ
    ContentListWidget->addItem(msg.left(length));
}
