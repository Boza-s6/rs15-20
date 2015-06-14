#include "playertank.h"
#include <QKeyEvent>
#include <iostream>
#include "bullet.h"
#include "solidbrick.h"
#include "fenix.h"

PlayerTank::PlayerTank(qreal x, qreal y, Tank::Orientation ori=Orientation::UP , Player p, int health)
    : Tank(ori, x,y, ":/img/img/player1_tank.png", health),
      mButtonsPressed(), mTimeOfLastBullet(),
      mPlayer(p)
{
    if(mPlayer == Player::Player1){
        UP_BUTTON = Qt::Key_W;
        DOWN_BUTTON = Qt::Key_S;
        LEFT_BUTTON = Qt::Key_A;
        RIGHT_BUTTON = Qt::Key_D;
        FIRE_BUTTON = Qt::Key_Space;
    }
    else{
        UP_BUTTON = Qt::Key_Up;
        DOWN_BUTTON = Qt::Key_Down;
        LEFT_BUTTON = Qt::Key_Left;
        RIGHT_BUTTON = Qt::Key_Right;
        FIRE_BUTTON = Qt::Key_Control;
    }
    setRotation(getAngleFromOrientation(ori));
    mTimeOfLastBullet.start();
    mTimeOfLastBullet.addMSecs(BULLET_TIME_BETWEEN_FIRE_MILISEC);
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

void PlayerTank::hitted(int damage)
{
    mHealth -= damage;
    emit playerTankHealthChanged(mHealth);
    if(mHealth <= 0){

        emit playerTankDestroyed(mPlayer);
        this->scene()->removeItem(this);
       // delete this;
    }
}

int PlayerTank::health() const
{
    return mHealth;
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

    mIsColliding = false;
    mIsColliding = mCollidingRect.collidingItems().size() == 0 ? false : true;

    if(mIsColliding)
        mCollidingSide = getOrientation();



}

void PlayerTank::multipeButtonsPressed()
{
    bool WASDProcessed = false;

    for(auto &button : mButtonsPressed)
    {
        if(WASDProcessed && (button == UP_BUTTON || button == DOWN_BUTTON
                             || button == LEFT_BUTTON
                             || button == RIGHT_BUTTON))
            continue;

        processKey(button);

        if (button == UP_BUTTON|| button == DOWN_BUTTON
                || button == LEFT_BUTTON
                || button == RIGHT_BUTTON){
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
    //proveravamo da li je udario u zid i ako nije taster moze da se obradi

    if(button == UP_BUTTON)
    {
        if(!mIsColliding || mCollidingSide != Orientation::UP){
//            setOrientation(Orientation::UP);
//            moveBy(0, -speed());
            moveUp(); //radi isto sto i ovo iznad
        }
    }

    else if(button == DOWN_BUTTON)
    {
        if(!mIsColliding || mCollidingSide != Orientation::DOWN){
            moveDown();
        }
    }

    else if (button == LEFT_BUTTON)
    {
        if(!mIsColliding || mCollidingSide != Orientation::LEFT){
            moveLeft();
        }
    }

    else if(button == RIGHT_BUTTON)
    {
        if(!mIsColliding || mCollidingSide != Orientation::RIGHT){
            moveRight();
        }
    }

    else if(button == FIRE_BUTTON)
    {
        if(mTimeOfLastBullet.elapsed() >= BULLET_TIME_BETWEEN_FIRE_MILISEC){
            qreal x=this->x();
            qreal y=this->y();

            Bullet *b=new Bullet(getOrientation(), QPointF(x,y), Tank::Player );
            scene()->addItem(b);
            mTimeOfLastBullet.restart();
        }
    }


}
