#ifndef TANK_H
#define TANK_H
#include <QGraphicsItem>

class Tank : public QGraphicsItem
{

public:
    enum class Vrsta{PRVI, DRUGI, BOT};
    enum Orijentacija{LEVO=0, GORE=1, DESNO=2, DOLE=3};

    Tank( Vrsta igrac, Orijentacija ori);
    ~Tank();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    //QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
    virtual void keyPressEvent(QKeyEvent * event);

public slots:
    void advance(int) Q_DECL_OVERRIDE;

private:
    Vrsta mVrsta;
    qreal mAngle;
    qreal mSpeed;
    QPixmap mSlika;
    Orijentacija mOrij;

    bool isMoving, isAlive;

};

#endif // TANK_H
