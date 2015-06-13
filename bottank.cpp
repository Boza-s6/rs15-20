
#include "bottank.h"
#include "tank.h"
#include <math.h>
#include <iostream>
#include "playertank.h"
#include "bullet.h"


BotTank::BotTank(qreal x, qreal y, Tank::Orientation ori=Orientation::DOWN)
    : Tank(ori, x,y, ":/img/img/player2_tank.png"),
      mTimeOfLastBullet(),
      mFirstTime(true)
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

    int r=BOT_MAX_FIRING_TIME- rand()%1500;

    if(mFirstTime){
        mTimeOfLastBullet.start();
        mTimeOfLastBullet.addMSecs(r + 1);
        mFirstTime = false;
    }

    if(mTimeOfLastBullet.elapsed() >= r){
        qreal x=this->x();
        qreal y=this->y();

        Bullet *b=new Bullet(getOrientation(), QPointF(x,y) );
        scene()->addItem(b);
        mTimeOfLastBullet.restart();
    }


    QList<QGraphicsItem *> Tanks = scene()->items();

    qreal xp=0,yp=0;
    qreal xb=0,yb=0;

    foreach (QGraphicsItem *item, Tanks) {
        if (item == this)
            continue;
        //treba naci player tenk i bota usmeriti ga ka njemu, kako, ne znam

        if (dynamic_cast<PlayerTank*> (item)) {
            //ovo je igrac, usmeri botove ka njemu
            xp=item->x();
            yp=item->y();
            break; //prekini cim ga nadjes
        }
    }
    foreach (QGraphicsItem *item, Tanks) {
        if (item == this){

            //ovo je bot
            xb=item->x();
            yb=item->y();

            qreal xdx, ydx;

            xdx=xb-xp;
            ydx=yb-yp;

            // std::cout<<" - "<<ydx<<std::endl;

            // 5 da ne bi ulazili u beskonacnu petlju vec da ima vremena da se okrene
            if (xdx>=5) {
                mAngle=-90;
                setOrientation(Orientation::LEFT);
            }
            if (xdx<0) {
                mAngle=90;
                setOrientation(Orientation::RIGHT);
            }
            if (ydx>=5) {
                mAngle=0;
                setOrientation(Orientation::UP);
            }
            if (ydx<0) {
                mAngle=180;
                setOrientation(Orientation::DOWN);
            }


        }


    }






    // treba izracunati koja je polivina tenka i dodati/oduzeti jer izlazi iz scene za polovinu, mrzi me sada
    //okrece tenk kad udari u ivicu
    setSpeed(10);
    if (this->x()<0 ){ //levo
        mAngle=90;
    }else if (this->x()>1000){ //desno
        mAngle=-90;
    } else if (this->y()<0 ){ //gore
        mAngle=180;
    } else if (this->y()>700){ //dole
        mAngle=0;
    }

    setRotation(mAngle);
    setPos(mapToParent(0, -(3 + sin(speed()) * 4)));

}

