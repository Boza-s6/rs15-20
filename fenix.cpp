#include "fenix.h"


Fenix::Fenix(qreal x, qreal y)
{
    setPos(x,y);
}

Fenix::~Fenix()
{


}

QRectF Fenix::boundingRect() const
{
    return QRectF(0,0, mImage.width(), mImage.height());
}

void Fenix::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    int x = mImage.rect().width();
    int y = mImage.rect().height();

    painter->drawPixmap(-x/2,-y/2, mImage);
}

void Fenix::hitted(int)
{
    scene()->removeItem(this);
    delete this;
}

