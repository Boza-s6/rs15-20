#include "specialqgraphicspixmapitem.h"

SpecialQGraphicsPixmapItem::SpecialQGraphicsPixmapItem(const char *slika, qreal x, qreal y)
    : QGraphicsPixmapItem(QPixmap(QString(slika)))
{
    setPos(x, y);
}

SpecialQGraphicsPixmapItem::SpecialQGraphicsPixmapItem()
    :QGraphicsPixmapItem(QPixmap(":/img/special.png"))
{
    setPos(0, 0);
}

SpecialQGraphicsPixmapItem::~SpecialQGraphicsPixmapItem()
{

}

