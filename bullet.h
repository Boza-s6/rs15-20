#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>
#include "tank.h"
#include <QGraphicsObject>
#include <QtMultimedia>
#include "explosion.h"

class Bullet : public QGraphicsObject
{
    Q_OBJECT
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
    void destroySelf();


    QPixmap mImage;
    Tank::Orientation mOrientation;
    QPointF mPoint;
    qreal mSpeed;
    QMediaPlayer * mMusic;

};

#endif // BULLET_H
