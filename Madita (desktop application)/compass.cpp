#include "compass.h"

#include <QtGui>
#include <QGraphicsItem>
#include <QRect>

Compass::Compass(QGraphicsItem* parent) : QGraphicsItem (parent){}

QRectF Compass::boundingRect() const{
    return QRectF(0,0,30,30);
}

void Compass::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::white);
    painter->drawEllipse(0,0,190,190);
    painter->drawImage(QRect(0,0,190,190), QImage(":/Images/images/kompas.png"));
}
