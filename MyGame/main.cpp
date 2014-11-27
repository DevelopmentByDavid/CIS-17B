#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QPixmap image(":/splash.png");
    QLabel* aWidget = new QLabel(0, Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    aWidget->setAttribute(Qt::WA_TranslucentBackground);
    aWidget->setPixmap(image);
    int width = image.width();
    int height = image.height();

    QDesktopWidget wid;
    QRect mainScreenSize = wid.availableGeometry(wid.primaryScreen());

    aWidget->move((mainScreenSize.width()/2)-(width/2), (mainScreenSize.height()/2)-(height/2));
    aWidget->show();
    QTimer::singleShot(5000, aWidget,SLOT(close()));
    QTimer::singleShot(5000, &w,SLOT(show()));

    //w.show();

    return a.exec();
}