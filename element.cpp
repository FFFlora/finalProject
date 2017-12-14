#include "element.h"

element::element(QObject *parent) :
    QObject(parent)
{
    framesCount=0;
    enabled=true;
}

void element::addFrames(QPixmap pixmap)
{
    if (pixmap.isNull()) return;
    pixmapList.append(pixmap);
    framesCount++;
}

void element::clearAllFrames()
{
    pixmapList.clear();
    framesCount=0;
}

QRectF& element::getBindRectangle()
{
    return bindRectangle;
}

void element::setRectangle(qreal x, qreal y, qreal w, qreal h)
{
    bindRectangle.setRect(x,y,w,h);
}

void element::setRectangle(QRectF rect)
{
    bindRectangle=rect;
}

void element::setEnabled(bool ifEnabled)
{
    enabled=ifEnabled;
}
