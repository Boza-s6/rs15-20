#include "tank.h"
#include <QPainter>
#include <iostream>
#include <QKeyEvent>

Tank::Tank( Vrsta igrac = Vrsta::PRVI, Orijentacija ori = Orijentacija::GORE):
    mSlika((igrac == Vrsta::PRVI)?":/img/player1_tank.png":(igrac == Vrsta::DRUGI)?
                                      ":/img/player2_tank.png" : ":/img/bot.png"),
    mOrij(ori)
{
    mSpeed = 5; //pikseli po sekundi
    isMoving = false;
    isAlive = true;
    setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);

}

Tank::~Tank()
{

}

QRectF Tank::boundingRect() const{
    return mSlika.rect();
}


void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                 QWidget *)
{
    int x = mSlika.rect().width();
    int y = mSlika.rect().height();
    painter->drawPixmap(-x/2,-y/2, mSlika);

    //    // Ears
    //    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : Qt::red);
    //    painter->drawEllipse(0, 0, 16, 16);
    //    painter->drawEllipse(0, 0, 16, 16);


    QPen pen;
    pen.setColor(Qt::yellow);
    pen.setWidth(2);
    painter->setPen(pen);

    painter->drawLine(QPoint(-20, 0), QPoint(20, 0));
    painter->drawLine(QPoint(0, -20), QPoint(0, 10));

    update();
}

void Tank::keyPressEvent(QKeyEvent *event)
{
    Orijentacija nova;
    int n;

    int key = event->key();
    switch (key) {
    case Qt::Key_W:
        mOrij=Orijentacija::GORE;
        moveBy(0,-mSpeed);
        setRotation(0);
        break;
    case Qt::Key_A:
        mOrij=Orijentacija::LEVO;
        moveBy(-mSpeed,0);
        setRotation(-90);
        break;
    case Qt::Key_D:
        mOrij=Orijentacija::DESNO;
        moveBy(mSpeed,0);
        setRotation(90);
        break;
    case Qt::Key_S:
        mOrij=Orijentacija::DOLE;
        moveBy(0,mSpeed);
        setRotation(180);
        break;
    default:

        break;
    }

    update();
    QGraphicsItem::keyPressEvent(event);
}

void Tank::advance(int)
{
    //    std::cout << "SARIC JE MORON" << std::endl;

    //   moveBy(4, 0);

}
