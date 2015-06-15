#include "brick.h"

Brick::Brick(qreal x, qreal y)
    :SpecialQGraphicsPixmapItem(":/img/img/brick.png", x, y), mHealth(BRICK_HEALTH),
      isDone(false)
{

}
Brick::Brick(const char *slika, qreal x, qreal y)
    :SpecialQGraphicsPixmapItem(slika, x, y), mHealth(BRICK_HEALTH),
      isDone(false)
{

}
Brick::Brick()
    :SpecialQGraphicsPixmapItem(), mHealth(BRICK_HEALTH),
      isDone(false)
{
}

Brick::~Brick()
{

}
//umanjenje helta kada je cigla pogodjena
void Brick::hitted(int damage)
{
    mHealth -= damage;
    if(mHealth <= 0 && !isDone){
        hide();
        isDone = true;
        deleteLater();
    }
}

