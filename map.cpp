#include <QGraphicsScene>
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <sstream>
#include "brick.h"

namespace Map {
    static const int NUM_LINES = 14, NUM_BRICKS_IN_LINE = 20;
    static const qreal BRICK_SIZE = 50.0;
    enum Maps{
        FIRST = "first.map",
        SECOND = "second.map",
        THIRD = "third.map"
    };
    enum BrickType{
        NO_BRICK = 0,
        BRICK = 1,
        SOLID_BRICK = 2
    };

    void readMap(QGraphicsScene * scena, Maps map = Maps::FIRST)
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
                    scena->addItem(new Brick(positionX, positionY));// !!! Dok ne napravi SolidBrick kalsu
                default:
                    break;
                }
                positionX += BRICK_SIZE;
            }

            positionY += BRICK_SIZE;
        }
    }
}
