#include "mainwindow.h"
#include <QApplication>
#include "Opening.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Opening *w= new Opening;
    w->show();

    return a.exec();
}
