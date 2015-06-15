#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    QIcon icon(":/img/img/tank_icon.png");
    window.setWindowIcon(icon);

    window.showMaximized();//U test rezimu, da imam x za izlazak
//    window.showFullScreen();


//    window.show();


    return a.exec();
}
