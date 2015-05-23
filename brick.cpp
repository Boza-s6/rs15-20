#include "brick.h"

Brick::Brick(qreal x, qreal y):
    mImage(":/img/brick.png"),
    mHealth(100)
{
    setPos(x, y);
    mWidth = mImage.width();
    mHeight = mImage.height();
}

Brick::~Brick()
{
}

QRectF Brick::boundingRect() const
{
    return QRectF(0, 0, mWidth, mHeight);
}

void Brick::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(boundingRect()); // proba!!!!!

    painter->drawPixmap(boundingRect().topLeft(), mImage);
}

void Brick::advance(int phase)
{
    if(!phase) return;
}

void Brick::hitted(int damage)
{
    mHealth -= damage;
    if(mHealth == 0)
    {
        scene()->removeItem(this);
    }
}
