#include "gamewindow.h"
#include <QLayout>
#include "map.h"
#include "bottank.h"
#include "playertank.h"
#include <QTimer>

GameWindow::GameWindow( QWidget *parent)
    : QWidget(parent), mTimer(),
      mView(new QGraphicsView),
      mScene(new QGraphicsScene(0, 0, SCENE_WIDTH, SCENE_HEIGHT, mView))
{

    auto layout= new QVBoxLayout();
    layout->setMargin(0);
    this->setLayout(layout);

    this->layout()->addWidget(mView);
    mView->setScene(mScene);




    mView->setRenderHint(QPainter::Antialiasing);
    mView->setBackgroundBrush(QPixmap(":/img/img/bg_pattern.png"));

    mView->setCacheMode(QGraphicsView::CacheBackground);
    mView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    mView->setDragMode(QGraphicsView::ScrollHandDrag);

    mView->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Fenix Tanks"));
    mView->resize(1050, 750);
    mView->show();

    init();
    //butik je otvoren!!!

    Map::readMap(mScene, "maps/first.map");

    QObject::connect(&mTimer, SIGNAL(timeout()), mScene, SLOT(advance()));
    mTimer.start(30);

    mView->setFocus();

}


GameWindow::~GameWindow()
{
    delete mScene;
    delete mView;
}

void GameWindow::init()
{
    BotTank *bot1 = new BotTank( 100,100, Tank::Orientation::DOWN);
    mScene->addItem(bot1);

    BotTank *bot2 = new BotTank( 700, 0, Tank::Orientation::DOWN);
    mScene->addItem(bot2);
    BotTank *bot3 = new BotTank( 70, 600, Tank::Orientation::UP);
    mScene->addItem(bot3);
    BotTank *bot4 = new BotTank( 50, 600, Tank::Orientation::UP);
    mScene->addItem(bot4);

    PlayerTank *player = new PlayerTank( 500,300, Tank::Orientation::LEFT, PlayerTank::Player::Player1);
    player->setFocus();
    mScene->addItem(player);
}


