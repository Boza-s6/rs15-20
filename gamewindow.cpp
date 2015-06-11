#include "gamewindow.h"
#include <QGraphicsRectItem>
#include <QVBoxLayout>
#include <QPixmap>
#include <QTimer>
#include "bullet.h"
#include "bottank.h"
#include "playertank.h"
#include "map.h"
#include <QString>
#include <QDir>

GameWindow::GameWindow( QWidget *parent)
    : QWidget(parent)
{

    auto * layout= new QVBoxLayout();
    layout->setMargin(0);
    this->setLayout(layout);

    view  = new QGraphicsView();
    scene = new QGraphicsScene(0, 0, 1000, 700, view);

    this->layout()->addWidget(view);
    view->setScene(scene);


    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap(":/img/img/bg_pattern.png"));
    //! [4] //! [5]
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    //! [5] //! [6]
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Fenix Tanks"));
    view->resize(1050, 750);
    view->show();

    QPen olovka(Qt::white);
    olovka.setWidth(5);
    //scene->addRect(0,0,1000,600, olovka);


    //butik je otvoren!!!


    Map::readMap(scene, "maps/first.map");


    BotTank *bot1 = new BotTank( 100,100, Tank::Orientation::DOWN);
    scene->addItem(bot1);

    BotTank *bot2 = new BotTank( 1000,0, Tank::Orientation::DOWN);
    scene->addItem(bot2);
    BotTank *bot3 = new BotTank( 1000,600, Tank::Orientation::UP);
    scene->addItem(bot3);
    BotTank *bot4 = new BotTank( 0,600, Tank::Orientation::UP);
    scene->addItem(bot4);


    PlayerTank *player = new PlayerTank( 500,300, Tank::Orientation::LEFT);
    player->setFocus();
    scene->addItem(player);

    /*
    Bullet *b=new Bullet(Tank::Orientation::LEFT, QPointF(0,0) );
    scene->addItem(b);
*/
    mTimer = new QTimer(this);
    QObject::connect(mTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    mTimer->start(30);

/*
    view->setFocus();
    scene->setFocus();
    scene->setFocusItem(player);*/

}

GameWindow::~GameWindow()
{
    delete mTimer;
    delete scene;
    delete view;
}


