#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    QIcon icon("C:/Users/lenovo/Desktop/FenixTanks/img/tank_icon.png");
    window.setWindowIcon(icon);

    window.showMaximized();
    //window.show();



    return a.exec();
}
