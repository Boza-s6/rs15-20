#ifndef METAK_H
#define METAK_H
#include <QGraphicsItem>

class Metak : public QGraphicsItem
{
public:
    enum Orijentacija{LEVO=0, GORE=1, DESNO=2, DOLE=3};
    Metak(Orijentacija pravac, QPoint tacka);
    ~Metak();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;

public slots:
    void advance(int step) Q_DECL_OVERRIDE;

private:
    QPixmap mSlika;
    Orijentacija mPravac;
    QPoint mTacka;
    qreal mSpeed;
};

#endif // METAK_H
