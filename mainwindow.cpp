#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
QString dat[3][4]={
    ":/image/bird/up20.png",":/image/bird/up0.png",":/image/bird/up-20.png",":/image/bird/up-90.png",
    ":/image/bird/mid20.png",":/image/bird/mid0.png",":/image/bird/mid-20.png",":/image/bird/mid-90.png",
    ":/image/bird/down20.png",":/image/bird/down0.png",":/image/bird/down-20.png",":/image/bird/down-90.png"
};
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
   ui(new Ui::MainWindow)
{
    QTime t;
    t= QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    ui->setupUi(this);
    tag=1;
    best_grades=0;
    cheat=0;
    for(int i=0;i<4;i++) graderank[i]=0;
    gradeload();

    distance=140;
    a1=5; a2=-5;
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(repaint()));//conect timer and repaint
    begin.setTop(370); begin.setBottom(445); begin.setLeft(35); begin.setRight(170);
    rank.setTop(370); rank.setBottom(445); rank.setLeft(210); rank.setRight(345);
    menu.setTop(400); menu.setBottom(427); menu.setLeft(290); menu.setRight(367);
    socreboard.load(":/image/others/billboard.png");
    b_pixmap.load(":/image/background/day.png");
    w_pixmap.load(":/image/others/start.png");
    land.load(":/image/background/ground.png");
    pip_up.load(":/image/pillar/down.png");
    pip_down.load(":/image/pillar/up.png");
    gameover.load(":/image/others/gameover.png");
    again.load(":/image/others/restart.png");
    ank.load(":/image/others/ranking.png");
    number[1].load(":/image/number/1.png"); number[2].load(":/image/number/2.png"); number[3].load(":/image/number/3.png");
    number[4].load(":/image/number/4.png"); number[5].load(":/image/number/5.png"); number[6].load(":/image/number/6.png");
    number[7].load(":/image/number/7.png"); number[8].load(":/image/number/8.png"); number[9].load(":/image/number/9.png");
    number[0].load(":/image/number/0.png");
    reset();
    this->setFixedSize(385,448);
    this->setWindowTitle("Flappy Bird");
    this->setWindowIcon(QIcon(":/bird.ico"));
}

MainWindow::~MainWindow()
{
delete ui;
}

void MainWindow::reset()
{
    bird_tag=1;
    fly=0;
    ifAdd=0;
    v=0;
    land_site=385;
    l_tag=1;
    grades=0;
    bird.load(":/image/bird/mid0.png");
    r_bird.setTop(240); r_bird.setLeft(95); r_bird.setRight(138); r_bird.setBottom(270);

    int zz=qrand()%150+100-250;
    pipe[0]=new QRect(460,zz,65,250);
    pipe[1]=new QRect(460,zz+250+distance,65,250);
    zz=qrand()%150-150;
    pipe[2]=new QRect(460+220,zz,65,250);
    pipe[3]=new QRect(460+220,zz+250+distance,65,250);
    zz=qrand()%150-150;
    pipe[4]=new QRect(460+220*2,zz,65,250);
    pipe[5]=new QRect(460+220*2,zz+250+distance,65,250);

}
void MainWindow::paintEvent(QPaintEvent *)
{
    switch (tag)
    {
        case 1:
            welcome();
            break;

        case 2:
            lead();
            break;
        case 3:
             game();
             break;
        case 4:
             over();
             break;
        case 5:
                Rank();
                break;
          default:
        break;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
        case Qt::Key_Space:
        {
            if(tag==2)
            {
                tag=3;
                timer->start(70);
            }
            else if(tag==3)
            {
                fly=4; v=10;
            }
        break;
        }
        case Qt::Key_F1:
            if(distance==140) distance=200;
            else if(distance==200) distance=140;
        break;
    case Qt::Key_F2:
            cheat=!cheat;
        break;
    default:
        return ;

    }
}

void MainWindow::mousePressEvent(QMouseEvent *m)
{
    switch(tag)
    {
        case 1:
        {
            if(begin.contains(m->x(),m->y()))
            {
                timer->start(300);
                tag=2;
            }
            else if(rank.contains(m->x(),m->y()))
            {
                last=1;
                tag=5;
                repaint();
            }

            break;
        }
        case 4:
        {
            if(begin.contains(m->x(),m->y()))
            {
                timer->start(300);
                tag=2;
                reset();
            }
            else if(rank.contains(m->x(),m->y()))
            {
                last=4;
                tag=5;
                repaint();
            }

            break;
        }
        case 5:
            if(menu.contains(m->x(),m->y()))
            {
                tag=last;
                repaint();
            }
         break;
    }
}

void MainWindow::welcome()      //welcome tag 1
{
    QPainter painter(this);
    painter.drawPixmap(0,0,w_pixmap);
}

void MainWindow::lead()         //welcome tag 2
{
    switch(l_tag)
    {
    case 1:
        c_pixmap.load(":/image/intro/day/up.png"); l_tag=2; break;
    case 2:
        c_pixmap.load(":/image/intro/day/mid.png"); l_tag=3; break;
    case 3:
        c_pixmap.load(":/image/intro/day/down.png"); l_tag=1; break;
    }
    QPainter painter(this);
    painter.drawPixmap(0,0,c_pixmap);
    c_pixmap.load(":/image/number/0.png");
    painter.drawPixmap(180,100,c_pixmap);
    painter.drawPixmap(0,423,land);
}
void MainWindow::game()     //draw the bird and pipes at beginning
{
    if(!cheat)
    {
        if(collisionjudge())
        {
            timer->stop();
            tag=4;
            best_grades=max(best_grades,grades);
            gradesave();
            repaint();
        }
    }
    QPainter painter(this);
    painter.drawPixmap(0,0,b_pixmap);
    for(int i=0;i<6;i++)
    {
        if(i%2==0)
        painter.drawPixmap(pipe[i]->left(),pipe[i]->top(),pip_up);
        else
        painter.drawPixmap(pipe[i]->left(),pipe[i]->top(),pip_down);

       if(i%2==0)
        {
            if(pipe[i]->right()<r_bird.left()&&!ifAdd)
            {
                ifAdd=1;
                grades++;
 }
        }
        pipe[i]->translate(-8,0);
    }
    if(pipe[0]->right()<0)
    {
        ifAdd=0;
        for(int i=0;i<4;i+=2)
        {
            pipe[i]=pipe[i+2];
            pipe[i+1]=pipe[i+3];
        }
        int zz=qrand()%150-150;
        pipe[4]=new QRect(pipe[2]->left()+220,zz,65,250);
        pipe[5]=new QRect(pipe[3]->left()+220,zz+250+distance,65,250);
    }
    painter.drawPixmap(land_site-385,423,land);
    painter.drawPixmap(land_site,423,land);
    land_site-=5;
    if(land_site<0)
        land_site=384;

    painter.drawPixmap(r_bird.left(),r_bird.top(),bird);
        if(fly>0)
        {
            r_bird.translate(0,-(v+a1/2));
            v+=a1;
            bird.load(dat[bird_tag][0]);
            fly--;
            bird_tag++;
            if(bird_tag==3) bird_tag=0;
        }
        else if(fly==0)
        {
            v=0;
            bird.load(dat[bird_tag][1]);
            fly--;
            bird_tag++;  if(bird_tag==3) bird_tag=0;
        }
        else if(fly<0)
        {
            r_bird.translate(0,-(v+a2/2));
            v+=a2;
            if(fly>=-5)
            bird.load(dat[bird_tag][2]);
            else bird.load(dat[bird_tag][3]);
            fly--;
            bird_tag++;  if(bird_tag==3) bird_tag=0;
        }

        if(r_bird.top()< -2) r_bird.translate(0,10);
        drawgrades(180,100,grades);

}
void MainWindow::gradesave()    //save the rankings
{
    for(int i=0;i<4;i++)
    {
        if(grades>graderank[i])
        {
            for(int j=3;j>i;j--)
                graderank[j]=graderank[j-1];
            graderank[i]=grades;
            break;
        }
    }
    QFile file("rank.b");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    for(int i=0;i<4;i++)
        out<<graderank[i];
}
void MainWindow::gradeload()   //load the rankings
{
    QFile file("rank.b");
    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);
        for(int i=0;i<4;i++)
            in>>graderank[i];
    }
}
void MainWindow::Rank()
    {
        QPainter painter(this);
        painter.drawPixmap(0,0,b_pixmap);
        medal.load(":/image/award/gold.png");  painter.drawPixmap(0,0,medal);
        medal.load(":/image/award/white.png"); painter.drawPixmap(0,62,medal);
        medal.load(":/image/award/silver.png"); painter.drawPixmap(0,124,medal);
        medal.load(":/image/award/bronze.png"); painter.drawPixmap(0,186,medal);
        c_pixmap.load(":/image/others/menu.png");
        painter.drawPixmap(290,400,c_pixmap);
        int t=10;
        for(int i=0;i<4;i++)
        {
            drawgrades(100,t,graderank[i]);
            t+=61;
        }

    }

void MainWindow::drawgrades(int x,int y,int grade_)
    {
        QPainter painter(this);
        if(grade_==0)
        {
            painter.drawPixmap(x,y,number[0]);
        }
        int a=grade_;
        int bite=0;
        while(a)
        {
            a/=10;
            bite++;
        }
        int head=x+bite/2*25;
        a=grade_;
        while(a)
        {
            painter.drawPixmap(head,y,number[a%10]);
            head-=25;
            a/=10;
        }
    }

void MainWindow::over()
    {
        QPainter painter(this);
        painter.drawPixmap(0,0,b_pixmap);
        for(int i=0;i<6;i++)
        {
            if(i%2==0)
            painter.drawPixmap(pipe[i]->left(),pipe[i]->top(),pip_up);
            else
            painter.drawPixmap(pipe[i]->left(),pipe[i]->top(),pip_down);
        }
        painter.drawPixmap(r_bird.left(),r_bird.top(),bird);
        painter.drawPixmap(land_site-385,423,land);
        painter.drawPixmap(land_site,423,land);
        painter.drawPixmap(45,130,socreboard);
        painter.drawPixmap(70,50,gameover);
        painter.drawPixmap(begin.left(),begin.top(),again);
        painter.drawPixmap(rank.left(),rank.top(),ank);
        if(grades>=100)
            medal.load(":/image/award/gold.png");
        else if(grades>=50)
            medal.load(":/image/award/white.png");
        else if(grades>=20)
            medal.load(":/image/award/silver.png");
        else if(grades>=10)
            medal.load(":/image/award/bronze.png");
        if(grades>=10)
        {
            painter.drawPixmap(75,177,medal);
        }

        drawgrades(278,166,grades);
        drawgrades(278,224,best_grades);
    }
bool MainWindow::collisionjudge()      //test if collision
{
    if(r_bird.bottom()>=423) return true;
    for(int i=0;i<6;i++)
    {
        if(r_bird.intersects(*pipe[i]))
        {
            return true;
        }
    }
    return false;
}






