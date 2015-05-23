#include "tank.h"
#include <QPainter>
#include <iostream>
#include <QKeyEvent>

Tank::Tank( Orientation ori = Orientation::UP, qreal x=0, qreal y=0, const char* path=""):
    mOrientation(ori),
    mImage(path)
{
    mSpeed = 10; //pikseli po sekundi
    isMoving = false;
    isAlive = true;
    setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
    setPos(x,y);

}

Tank::~Tank()
{

}



QRectF Tank::boundingRect() const{

    qreal a=mImage.rect().width();
    qreal s=mImage.rect().height();
    return QRectF(-a/2, -s/2 -2, a, s);
}


void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                 QWidget *)
{
    int x = mImage.rect().width();
    int y = mImage.rect().height();
    this->setFocus();
    painter->drawPixmap(-x/2,-y/2, mImage);


}

int Tank::getAngleFromOrientation(Tank::Orientation ori)
{
    switch (ori) {
    case Orientation::UP:
        return 0;
        break;
    case Orientation::LEFT:
        return -90;
        break;
    case Orientation::RIGHT:
        return 90;
        break;
    case Orientation::DOWN:
        return 180;
        break;
    }

    return 0;
}

int Tank::Speed()
{
    return mSpeed;
}

void Tank::setOrientation(Tank::Orientation ori)
{
    mOrientation=ori;
}

Tank::Orientation Tank::getOrientation()
{
    return mOrientation;
}

void Tank::advance(int step)
{
    if(step == 0)
        return;
}
qreal Tank::speed() const
{
    return mSpeed;
}

void Tank::setSpeed(const qreal &speed)
{
    mSpeed = speed;
}


