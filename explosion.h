#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <QGraphicsObject>
#include "specialqgraphicspixmapitem.h"
#include <QTimer>
#include <QPainter>
#include <QObject>
#include "constants.h"
#include "tank.h"
#include "playertank.h"
#include "bottank.h"
//#include <QtMultimedia>

class Explosion : public QGraphicsObject
{
    Q_OBJECT
public:
    Explosion(QPointF point, Tank::TankType type = Tank::Player);
    virtual ~Explosion();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
               QWidget *) Q_DECL_OVERRIDE;
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void advance(int phase) Q_DECL_OVERRIDE;

public slots:
    void destroySelf();

private:
    QPixmap mImage;
    QTimer mTimer;
    bool isDone;
    Tank::TankType mTankType;
    //QMediaPlayer * mMusicExplosion;
};

#endif // EXPLOSION_H
