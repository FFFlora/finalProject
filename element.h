#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>
#include <QVector>
#include <QPainter>
#include <QPixmap>

class element : public QObject
{
    Q_OBJECT
public:
    explicit element(QObject *parent = 0);
    virtual void draw(QPainter *)=0;
    virtual void logic()=0;//used to control the elements movement
    void setRectangle(QRectF);
    void setRectangle(qreal,qreal,qreal,qreal);
    QRectF& getBindRectangle();
    void addFrames(QPixmap);
    void clearAllFrames();
    void setEnabled(bool);
protected:
    QRectF bindRectangle;
    int framesCount;
    QVector<QPixmap> pixmapList;
    bool enabled;
signals:

public slots:

};

#endif // ELEMENT_H
