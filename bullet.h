#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>
#include "tank.h"
#include <QGraphicsObject>
#include <QtMultimedia>
#include "explosion.h"
#include "constants.h"
#include "tank.h"
#include "playertank.h"
#include "bottank.h"



class Bullet : public QGraphicsObject
{
    Q_OBJECT
public:
    //enum Tank::Orientation{LEFT=0, UP=1, RIGHT=2, DOWN=3};

    Bullet(Tank::Orientation direction, QPointF point, Tank::TankType type = Tank::TankType::Player);
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
    Tank::TankType mTankType;

};

#endif // BULLET_H
