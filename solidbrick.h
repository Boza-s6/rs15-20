#ifndef SOLIDBRICK_H
#define SOLIDBRICK_H
#include "brick.h"

class SolidBrick : public Brick
{
public:
    SolidBrick(qreal x, qreal y);
    ~SolidBrick();
};

#endif // SOLIDBRICK_H
