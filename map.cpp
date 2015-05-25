#include <QGraphicsScene>
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <sstream>
#include "brick.h"
#include "solidbrick.h"

#define FIRST_MAP ":/maps/first.map"
#define SECOND_MAP ":/maps/second.map"
#define THIRD_MAP ":/maps/third.map"

namespace Map {
    static const int NUM_LINES = 14, NUM_BRICKS_IN_LINE = 20;
    static const qreal BRICK_SIZE = 50.0;
//    static const char
//        *FIRST = ":/maps/first.map",
//        *SECOND = ":/maps/second.map",
//        *THIRD = ":/maps/third.map"
//    ;

    enum BrickType{
        NO_BRICK = 0,
        BRICK = 1,
        SOLID_BRICK = 2
    };

    void readMap(QGraphicsScene * scena, const char * map = FIRST_MAP)
    {
        /*
         * Svaka mapa ja 20 x 14 brojeva koji oznacavaju tip cigle
         * */

        std::string line;

        int brick_type;
        qreal positionX = 0;
        qreal positionY = 0;

        std::ifstream input(map);

        for (int i = 0; i < NUM_LINES; ++i)
        {
            std::getline(input, line);
            std::istringstream iss(line);

            for (int j = 0; j < NUM_BRICKS_IN_LINE; ++j)
            {
                iss >> brick_type;

                switch (brick_type) {
                case BrickType::NO_BRICK:
                    //nista
                    break;
                case BrickType::BRICK:
                    scena->addItem(new Brick(positionX, positionY));
                    break;
                case BrickType::SOLID_BRICK:
                    scena->addItem(new SolidBrick(positionX, positionY));// !!! Dok ne napravi SolidBrick kalsu
                default:
                    break;
                }
                positionX += BRICK_SIZE;
            }
            positionX = 0;
            positionY += BRICK_SIZE;
        }
    }
}
