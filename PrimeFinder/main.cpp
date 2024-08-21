#include "primefindergui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PrimeFinderGUI w;
    w.show();
    return a.exec();
}
