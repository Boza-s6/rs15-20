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
   // Qt::key
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

   // update();
    QGraphicsItem::keyPressEvent(event);

}

void PlayerTank::advance(int step)
{
    if (!step)
        return;


    if (this->x()<0 || this->x()>1000 || this->y()<0 || this->y()>600) {
<<<<<<< HEAD
       setSpeed(-10);
    }
    else
       setSpeed(10);
=======
        setSpeed(-10);
    }
    else
        setSpeed(10);
>>>>>>> parent of ef94f62... Izmene u implementaciji bottank klase.


}
