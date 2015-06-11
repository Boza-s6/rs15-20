#include "map.h"
#include <iostream>

void Map::readMap(QGraphicsScene *scena, const char *map)
{
    /*
     * Svaka mapa ja 20 x 14 brojeva koji oznacavaju tip cigle
     * */
    static qreal const EMPTY_SIZE = 25;
    static qreal const BRICK_SIZE = Brick(0,0).boundingRect().width();
    static qreal const STONE_SIZE = SolidBrick(0,0).boundingRect().width();
    static qreal const FENIX_SIZE = Fenix(0, 0).boundingRect().width();

    static int const NUM_BRICKS_IN_LINE = 40;
    static int const NUM_LINES = 28;

//    std::cout << BRICK_SIZE << " " << NUM_LINES << " " << NUM_BRICKS_IN_LINE << std::endl;

    std::string line;

    int brick_type;
    qreal positionX = 0;
    qreal positionY = 0;

    std::ifstream input(map);

    bool fenix = false;
    bool nova_linija_posle_fenixa = false;

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
                positionX += EMPTY_SIZE;
                break;
            case BrickType::BRICK:
                scena->addItem(new Brick(positionX, positionY));
                positionX += BRICK_SIZE;
                break;
            case BrickType::SOLID_BRICK:
                scena->addItem(new SolidBrick(positionX, positionY));
                positionX +=STONE_SIZE;
                break;
            case BrickType::FENIX:
                if(fenix == false){
                    scena->addItem(new Fenix(positionX, positionY));
                    positionX += FENIX_SIZE;
                    fenix = true;
                    break;
                }
                if(nova_linija_posle_fenixa){
                    positionX += FENIX_SIZE/2;
                }
                continue;
            default:
                break;
            }
        }
        if(fenix)
            nova_linija_posle_fenixa = true;
        positionX = 0;
        positionY += BRICK_SIZE;
    }
}
