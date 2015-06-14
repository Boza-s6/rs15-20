#include "brick.h"

Brick::Brick(qreal x, qreal y)
    :SpecialQGraphicsPixmapItem(":/img/img/brick.png", x, y), mHealth(100)
{

}
Brick::Brick(const char *slika, qreal x, qreal y)
    :SpecialQGraphicsPixmapItem(slika, x, y), mHealth(100)
{

}
Brick::Brick()
    :SpecialQGraphicsPixmapItem(), mHealth(100)
{
}

Brick::~Brick()
{

}

void Brick::hitted(int damage)
{
    mHealth -= damage;
    if(mHealth <= 0){
        this->scene()->removeItem(this);
       // delete this;
    }
}

