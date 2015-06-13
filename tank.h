#ifndef TANK_H
#define TANK_H
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include "specialqgraphicspixmapitem.h"
#include "constants.h"

class Tank : public  SpecialQGraphicsPixmapItem
{

public:
    enum Orientation{LEFT=0, UP=1, RIGHT=2, DOWN=3};

    Tank( Orientation ori, qreal x, qreal y, const char * path);
    virtual ~Tank()=0;

    int getAngleFromOrientation(Orientation ori) const;

    int speed() const;
    void setSpeed(const int speed);

    Orientation getOrientation() const;
    void setOrientation(Orientation ori);

    void hitted(int damage) Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    virtual void advance(int step) Q_DECL_OVERRIDE;

protected:
    int mHealth;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

private:
    Orientation mOrientation;

    int mSpeed;
    bool isMoving, isAlive;

protected:
    bool hitLeft,hitRight,hitBottom,hitUp;
    QGraphicsRectItem mCollidingRect;
    Orientation mCollidingSide;
    bool mIsColliding;

};

#endif // TANK_H
