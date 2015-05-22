#ifndef TANK_H
#define TANK_H
#include <QGraphicsItem>

class Tank : public QGraphicsItem
{

public:


    enum Orientation{LEFT=0, UP=1, RIGHT=2, DOWN=3};

    Tank( Orientation ori, qreal x, qreal y, const char * path);
    virtual ~Tank()=0;
    virtual QRectF boundingRect() const Q_DECL_OVERRIDE;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
   // virtual void keyPressEvent(QKeyEvent * event);
    int getAngleFromOrientation(Orientation ori);
    int Speed();
    void setOrientation(Orientation ori);
    Orientation getOrientation();
    qreal speed() const;
    void setSpeed(const qreal &speed);

public slots:
    virtual void advance(int step) Q_DECL_OVERRIDE;

private:

    Orientation mOrientation;
    qreal mSpeed;
    QPixmap mImage;

    bool isMoving, isAlive;

};

#endif // TANK_H
