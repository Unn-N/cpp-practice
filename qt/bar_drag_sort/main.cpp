#include <QApplication>
#include "sortwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SortWidget w;
    w.setWindowTitle("Qt 复刻 SwapJS Speedrun");
    w.show();

    return a.exec();
}