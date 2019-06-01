#include <QtGui/QApplication>
#include "TcpClient.h"
#include <QTextCodec> //编码
int main(int argc, char *argv[])
{
    //设置本地编码 头文件 #include <QTextCodec> //编码
    QTextCodec *codec = QTextCodec::codecForLocale();
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    QApplication a(argc, argv);
    TcpClient w;
    w.show();

    return a.exec();
}
