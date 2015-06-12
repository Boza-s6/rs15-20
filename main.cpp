#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QtMultimedia>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    QIcon icon(":/img/img/tank_icon.png");
    window.setWindowIcon(icon);

    window.showMaximized();//U test rezimu, da imam x za izlazak
    //window.showFullScreen();


    window.show();

    //Pustanje pozadinske muzike
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sounds/igraj.mp3"));  //QUrl("qrc:/sounds/sounds/igraj.mp3") - za motivaciju xD
    music->play();

    return a.exec();
}
