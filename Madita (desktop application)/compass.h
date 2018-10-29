#ifndef COMPASS_H
#define COMPASS_H

#include <QGraphicsItem>

class Compass : public QGraphicsItem
{
public:
    Compass(QGraphicsItem* parent = nullptr);


protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // COMPASS_H
