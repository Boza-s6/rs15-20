#include "gamewindow.h"
#include <QGraphicsRectItem>
#include <QVBoxLayout>
#include <QPixmap>


GameWindow::GameWindow( QWidget *parent)
    : QWidget(parent)
{
    auto * layout= new QVBoxLayout();
    layout->setMargin(0);
    this->setLayout(layout);

    view  = new QGraphicsView();
    scene = new QGraphicsScene();

    this->layout()->addWidget(view);
    view->setScene(scene);

    QBrush tenkBrush(Qt::green);
    QPen outlinePen(Qt::black);

    auto pm = QPixmap(":/img/tank_icon.png");
    tenkBrush.setTexture(pm);

//auto * rectangle = scene->addRect(0,0, 100, 100, QPen(), tenkBrush);
for(int i=0; i<numberOfFields; i++){
    for(int j=0; j<numberOfFields; j++){
        auto tmp = scene->addPixmap(pm);
        tmp->setScale(2);
        tmp->setPos(50*i, 50*j);
    }
}



}

GameWindow::~GameWindow()
{

}


