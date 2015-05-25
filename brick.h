#ifndef BRICK_H
#define BRICK_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QString>
#include <QObject>
#include <QPixmap>
#include <QGraphicsObject>

class Brick : public QGraphicsObject
{
    Q_OBJECT
public:
    Brick(qreal x, qreal y, const char * = ":/img/brick.png");
    virtual ~Brick();
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *) Q_DECL_OVERRIDE;

protected:
    void advance(int phase);

public slots:
    void hitted(int damage);

protected:
    QPixmap mImage;
private:
    int mHealth;
    qreal mWidth, mHeight;
//    qreal mX, mY;
};

#endif // BRICK_H
