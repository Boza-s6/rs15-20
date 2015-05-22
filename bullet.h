#ifndef METAK_H
#define METAK_H
#include <QGraphicsItem>

class Bullet : public QGraphicsItem
{
public:
    enum Orijentacija{LEFT=0, UP=1, RIGHT=2, DOWN=3};
    Bullet(Orijentacija direction, QPoint point);
    ~Bullet();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;

public slots:
    void advance(int step) Q_DECL_OVERRIDE;

private:
    QPixmap mImage;
    Orijentacija mDirection;
    QPoint mPoint;
    qreal mSpeed;
};

#endif // METAK_H
