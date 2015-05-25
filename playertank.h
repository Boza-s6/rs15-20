#ifndef PLAYERTANK_H
#define PLAYERTANK_H
#include "tank.h"
#include <QGraphicsScene>
#include <QKeyEvent>

class PlayerTank : public Tank
{
public:
    PlayerTank(qreal x, qreal y, Orientation ori);
    ~PlayerTank();
    void keyPressEvent(QKeyEvent * event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *) Q_DECL_OVERRIDE;
public slots:
    virtual void advance(int step) Q_DECL_OVERRIDE;
private:
    Qt::Key mButton;
    bool mPressed;
};

#endif // PLAYERTANK_H
