#ifndef BIRD_H
#define BIRD_H

#include "element.h"
#include <qmath.h>
#include <QList>

class Bird : public element
{
    Q_OBJECT
private:
    int curFrame;
    int elapsedFrame;
    qreal vy;
    QList<element*> *elementList;
public:
    explicit Bird(QList<element*>*,QObject *parent = 0);
    void draw(QPainter *);
    void logic();
    void birdUp();
    void setVy(qreal);
signals:
    void birdDead();
public slots:

};

#endif // BIRD_H
