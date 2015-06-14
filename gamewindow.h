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
#include <QFont>
#include <QGraphicsTextItem>

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    GameWindow(QWidget *parent = 0);
    ~GameWindow();
public slots:
    void mPlayerTankHealthChanged(int health);
private:
    void init();
private:
    QTimer mTimer;
    QGraphicsView  * mView;
    QGraphicsScene * mScene;
    QGraphicsTextItem mText;



//    std::vector<Tank*> tanks;

};

#endif // GAMEWINDOW_H
