#ifndef SOLIDBRICK_H
#define SOLIDBRICK_H
#include "specialqgraphicspixmapitem.h"
#include <QGraphicsScene>
#include "brick.h"

class SolidBrick : public Brick
{
public:
    SolidBrick();
    SolidBrick(qreal x, qreal y);
    ~SolidBrick();
    virtual void hitted(int) Q_DECL_OVERRIDE;
};

#endif // SOLIDBRICK_H
