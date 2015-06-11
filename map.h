#ifndef MAP_H
#define MAP_H
#include <QGraphicsScene>
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <sstream>
#include "brick.h"
#include "solidbrick.h"
#include "fenix.h"

#define FIRST_MAP ":/maps/maps/first.map"
#define SECOND_MAP ":/maps/maps/second.map"
#define THIRD_MAP ":/maps/maps/third.map"

static const int NUM_LINES = 14, NUM_BRICKS_IN_LINE = 20;
static const qreal BRICK_SIZE = 50.0;
//    static const char
//        *FIRST = ":/maps/maps/first.map",
//        *SECOND = ":/maps/maps/second.map",
//        *THIRD = ":/maps/maps/third.map"
//    ;

enum BrickType{
    NO_BRICK = 0,
    BRICK = 1,
    SOLID_BRICK = 2,
    FENIX = 3
};
namespace Map {

    void readMap(QGraphicsScene * scena, const char * map = FIRST_MAP);
}

#endif // MAP_H

