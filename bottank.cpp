
#include "bottank.h"
#include "tank.h"
#include <math.h>
#include <iostream>
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

BotTank::BotTank(qreal x, qreal y): Tank(Tank::Orientation::UP, x,y, ":/img/player2_tank.png")
{

}


BotTank::~BotTank()
{

}

void BotTank::advance(int step)
{
    if (!step)
        return;

    // Try not to crash with any other mice
    //! [7]
    QList<QGraphicsItem *> Tanks = scene()->items(QPolygonF()
                                                  << mapToScene(0, 0)
                                                  << mapToScene(-30, -50)
                                                  << mapToScene(30, -50));


    foreach (QGraphicsItem *item, Tanks) {
        if (item == this)
            continue;

        QLineF lineToMouse(QPointF(0, 0), mapFromItem(item, 0, 0));
        qreal angleToMouse = ::acos(lineToMouse.dx() / lineToMouse.length());
        //std::cout<<angleToMouse<<std::endl;


        if (lineToMouse.dy() > 0)
            angleToMouse = TwoPi - angleToMouse;
        angleToMouse = normalizeAngle((Pi - angleToMouse) + Pi / 2);

        if (angleToMouse >= 0 && angleToMouse < Pi / 2) {
            // Rotate right
            mAngle += 90;
        } else if (angleToMouse <= TwoPi && angleToMouse > (TwoPi - Pi / 2)) {
            // Rotate left
            mAngle -= 90;

        }
    }


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


    setRotation(mAngle);
    setPos(mapToParent(0, -(3 + sin(Speed()) * 3)));
}

