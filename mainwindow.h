#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include <QFile>
//#include <QMediaPlayer>  ///this doesn't work
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QRect menu;
    QRect begin;
    QRect rank;
    QPixmap medal;
    QPixmap gameover;
    QPixmap again;
    QPixmap ank;
    QPixmap socreboard;
    QPixmap b_pixmap;   //background picture
    QPixmap w_pixmap;   //welcome
    QPixmap c_pixmap;   //general
    QPixmap land;
    QPixmap pip_up;
    QPixmap pip_down;
    QPixmap bird;       //save for bird's pic
    QPixmap number[10];
    QRect r_bird;      //coor. of bird
  //  Ui::MainWindow *ui;

    bool cheat;
    int last;
    void gradesave();
    void gradeload();
    void Rank();
    void reset();
    int distance;       //distance between two pillars
    void drawgrades(int x, int y, int grade_);
    void over();
    bool ifAdd;           //if need to add points
    bool collisionjudge();
    QRect* pipe[6];
    QTimer* timer;
    int land_site;
    int grades; //save the points
    int best_grades;
    int tag;        //which window now
    int bird_tag;
    int l_tag;
    int fly;
    int v,a1,a2;
    int graderank[4]; //
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent* e);
    void mousePressEvent(QMouseEvent *);
    void QTimerEvent(int timerId);
    void welcome();
    void lead();
    void game();
};

#endif // MAINWINDOW_H
