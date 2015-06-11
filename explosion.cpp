#include "explosion.h"

Explosion::Explosion(QPointF point)
    :mImage(":/img/img/explosion.png")
{
    setPos(point);
    mTimer = new QTimer;
    mTimer->setInterval(1000);
    mTimer->setSingleShot(true);
    QObject::connect(mTimer, SIGNAL(timeout()), this, SLOT(onTimerDestroySelf()));
    mTimer->start();
}

Explosion::~Explosion()
{
    delete mTimer;
}

void Explosion::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    int x = mImage.width();
    int y = mImage.height();
    painter->drawPixmap(-x/2,-y/2, mImage);
}

QRectF Explosion::boundingRect() const
{
    qreal w = mImage.width();
    qreal h = mImage.height();
    return QRectF(-w/2, -h/2, w, h);
}

void Explosion::advance(int phase)
{
    if(phase == 0 || isDone){
        return;
    }
    QList<QGraphicsItem*> list = collidingItems();

    for(auto &item: list){
        if(dynamic_cast<Explosion*>(item)){
            continue;
        }
        static_cast<SpecialQGraphicsPixmapItem*>(item)->hitted(100);

    }
    isDone = true;
}

void Explosion::onTimerDestroySelf()
{
    scene()->removeItem(this);
    delete this;
}

