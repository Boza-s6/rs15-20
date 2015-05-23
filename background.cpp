#include "background.h"

Background::Background()
    :mImage(":/img/bg_pattern.png")
{
}

Background::~Background()
{
}

QRectF Background::boundingRect() const
{
    return QRectF(-500, -350, 1000, 700);
}

void Background::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-500, 350, 1000, 700, mImage);
}

void Background::advance(int phase)
{
    if(!phase) return;
}
