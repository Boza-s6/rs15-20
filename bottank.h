#ifndef BOTTANK_H
#define BOTTANK_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>


class BotTank: public QGraphicsItem
{
public:
    enum class Vrsta{PRVI, DRUGI, BOT};
    enum Orijentacija{LEVO=0, GORE=1, DESNO=2, DOLE=3};

    BotTank( Vrsta igrac, Orijentacija ori);
    ~BotTank();




    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
    //virtual void keyPressEvent(QKeyEvent * event);

public slots:
    void advance(int step) Q_DECL_OVERRIDE;

private:
    Vrsta mVrsta;
    qreal mAngle;
    qreal mSpeed;
    QPixmap mSlika;
    Orijentacija mOrij;

    bool isMoving, isAlive;


};

#endif // BOTTANK_H
