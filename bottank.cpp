
#include "bottank.h"
#include "tank.h"
#include <math.h>
#include <iostream>
#include "playertank.h"
static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

BotTank::BotTank(qreal x, qreal y, Tank::Orientation ori=Orientation::DOWN): Tank(ori, x,y, ":/img/player2_tank.png")
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
                setOrientation(Orientation::LEFT);
            }
            if (xdx<0) {
                setOrientation(Orientation::RIGHT);
            }

            if (ydx>=5) {
                setOrientation(Orientation::UP);
            }
            if (ydx<0) {
                setOrientation(Orientation::DOWN);
            }


        }


    }




    // treba izracunati koja je polivina tenka i dodati/oduzeti jer izlazi iz scene za polovinu, mrzi me sada
    //okrece tenk kad udari u ivicu

    if (this->x()<0 ){ //levo
        setOrientation(Orientation::LEFT);
    }else if (this->x()>1000){ //desno
        setOrientation(Orientation::RIGHT);
    } else if (this->y()<0 ){ //gore
        setOrientation(Orientation::UP);
    } else if (this->y()>600){ //dole
        setOrientation(Orientation::DOWN);
    }

    setRotation(mAngle);
    move();

}

void BotTank::move()
{
    switch (getOrientation()) {
    case Orientation::UP:
        Tank::moveBy(0, -speed());
        break;
    case Orientation::DOWN:
        Tank::moveBy(0, speed());
        break;
    case Orientation::LEFT:
        Tank::moveBy(-speed(), 0);
        break;
    case Orientation::RIGHT:
        Tank::moveBy(speed(), 0);
        break;
    default:
        break;
    }
}
