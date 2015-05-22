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

int Tank::Speed()
{
    return mSpeed;
}

void Tank::keyPressEvent(QKeyEvent *event)
{

    int key = event->key();
    switch (key) {
    case Qt::Key_W:
        mOrientation=Orientation::UP;
        moveBy(0,-mSpeed);
        setRotation(0);
        break;
    case Qt::Key_A:
        mOrientation=Orientation::LEFT;
        moveBy(-mSpeed,0);
        setRotation(-90);
        break;
    case Qt::Key_D:
        mOrientation=Orientation::RIGHT;
        moveBy(mSpeed,0);
        setRotation(90);
        break;
    case Qt::Key_S:
        mOrientation=Orientation::DOWN;
        moveBy(0,mSpeed);
        setRotation(180);
        break;
    default:

        break;
    }

    update();
    QGraphicsItem::keyPressEvent(event);
}


void Tank::advance(int step)
{
    if(step == 0)
        return;


    //   moveBy(4, 0);

}

