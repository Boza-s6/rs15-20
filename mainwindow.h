#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    QWidget *background;
    Ui::MainWindow *ui;
    QPixmap* m_pPixmap;
    QPalette* m_pPalette;
};

#endif // MAINWINDOW_H
