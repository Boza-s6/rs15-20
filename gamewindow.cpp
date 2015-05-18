#include "gamewindow.h"
#include <QGraphicsRectItem>
#include <QVBoxLayout>
#include <QPixmap>
#include <QTimer>
#include "metak.h"
#include "bottank.h"

GameWindow::GameWindow( QWidget *parent)
    : QWidget(parent)
{

    auto * layout= new QVBoxLayout();
    layout->setMargin(0);
    this->setLayout(layout);

    view  = new QGraphicsView();
    scene = new QGraphicsScene(view);

    this->layout()->addWidget(view);
    view->setScene(scene);


    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap(":/img/bg_pattern.png"));
    //! [4] //! [5]
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    //! [5] //! [6]
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Fenix Tanks"));
    view->resize(400, 300);
    view->show();

    QPen olovka(Qt::white);
    olovka.setWidth(5);
    scene->addRect(0,0,1000,600, olovka);


    //butik je otvoren!!!

    //tanks.push_back(new Tank(Tank::Vrsta::PRVI, Tank::Orijentacija::GORE));
    Tank *tank = new Tank(Tank::Vrsta::PRVI, Tank::Orijentacija::GORE);
    scene->addItem(tank);
    tank->setFocus();

    // scene->addItem(new Metak(Metak::Orijentacija::GORE, QPoint(0,0))); //proba!!!!!

   scene->addItem(new BotTank( BotTank::Orijentacija::LEVO ));

//      scene->addItem(new BotTank(BotTank::Vrsta::BOT, BotTank::Orijentacija::DESNO ));
    mTimer = new QTimer(this);
    QObject::connect(mTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    mTimer->start(30);
}

GameWindow::~GameWindow()
{
    delete mTimer;
    delete scene;
    delete view;


}


