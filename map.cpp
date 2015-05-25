#include "map.h"


void Map::readMap(QGraphicsScene *scena, const char *map)
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
