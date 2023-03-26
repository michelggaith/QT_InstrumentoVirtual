#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w2;

    w2.setGeometry(200,200,550,520); //Tamaño VI original
    w2.show();

    return a.exec();
}
