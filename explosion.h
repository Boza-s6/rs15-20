#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <QGraphicsObject>
#include "specialqgraphicspixmapitem.h"
#include <QTimer>
#include <QPainter>
#include <QObject>
#include "constants.h"

class Explosion : public QGraphicsObject
{
    Q_OBJECT
public:
    Explosion(QPointF point);
    virtual ~Explosion();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
               QWidget *) Q_DECL_OVERRIDE;
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void advance(int phase) Q_DECL_OVERRIDE;

public slots:
    void destroySelf();

private:
    QPixmap mImage;
    QTimer mTimer;
    bool isDone;
};

#endif // EXPLOSION_H
