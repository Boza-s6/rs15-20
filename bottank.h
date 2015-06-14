#ifndef BOTTANK_H
#define BOTTANK_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "tank.h"
#include "constants.h"
#include <QTime>

class BotTank: public Tank
{
public:

    BotTank(qreal x, qreal y, Orientation ori, int health = BOTTANK_HEALTH);
    ~BotTank();
    void hitted(int damage)  Q_DECL_OVERRIDE;
public slots:
    virtual void advance(int step) Q_DECL_OVERRIDE;

private:
    QTime mTimeOfLastBullet;
    qreal mAngle;

};

#endif // BOTTANK_H
