#ifndef BOTTANK_H
#define BOTTANK_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "tank.h"

class BotTank: public Tank
{
public:

    BotTank(qreal x, qreal y, Orientation ori);
    ~BotTank();
public slots:
    virtual void advance(int step) Q_DECL_OVERRIDE;

private:

    qreal mAngle;

};

#endif // BOTTANK_H
