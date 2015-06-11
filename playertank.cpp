#include "playertank.h"
#include <QKeyEvent>
#include "bullet.h"
PlayerTank::PlayerTank(qreal x, qreal y,Tank::Orientation ori=Orientation::UP )
    : Tank(ori, x,y, ":/img/img/player1_tank.png")
{
    setRotation(getAngleFromOrientation(ori));
}

PlayerTank::~PlayerTank()
{

}

void PlayerTank::keyPressEvent(QKeyEvent *event)
{
    mPressed = true;
    int key = event->key();
    /*
    if(key == mButton)
        return;
*/
    mButton = (Qt::Key)key;


    switch (key) {
    case Qt::Key_W:
        setOrientation(Orientation::UP);
        break;
    case Qt::Key_A:
        setOrientation(Orientation::LEFT);
        break;
    case Qt::Key_D:
        setOrientation(Orientation::RIGHT);
        break;
    case Qt::Key_S:
        setOrientation(Orientation::DOWN);
        break;
    case Qt::Key_Space:
        qreal x=this->x();
        qreal y=this->y();

        Bullet *b=new Bullet(Tank::getOrientation(), QPointF(x,y) );
        scene()->addItem(b);
        break;
    }

    //    QGraphicsItem::keyPressEvent(event);

}

void PlayerTank::keyReleaseEvent(QKeyEvent *)
{
    mPressed = false;
}

void PlayerTank::advance(int step)
{
    if (!step)
        return;

    if(mPressed){
        switch (mButton) {
        case Qt::Key_W:
            moveBy(0, -speed());
            break;
        case Qt::Key_S:
            moveBy(0, speed());
            break;
        case Qt::Key_A:
            moveBy(-speed(), 0);
            break;
        case Qt::Key_D:
            moveBy(speed(), 0);
            break;
        default:
            break;
        }
    }
    if (this->x()<0 || this->x()>1000 || this->y()<0 || this->y()>600) {
        setSpeed(-5);
    }
    else
        setSpeed(5);


}
