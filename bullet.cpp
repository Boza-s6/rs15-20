#include "bullet.h"
#include <QPainter>
#include <iostream>
#include <QKeyEvent>

Bullet::Bullet(Orijentacija direction, QPoint point)
    : mImage(":/img/metak.png"), mDirection(direction),
      mPoint(point)
{
    mSpeed = 10; //pikslea po sek
    setFlags(QGraphicsItem::ItemIsMovable);
    mapToScene(mPoint);

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
    painter->drawRect(QRectF(mImage.rect()));
    painter->drawPixmap(mPoint, mImage);
}

void Bullet::advance(int step)
{
    if(step == 0)
        return;
    moveBy(mSpeed, 0);

}


