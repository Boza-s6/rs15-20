#include "fenix.h"

Fenix::Fenix()
    : SpecialQGraphicsPixmapItem(), mHealth(FENIX_HEALTH),
      isDone(false)
{

}

Fenix::Fenix(qreal x, qreal y)
    : SpecialQGraphicsPixmapItem(":/img/img/fenix.png", x, y), mHealth(FENIX_HEALTH),
      isDone(false)
{

}

Fenix::~Fenix()
{

}

void Fenix::hitted(int damage)
{
    mHealth -= damage;
    if(mHealth <= 0 && !isDone)
    {
        emit fenixDestroyed();
        hide();
        isDone = true;
        deleteLater();

    }
}

