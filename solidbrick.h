#ifndef SOLIDBRICK_H
#define SOLIDBRICK_H
#include "brick.h"

class SolidBrick : protected Brick
{
public:
    SolidBrick(qreal x, qreal y);
    ~SolidBrick();
};

#endif // SOLIDBRICK_H
