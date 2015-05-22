#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>
#include "tank.h"

class Bullet : public QGraphicsItem
{
   // Q_OBJECT
public:
    //enum Tank::Orientation{LEFT=0, UP=1, RIGHT=2, DOWN=3};

    Bullet(Tank::Orientation direction, QPointF point);
    ~Bullet();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;

public slots:
    void advance(int step) Q_DECL_OVERRIDE;

private:
    QPixmap mImage;
    Tank::Orientation mOrientation;
    QPointF mPoint;
    qreal mSpeed;
};

#endif // BULLET_H
