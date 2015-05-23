#include "button.h"
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
Button::Button(const char *text="DUGME", qreal x=0, qreal y=0)
    : mText(text),
      mImage(":/img/button.png"),
      mImagePressed(":/img/button_pressed.png")
{
    setPos(x, y);
    mWidth = mImage.width();
    mHeight = mImage.height();
    pressed = false;
}

Button::~Button()
{

}

QRectF Button::boundingRect() const
{
    return QRectF(0, 0, mWidth, mHeight);
}

void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(boundingRect()); // proba!!!!!

    //ako je dugme pritisnuto, isrtavamo odgovarajucu sliku
    painter->drawPixmap(boundingRect().topLeft(), pressed ? mImagePressed : mImage);

    //iscrtavamo  tekst
    painter->drawText(boundingRect(), mText, QTextOption(Qt::AlignCenter));
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    pressed = true;
}

void Button::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    if(pressed)
    {
        pressed = false;
        emit clicked();
    }
}

void Button::advance(int phase){
    if(!phase) return;
}
