
#include "bottank.h"
#include "tank.h"
#include <math.h>
#include <iostream>
#include "playertank.h"
//static const double Pi = 3.14159265358979323846264338327950288419717;
//static double TwoPi = 2.0 * Pi;

BotTank::BotTank(qreal x, qreal y, Tank::Orientation ori=Orientation::DOWN)
    : Tank(ori, x,y, ":/img/img/player2_tank.png")
{
    setRotation(getAngleFromOrientation(ori));

}


BotTank::~BotTank()
{

}

void BotTank::advance(int step)
{
    if (!step)
        return;

    mIsColliding = false;
    mIsColliding = mCollidingRect.collidingItems().size() == 0 ? false : true;

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

