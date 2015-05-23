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
public slots:
    virtual void advance(int step) Q_DECL_OVERRIDE;
private:

};

#endif // PLAYERTANK_H
