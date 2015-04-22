#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include <QDesktopWidget>
#include "gamewindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pPalette	= new QPalette();
    m_pPixmap	= new QPixmap(":/img/bg.png");

    m_pPalette->setBrush(QPalette::Background,QBrush(*m_pPixmap));
    setPalette(*m_pPalette);

    background = new GameWindow();
    //za test rezim
    //ui->btn_1player->click();
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
    QWidget * tmp = this->centralWidget();
    setCentralWidget(background);
    background = tmp;
    background->setParent(0);
}

void MainWindow::on_btn_2players_clicked()
{
    //TODO: implementirati osobinu, close radi provere ispravnosti
    close();
}
