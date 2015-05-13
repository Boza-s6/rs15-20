#include "metak.h"
#include <QPainter>
#include <iostream>
#include <QKeyEvent>

Metak::Metak(Orijentacija pravac, QPoint tacka)
    : mSlika(":/img/metak.png"), mPravac(pravac),
      mTacka(tacka)
{
    mSpeed = 10; //pikslea po sek
    setFlags(QGraphicsItem::ItemIsMovable);
    mapToScene(mTacka);

}

Metak::~Metak()
{

}

QRectF Metak::boundingRect() const
{
    return QRectF(mSlika.rect());
}

void Metak::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(QRectF(mSlika.rect()));
    painter->drawPixmap(mTacka, mSlika);
}

void Metak::advance(int step)
{
    if(step == 0)
        return;
    moveBy(mSpeed, 0);

}


