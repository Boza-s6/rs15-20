#ifndef SPECIALQGRAPHICSPIXMAPITEM_H
#define SPECIALQGRAPHICSPIXMAPITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include "constants.h"

class SpecialQGraphicsPixmapItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    SpecialQGraphicsPixmapItem(const char* slika, qreal x = 0, qreal y = 0);
    SpecialQGraphicsPixmapItem();
    virtual ~SpecialQGraphicsPixmapItem();
    virtual void hitted(int damage = EXPLOSION_DAMAGE) = 0;
};

#endif // SPECIALQGRAPHICSPIXMAPITEM_H
