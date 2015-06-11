#ifndef BRICK_H
#define BRICK_H

#include "specialqgraphicspixmapitem.h"
#include <QGraphicsScene>

class Brick : public SpecialQGraphicsPixmapItem
{
public:
    Brick(qreal x, qreal y);
    Brick();
    ~Brick();
    virtual void hitted(int damage) Q_DECL_OVERRIDE;
protected:
    Brick(const char * slika, qreal x, qreal y);
private:
    int mHealth;
};

#endif // BRICK_H

