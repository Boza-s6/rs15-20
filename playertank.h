#ifndef PLAYERTANK_H
#define PLAYERTANK_H
#include "tank.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QSet>
#include <QTime>
#include <QRect>
#include "constants.h"

class PlayerTank : public Tank
{
public:
    PlayerTank(qreal x, qreal y, Orientation ori);
    ~PlayerTank();
    void keyPressEvent(QKeyEvent * event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
public slots:
    virtual void advance(int step) Q_DECL_OVERRIDE;

private:
    void multipeButtonsPressed();
    void singleButtonPressed();
    void processKey(const Qt::Key & button);
private:
    QSet<Qt::Key> mButtonsPressed;
    QTime mTimeOfLastBullet;


};

#endif // PLAYERTANK_H
