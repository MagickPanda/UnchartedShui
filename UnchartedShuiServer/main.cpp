#include "mainwindow.h"
#include <QApplication>

void handler(const std::error_code &ec)
{
  std::cout << "5 s." << std::endl;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    boost::asio::io_service io_service;
    boost::asio::deadline_timer timer(io_service, boost::posix_time::seconds(5));
    timer.async_wait(handler);
    io_service.run();

    return a.exec();
}
