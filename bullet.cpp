#include "bullet.h"
#include <QPainter>
#include <iostream>
#include <QKeyEvent>
#include <typeinfo>


Bullet::Bullet(Tank::Orientation direction, QPointF point, Tank::TankType type)
    : mImage(":/img/img/metak.png"), mOrientation(direction),
      mPoint(point), mSpeed(BULLET_SPEED), mTankType(type),
      isDone(false)
{
    setFlags(QGraphicsItem::ItemIsMovable);
    mapFromScene(mPoint); //mozda ne treba ovo
    setPos(point);

    //Zvuk metka bullet.mp3 svaki put kad se ispali novi metak
    mMusic = new QMediaPlayer();
    mMusic->setMedia(QUrl("qrc:/sounds/sounds/bullet.mp3"));
    mMusic->play();
}

Bullet::~Bullet()
{
    delete mMusic;
}

QRectF Bullet::boundingRect() const
{
    qreal a=mImage.rect().width();
    qreal s=mImage.rect().height();
    return QRectF(-a/2, -s/2 -2, a, s);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    int x = mImage.rect().width();
    int y = mImage.rect().height();
    this->setFocus();
    painter->drawPixmap(-x/2,-y/2, mImage);
}


void Bullet::advance(int step)
{
    if(step == 0 || isDone)
        return;

    switch (mOrientation) {

        case Tank::Orientation::UP:{
            moveBy(0,-mSpeed);
            setRotation(0);
        }
            break;
        case Tank::Orientation::LEFT:{
            moveBy(-mSpeed,0);
            setRotation(-90);}
            break;
        case Tank::Orientation::RIGHT:{
            moveBy(mSpeed,0);
            setRotation(90);}
            break;
        case Tank::Orientation::DOWN:{
            moveBy(0,mSpeed);
            setRotation(180);}
            break;
    }

    auto list = collidingItems();
    bool isColliding = list.size()==0 ? false : true;


    bool oneIsNotExplosion = false;
    for(auto item : list)
    {
        //proveravmo tip tenka i vracamo se iz funkcije
        //jer ne zelimo da ubijemo svog tenka
        if(mTankType == Tank::TankType::Player)
            if(dynamic_cast<PlayerTank*>(item))
                return;
        if(mTankType == Tank::TankType::Bot)
            if(dynamic_cast<BotTank*>(item))
                return;

        //ako se sudario sa QRect koji koristimo za detekciju preklapanja, nastavi dalje;
        if(dynamic_cast<QGraphicsRectItem*>(item)){
            return;
        }
        //ako se sudario sa ekspolzijom oznaci;
        if(!dynamic_cast<Explosion*>(item)){
            oneIsNotExplosion = true;
        }
        // ako se sudario sa drugim metkom unisti se;
        if(dynamic_cast<Bullet*>(item) != nullptr){
            destroySelf();
            return;
        }
    }



    //ako se sudario sa necim i ako to nesto nije Explosion
    if(isColliding && oneIsNotExplosion){
        qreal x=this->x();
        qreal y=this->y();
        scene()->addItem(new Explosion(QPointF(x,y), mTankType));
        destroySelf();
    }
}

void Bullet::destroySelf()
{
    hide();
    mMusic->stop();
    isDone = true;
//    scene()->removeItem(this);
    delete this;
}



