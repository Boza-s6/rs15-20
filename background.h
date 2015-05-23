#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>

class Background : public QGraphicsItem
{
public:
    Background();
    ~Background();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *) Q_DECL_OVERRIDE;

protected:
    void advance(int phase) Q_DECL_OVERRIDE;

private:
    QPixmap mImage;
};

#endif // BACKGROUND_H
