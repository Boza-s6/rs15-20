#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //moguce je da ce te morati da promenite putanju da odgovara vama
    //moja je: C:/Users/lenovo/Desktop/FenixTanks/img/bg.png

    m_pPalette	= new QPalette();
    m_pPixmap		= new QPixmap("C:/Users/lenovo/Desktop/FenixTanks/img/bg.png");

    m_pPalette->setBrush(QPalette::Background,QBrush(*m_pPixmap));
    setPalette(*m_pPalette);

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

void MainWindow::on_btnClose_clicked()
{
    close();
}
