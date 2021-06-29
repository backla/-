#include "calyh.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalYh w;
    w.show();
    w.setWindowTitle("CalThirdTeam");

    return a.exec();
}
