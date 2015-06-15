#include "gamewindow.h"
#include <QLayout>
#include "map.h"
#include "bottank.h"
#include "playertank.h"
#include <QTimer>
#include <QtMultimedia>

GameWindow::GameWindow( QWidget *parent)
    : QWidget(parent), mTimer(),
      mView(new QGraphicsView),
      mScene(new QGraphicsScene(0, 0, SCENE_WIDTH, SCENE_HEIGHT, mView)),
      mText(),
      mBotReserve(NUM_OF_BOTS)
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

    //first, second, third, fourth - imena fajlova
    mFenix = Map::readMap(mScene, "maps/fourth.map");

    QObject::connect(&mTimer, SIGNAL(timeout()), mScene, SLOT(advance()));
    mTimer.start(30);

    mView->setFocus();

    //Pustanje pozadinske muzike
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sounds/igraj.mp3"));  //QUrl("qrc:/sounds/sounds/igraj.mp3") - za motivaciju xD
    music->play();

}


GameWindow::~GameWindow()
{
    delete mScene;
    delete mView;
}

void GameWindow::mPlayerTankHealthChanged(int health)
{
    // Ispisujemo helte playera
    mText.setPlainText(QString("Health: ") + QString::number(health));
}

void GameWindow::playerKilled()
{
    // std::cout<<"mrtva si kokosko"<<std::endl;
    emit notifyPlayerKilled();
}

void GameWindow::mbotKilled()
{
    mBotReserve--;
    std::cout<<mBotReserve<< std::endl;

    if(mBotReserve>0){
        BotTank *bt1 = new BotTank( 500,500, Tank::Orientation::DOWN);

        mPlayer->setFocus();
        mScene->setFocusItem(mPlayer);
        mScene->addItem(bt1);

        QObject::connect(bt1, SIGNAL(botKilled()), this, SLOT(mbotKilled()));
    }

}

void GameWindow::init()
{
    BotTank *bot1 = new BotTank( 100,100, Tank::Orientation::DOWN);
    mScene->addItem(bot1);
    QObject::connect(bot1, SIGNAL(botKilled()), this, SLOT(mbotKilled()));

    BotTank *bot2 = new BotTank( 700, 80, Tank::Orientation::DOWN);
    mScene->addItem(bot2);
    QObject::connect(bot2, SIGNAL(botKilled()), this, SLOT(mbotKilled()));

    BotTank *bot3 = new BotTank( 70, 600, Tank::Orientation::UP);
    mScene->addItem(bot3);
    QObject::connect(bot3, SIGNAL(botKilled()), this, SLOT(mbotKilled()));

    BotTank *bot4 = new BotTank( 50, 600, Tank::Orientation::UP);
    mScene->addItem(bot4);
    QObject::connect(bot4, SIGNAL(botKilled()), this, SLOT(mbotKilled()));



    mScene->addItem(&mText);
    mText.setPos(1010,100);
    mText.setPlainText(QString("Health: ") + QString::number(TANK_HEALTH));
    mText.setDefaultTextColor(Qt::red);
    mText.setFont(QFont("times",16));

    mPlayer = new PlayerTank( 500,400, Tank::Orientation::LEFT, PlayerTank::Player::Player1);
    mPlayer->setFocus();
    mScene->addItem(mPlayer);

    QObject::connect(mPlayer, SIGNAL(playerTankHealthChanged(int)), this, SLOT(mPlayerTankHealthChanged(int)));
    QObject::connect(mPlayer, SIGNAL(playerTankDestroyed()), this, SLOT(playerKilled()));


}


