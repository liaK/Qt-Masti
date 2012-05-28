#include <QtGui/QApplication>
#include "bridgewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CBridgeWidget w;
    w.show();
    
    return a.exec();
}
