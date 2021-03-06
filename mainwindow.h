#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "constants.h"
#include "gamewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent (QResizeEvent* event);
private slots:
    void on_btn_1player_clicked();
    void on_btn_2players_clicked();
    void on_btn_exit_clicked();
    void mPlayerKilled();
    void mFenixKilled();
private:
    GameWindow *mBackground;
    QWidget *tmp;
    Ui::MainWindow *ui;
    QPixmap* m_pPixmap;
    QPalette* m_pPalette;
};

#endif // MAINWINDOW_H
