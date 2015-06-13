#include "tank.h"
#include <QPainter>
#include <iostream>
#include <QKeyEvent>
//#define DEBUG

Tank::Tank( Orientation ori = Orientation::UP, qreal x=0, qreal y=0, const char* path="", int health):
    SpecialQGraphicsPixmapItem(path,x,y),
    mOrientation(ori), mSpeed(TANK_SPEED),
    mCollidingRect(QRect(boundingRect().topLeft().x() +2 , boundingRect().topLeft().y() - 7, 40, 3), this),
    mHealth(health)
{

    mCollidingRect.setPen(QPen(Qt::PenStyle::NoPen)); //postavljamo olovku na 'bez olovke'
                                                      //da ne bi isrctavali pravouganik na sceni

    isMoving = false; //ne treba nam??
    isAlive = true; //  ovo?
    setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
}

Tank::~Tank()
{

}

int Tank::getAngleFromOrientation(Tank::Orientation ori) const
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

int Tank::speed() const
{
    return mSpeed;
}

void Tank::setOrientation(Tank::Orientation ori)
{
    mOrientation=ori;
    this->setRotation(getAngleFromOrientation(ori));

}

Tank::Orientation Tank::getOrientation() const
{
    return mOrientation;
}

void Tank::advance(int step)
{
    if(step == 0)
        return;

}

void Tank::moveUp()
{
    setOrientation(Orientation::UP);
    moveBy(0, -speed());
}

void Tank::moveDown()
{
    setOrientation(Orientation::DOWN);
    moveBy(0, speed());
}

void Tank::moveLeft()
{
    setOrientation(Orientation::LEFT);
    moveBy(-speed(), 0);
}

void Tank::moveRight()
{
    setOrientation(Orientation::RIGHT);
    moveBy(speed(), 0);
}



void Tank::setSpeed(const int speed)
{
    mSpeed = speed;
}

void Tank::hitted(int)
{
    return;
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                 QWidget *)
{
    int x = this->pixmap().width();
    int y = this->pixmap().height();
    this->setFocus();
    painter->drawPixmap(-x/2,-y/2, pixmap());

#ifdef DEBUG
    QLine goredole(QPoint(0, 50), QPoint(0, -50));
    QLine levodesno(QPoint(-50, 0), QPoint(50, 0));
    QPen olovka(Qt::white);
    painter->setPen(olovka);
    painter->drawLine(goredole);
    painter->drawLine(levodesno);

    painter->setPen(QPen(Qt::red));
    painter->drawRect(boundingRect());


    mCollidingRect.paint(painter, option, 0);
#endif
}

QRectF Tank::boundingRect() const
{
    qreal w = pixmap().width();
    qreal h = pixmap().height();
    return QRectF(-w/2, -h/2, w, h);

}


