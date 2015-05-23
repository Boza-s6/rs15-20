#ifndef BRICK_H
#define BRICK_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QString>
#include <QObject>
#include <QPixmap>

class Brick : public QGraphicsItem
{
    Q_OBJECT

public:
    Brick(qreal x, qreal y);
    virtual ~Brick();
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *) Q_DECL_OVERRIDE;

protected:
    void advance(int phase);

public slots:
    void hitted(int damage);

private:
    QPixmap mImage;
    int mHealth;
    qreal mWidth, mHeight;
//    qreal mX, mY;
};

#endif // BRICK_H
