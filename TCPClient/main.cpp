#include <QtGui/QApplication>
#include "TcpClient.h"
#include <QTextCodec> //����
int main(int argc, char *argv[])
{
    //���ñ��ر��� ͷ�ļ� #include <QTextCodec> //����
    QTextCodec *codec = QTextCodec::codecForLocale();
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    QApplication a(argc, argv);
    TcpClient w;
    w.show();

    return a.exec();
}
