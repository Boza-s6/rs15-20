#include "bullet.h"
#include <QPainter>
#include <iostream>
#include <QKeyEvent>

Bullet::Bullet(Tank::Orientation direction, QPointF point)
    : mImage(":/img/metak.png"), mOrientation(direction),
      mPoint(point)
{
    mSpeed = 10; //pikslea po sek
    setFlags(QGraphicsItem::ItemIsMovable);
    mapFromScene(mPoint); //mozda ne treba ovo
    setPos(point);

}

Bullet::~Bullet()
{

}

QRectF Bullet::boundingRect() const
{
    return QRectF(mImage.rect());


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

}


