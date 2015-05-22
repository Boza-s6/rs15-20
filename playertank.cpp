#include "playertank.h"
#include <QKeyEvent>
#include "bullet.h"
PlayerTank::PlayerTank(qreal x, qreal y,Tank::Orientation ori=Orientation::UP ): Tank(ori, x,y, ":/img/player1_tank.png")
{
    setRotation(getAngleFromOrientation(ori));
}

PlayerTank::~PlayerTank()
{

}

void PlayerTank::keyPressEvent(QKeyEvent *event)
{



    int key = event->key();
    switch (key) {
    case Qt::Key_W:{

        setOrientation(Orientation::UP);
        moveBy(0,-speed());
        setRotation(0);
    }
        break;
    case Qt::Key_A:{
        setOrientation(Orientation::LEFT);
        moveBy(-speed(),0);
        setRotation(-90);
    }
        break;
    case Qt::Key_D:{
        setOrientation(Orientation::RIGHT);
        moveBy(speed(),0);
        setRotation(90);
    }
        break;
    case Qt::Key_S:{
        setOrientation(Orientation::DOWN);
        moveBy(0,speed());
        setRotation(180);
    }
        break;
    case Qt::Key_Space:{
        qreal x=this->x();
        qreal y=this->y();




        Bullet *b=new Bullet(Tank::getOrientation(), QPointF(x,y) );
        scene()->addItem(b);
    }
        break;

        default:
        break;
    }

    update();
    QGraphicsItem::keyPressEvent(event);

}

