#include "qskatmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSkatMainWindow w;
    w.show();

    return a.exec();
}
