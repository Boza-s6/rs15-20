#ifndef PLAYERTANK_H
#define PLAYERTANK_H
#include "tank.h"
#include <QGraphicsScene>

class PlayerTank : public Tank
{
public:
    PlayerTank(qreal x, qreal y, Orientation ori);
    ~PlayerTank();
    void keyPressEvent(QKeyEvent * event);
private:

};

#endif // PLAYERTANK_H
