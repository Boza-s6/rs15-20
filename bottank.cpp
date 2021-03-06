
#include "bottank.h"
#include "tank.h"
#include <math.h>
#include <iostream>
#include "playertank.h"
#include "bullet.h"


BotTank::BotTank(qreal x, qreal y, Tank::Orientation ori=Orientation::DOWN, int health)
    : Tank(ori, x,y, ":/img/img/player2_tank.png", health),
      mTimeOfLastBullet(), isDone(false)
{
    setRotation(getAngleFromOrientation(ori));
    mTimeOfLastBullet.start();
    mTimeOfLastBullet.addMSecs(BOT_MAX_FIRING_TIME + 1);

}


BotTank::~BotTank()
{

}
//kada je bot pogodjen
void BotTank::hitted(int damage)
{
    //smanjenje helta i emitovanje signala radi dodavanja novog bota
    mHealth -= damage;
    if(mHealth <= 0 && !isDone){

        emit botKilled();
        hide();
        isDone = true;
        deleteLater();
    }

}

void BotTank::advance(int step)
{
    if (!step || isDone)
        return;

    //random vreme koje se generise radi random ispucavanja metkova
    int r=BOT_MAX_FIRING_TIME- rand()%1500;

    //ako je isteklo vreme ispaljuje se novi metak
    if(mTimeOfLastBullet.elapsed() >= r){
        qreal x=this->x();
        qreal y=this->y();

        Bullet *b=new Bullet(getOrientation(), QPointF(x,y), Tank::Bot );
        scene()->addItem(b);
        mTimeOfLastBullet.restart();
    }

    //sudaranje sa ostalim item-ima i random kretanje
    mIsColliding = false;
    mIsColliding = mCollidingRect.collidingItems().size() == 0 ? false : true;

    bool isCollidingWithBullet =false;
    for(auto item : mCollidingRect.collidingItems()){
        if(dynamic_cast<Bullet*>(item)){
            isCollidingWithBullet = true;
            break;
        }
    }
    if(isCollidingWithBullet)
        mIsColliding = false;

    if(mIsColliding)
        mCollidingSide = getOrientation();

    if(!mIsColliding){
        switch (getOrientation()) {
        case Orientation::UP:
            moveUp();
            break;
        case Orientation::DOWN:
            moveDown();
            break;
        case Orientation::LEFT:
            moveLeft();
            break;
        case Orientation::RIGHT:
            moveRight();
            break;
        default:
            break;
        }
    }
    int rand_num = rand()%4;
    if(mIsColliding){
        if(mCollidingSide != Orientation::UP && rand_num == 0)
            moveUp();
        else if(mCollidingSide != Orientation::DOWN  && rand_num == 1)
            moveDown();
        else if(mCollidingSide != Orientation::LEFT  && rand_num == 2)
            moveLeft();
        else if(mCollidingSide != Orientation::RIGHT  && rand_num == 3)
            moveRight();
    }
}

