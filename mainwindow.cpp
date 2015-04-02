#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pPalette	= new QPalette();
    m_pPixmap	= new QPixmap("img/bg.png");

    m_pPalette->setBrush(QPalette::Background,QBrush(*m_pPixmap));
    setPalette(*m_pPalette);

    //Exit, 1 Player, 2 Players btn img
    QIcon exit;
    QIcon player;
    QIcon players;

    exit.addFile(QString::fromUtf8("img/exit.jpg"), QSize(), QIcon::Normal, QIcon::Off);
    player.addFile(QString::fromUtf8("img/player1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
    players.addFile(QString::fromUtf8("img/player2.jpg"), QSize(), QIcon::Normal, QIcon::Off);

    ui->btn_exit->setIcon(exit);
    ui->btn_1player->setIcon(player);
    ui->btn_2players->setIcon(players);
    ui->btn_exit->setIconSize(QSize(156, 52));
    ui->btn_1player->setIconSize(QSize(156, 52));
    ui->btn_2players->setIconSize(QSize(156, 52));
}

//kad se prozor resizuje da se scalira slika
void MainWindow::resizeEvent (QResizeEvent* event)
{
    m_pPalette->setBrush(QPalette::Background,QBrush(m_pPixmap->scaled(width(),height())));
    setPalette(*m_pPalette);
};

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_exit_clicked()
{
    close();
}

void MainWindow::on_btn_1player_clicked()
{
    //TODO: implementirati osobinu, close radi provere ispravnosti
    close();
}

void MainWindow::on_btn_2players_clicked()
{
    //TODO: implementirati osobinu, close radi provere ispravnosti
    close();
}
