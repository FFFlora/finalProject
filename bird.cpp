#include "bird.h"

Bird::Bird(QList<element *>* lpList, QObject *parent) :
    element(parent)
{
    elementList=lpList;
    curFrame=0;
    elapsedFrame=0;
    vy=2.0;
}

void Bird::setVy(qreal _vy)
{
    vy=_vy;
}

void Bird::birdUp()
{
    vy=-7.0;
}

void Bird::draw(QPainter *painter)
{
    painter->save();
    painter->translate(bindRectangle.center());
    painter->rotate(qAtan2(vy,6)*180.0/3.14159);
    painter->translate(-bindRectangle.center());
    painter->drawPixmap(bindRectangle.topLeft(),pixmapList[curFrame]);
    painter->restore();
}

void Bird::logic()
{
    if (!enabled)
        return;
    bindRectangle.translate(0.0,vy);
    vy+=0.5;
    if (bindRectangle.y()<2.0)
        emit birdDead();
    for (element *e:*elementList)
        if (e!=this)
            if (bindRectangle.intersects(e->getBindRectangle()))
                emit birdDead();
    elapsedFrame++;
    if (elapsedFrame%3==0)
        curFrame++;
    if (curFrame==framesCount)
    {
        curFrame=0;
        elapsedFrame=0;
    }
}
