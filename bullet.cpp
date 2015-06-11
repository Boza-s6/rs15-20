#include "bullet.h"
#include <QPainter>
#include <iostream>
#include <QKeyEvent>
#include <QtMultimedia>

Bullet::Bullet(Tank::Orientation direction, QPointF point)
    : mImage(":/img/img/metak.png"), mOrientation(direction),
      mPoint(point)
{
    mSpeed = 10; //pikslea po sek
    setFlags(QGraphicsItem::ItemIsMovable);
    mapFromScene(mPoint); //mozda ne treba ovo
    setPos(point);

    //Zvuk metka bullet.mp3 svaki put kad se ispali novi metak
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sounds/bullet.mp3"));
    music->play();
}

Bullet::~Bullet()
{

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
    if(step == 0)
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

    if (this->x()<0 || this->x()>1000) {
        delete this;
    }
    if(this->y()<0 || this->y()>600){
        delete this;

    }
}


