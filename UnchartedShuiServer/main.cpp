#include "mainwindow.h"
#include <QApplication>
#include "uslogger.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    UsLogger &logger = UsLogger::getSingleton();

    //Log4Qt::PropertyConfigurator::configure(a.applicationDirPath() + "/log4qt.conf");
    logger.init();


    USLOG("meow!!\n");

    UsSocketServer server;

    server.start();

    return a.exec();
}
