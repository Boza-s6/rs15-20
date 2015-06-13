#include "explosion.h"

Explosion::Explosion(QPointF point)
    :mImage(":/img/img/explosion.png"),
      mTimer(), isDone(false)
{
    setPos(point);

    mTimer.setInterval(EXPLOSION_TIME_MILISEC);
    mTimer.setSingleShot(true);
    QObject::connect(&mTimer, SIGNAL(timeout()), this, SLOT(destroySelf()));
    mTimer.start();

    //Zvuk explozije
    /*
    mMusicExplosion = new QMediaPlayer();
    mMusicExplosion->setMedia(QUrl("qrc:/sounds/sounds/explosion.mp3"));
    mMusicExplosion->play();
    */
}

Explosion::~Explosion()
{
    //delete mMusicExplosion;
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
        if(dynamic_cast<SpecialQGraphicsPixmapItem*>(item))
            static_cast<SpecialQGraphicsPixmapItem*>(item)->hitted(EXPLOSION_DAMAGE);

    }
    isDone = true;
}

void Explosion::destroySelf()
{
    scene()->removeItem(this);
    delete this;
}

