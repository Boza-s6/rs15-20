#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    QIcon icon("img/tank_icon.png");
    window.setWindowIcon(icon);

    window.showFullScreen();

    return a.exec();
}
