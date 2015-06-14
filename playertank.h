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
    Q_OBJECT
public:
    enum Player {Player1, Player2};

    PlayerTank(qreal x, qreal y, Orientation ori, Player p = Player::Player1, int health = TANK_HEALTH);
    ~PlayerTank();
    void keyPressEvent(QKeyEvent * event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void hitted(int damage) Q_DECL_OVERRIDE;
    int health() const;
    virtual void advance(int step) Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

signals:
    void playerTankDestroyed(PlayerTank::Player p = Player1);
    void playerTankHealthChanged(int health);

private:
    void multipeButtonsPressed();
    void singleButtonPressed();
    void processKey(const Qt::Key &button);

private:
    QSet<Qt::Key> mButtonsPressed;
    QTime mTimeOfLastBullet;
    int UP_BUTTON, DOWN_BUTTON, LEFT_BUTTON, RIGHT_BUTTON, FIRE_BUTTON;
    Player mPlayer;

};

#endif // PLAYERTANK_H
