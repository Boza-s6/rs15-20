#ifndef SPECIALGRAPHICSITEM_H
#define SPECIALGRAPHICSITEM_H

#include <QGraphicsObject>

class SpecialGraphicsItem : public QGraphicsObject
{
public:
    SpecialGraphicsItem();
    ~SpecialGraphicsItem();

    virtual QRectF boundingRect() const = 0 ;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) =0;

public slots:
    virtual void hitted(int damage) =0;
};

#endif // SPECIALGRAPHICSITEM_H
