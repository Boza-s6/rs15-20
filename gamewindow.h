#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGraphicsView>
#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QRect>
#include <QGraphicsPixmapItem>
#include "tank.h"
#include <QTimer>
#include "constants.h"

class GameWindow : public QWidget
{
public:
    GameWindow(QWidget *parent = 0);
    ~GameWindow();

private:
    void init();
private:
    QTimer mTimer;
    QGraphicsView  * mView;
    QGraphicsScene * mScene;



//    std::vector<Tank*> tanks;

};

#endif // GAMEWINDOW_H
