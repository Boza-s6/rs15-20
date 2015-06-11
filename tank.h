#ifndef TANK_H
#define TANK_H
#include <QGraphicsItem>
#include "specialqgraphicspixmapitem.h"

class Tank : public  SpecialQGraphicsPixmapItem
{

public:


    enum Orientation{LEFT=0, UP=1, RIGHT=2, DOWN=3};

    Tank( Orientation ori, qreal x, qreal y, const char * path);
    virtual ~Tank()=0;
   // virtual void keyPressEvent(QKeyEvent * event);
    int getAngleFromOrientation(Orientation ori);
    int Speed();
    void setOrientation(Orientation ori);
    Orientation getOrientation();
    qreal speed() const;
    void setSpeed(const qreal &speed);

    void hitted(int damage) Q_DECL_OVERRIDE;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const Q_DECL_OVERRIDE;
public slots:
    virtual void advance(int step) Q_DECL_OVERRIDE;

private:

    Orientation mOrientation;
    qreal mSpeed;

    bool isMoving, isAlive;

};

#endif // TANK_H
