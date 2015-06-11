
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
            }
            if (xdx<0) {
                mAngle=90;
            }

            if (ydx>=5) {
                 mAngle=0;
            }
            if (ydx<0) {
                mAngle=180;
            }


        }


    }



        /*
    QList<QGraphicsItem *> Tanks = scene()->items();

    //scene()->items();

    foreach (QGraphicsItem *item, Tanks) {
        if (item == this)
            continue;

        std::cout<<item->
        QLineF lineToMouse(QPointF(0, 0), mapFromItem(item, 0, 0));
        qreal angleToMouse = ::acos(lineToMouse.dx() / lineToMouse.length());
        std::cout<<angleToMouse * 180.0 / Pi<<std::endl;

        mAngle=angleToMouse * 180.0 / Pi;


        if (lineToMouse.dy() > 0)
            angleToMouse = TwoPi - angleToMouse;
        angleToMouse = normalizeAngle((Pi - angleToMouse) + Pi / 2);

        if (angleToMouse >= 0 && angleToMouse < Pi / 2) {
            // Rotate right
            mAngle -= 90;
        } else if (angleToMouse <= TwoPi && angleToMouse > (TwoPi - Pi / 2)) {
            // Rotate left
            mAngle += 90;

        }

    }

*/


        /*
    switch (qrand() % 4 ) {
    case 0:
         mAngle =0;
        break;
    case 1:
         mAngle =90;
        break;
    case 2:
         mAngle =180;
        break;
    case 3:
         mAngle =270;
        break;

    }
*/




        // treba izracunati koja je polivina tenka i dodati/oduzeti jer izlazi iz scene za polovinu, mrzi me sada
        //okrece tenk kad udari u ivicu

        if (this->x()<0 ){ //levo
            mAngle=90;
        }else if (this->x()>1000){ //desno
            mAngle=-90;
        } else if (this->y()<0 ){ //gore
            mAngle=180;
        } else if (this->y()>600){ //dole
            mAngle=0;
        }

        setRotation(mAngle);
        setPos(mapToParent(0, -(3 + sin(Speed()) * 3)));

    }

