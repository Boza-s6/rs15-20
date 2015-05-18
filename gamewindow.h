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

class GameWindow : public QWidget
{
public:
    GameWindow(QWidget *parent = 0);
    ~GameWindow();



private:
    QGraphicsScene * scene;
    QGraphicsView  * view;
    int sceneWidth;
    QTimer *mTimer;


//    std::vector<Tank*> tanks;

};

#endif // GAMEWINDOW_H
