#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>
#include "counter.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();

    QApplication app(argc, argv);
    QLabel lbl("0");
    QPushButton cmd("Add");
    Counter counter;

    lbl.show();
    cmd.show();

    QObject::connect(&cmd, SIGNAL(clicked()), &counter, SLOT(slotInc()));

    QObject::connect(&counter, SIGNAL(counerChanged(int)), &lbl, SLOT(setNum(int)));
    QObject::connect(&counter, SIGNAL(goodbye()), &app, SLOT(quit()));



    return app.exec();
}
