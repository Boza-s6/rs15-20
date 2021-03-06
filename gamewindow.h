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
#include "bottank.h"
#include "playertank.h"
#include "fenix.h"
#include <QtMultimedia>

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    GameWindow(QWidget *parent = 0);
    ~GameWindow();
public slots:
    void mPlayerTankHealthChanged(int health);
    void playerKilled();
    void mbotKilled();
    void fenixKilled();
signals:
    void notifyPlayerKilled();
    void notifyFenixKilled();
private:
    void init();
    void deinit();
private:
    QTimer mTimer;
    QGraphicsView  * mView;
    QGraphicsScene * mScene;
    QGraphicsTextItem mText;
    int mPlayerNumLife;  //broj zivota playera
    int mBotReserve;
    PlayerTank *mPlayer;
    Fenix *mFenix;
    int mLvl;
    QMediaPlayer * mMusic;


//    std::vector<Tank*> tanks;

};

#endif // GAMEWINDOW_H
