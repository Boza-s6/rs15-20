#include "playertank.h"
#include <QKeyEvent>
#include <iostream>
#include "bullet.h"
PlayerTank::PlayerTank(qreal x, qreal y,Tank::Orientation ori=Orientation::UP )
    : Tank(ori, x,y, ":/img/img/player1_tank.png"),
      mButtonsPressed(), mTimeOfLastBullet()
{
    setRotation(getAngleFromOrientation(ori));
}

PlayerTank::~PlayerTank()
{

}

void PlayerTank::keyPressEvent(QKeyEvent *event)
{
    mButtonsPressed += (Qt::Key)event->key();

}

void PlayerTank::keyReleaseEvent(QKeyEvent *event)
{
    mButtonsPressed -= (Qt::Key)event->key();
}

void PlayerTank::advance(int step)
{
    if (!step)
        return;

    if(mButtonsPressed.size() == 1)
    {
        singleButtonPressed();
    }
    else if(mButtonsPressed.size() > 1)
    {
        multipeButtonsPressed();
    }

}

void PlayerTank::multipeButtonsPressed()
{
    bool WASDProcessed = false;

    for(auto &button : mButtonsPressed)
    {
        if(WASDProcessed && (button == Qt::Key_W || button == Qt::Key_S
                             || button == Qt::Key_A
                             || button == Qt::Key_D))
            continue;

        processKey(button);

        if (button == Qt::Key_W || button == Qt::Key_S
                || button == Qt::Key_A
                || button == Qt::Key_D){
            WASDProcessed = true;
        }

    }
}

void PlayerTank::singleButtonPressed()
{
    auto iterator = mButtonsPressed.constBegin();

    processKey(*iterator);
}

void PlayerTank::processKey(const Qt::Key & button)
{
    switch (button) {
        case Qt::Key_W:
            setOrientation(Orientation::UP);
            moveBy(0, -speed());
            break;
        case Qt::Key_S:
            setOrientation(Orientation::DOWN);
            moveBy(0, speed());
            break;
        case Qt::Key_A:
            setOrientation(Orientation::LEFT);
            moveBy(-speed(), 0);
            break;
        case Qt::Key_D:
            setOrientation(Orientation::RIGHT);
            moveBy(speed(), 0);
            break;
        case Qt::Key_Space:
            //ako prvi put udjemo ovde moramo da budemo sigurni
            // da smo pokrenuli tajmer
            static bool firstTime = true;
            if(firstTime){
                mTimeOfLastBullet.start();
                mTimeOfLastBullet.addMSecs(200);
                firstTime = false;
            }

            if(mTimeOfLastBullet.elapsed() >= BULLET_TIME_BETWEEN_FIRE_MILISEC){
                qreal x=this->x();
                qreal y=this->y();

                Bullet *b=new Bullet(getOrientation(), QPointF(x,y) );
                scene()->addItem(b);
                mTimeOfLastBullet.restart();
            }
            break;
        default:
            break;
    }
}
