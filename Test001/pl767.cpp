#include "pl767.h"

pl767::pl767(QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/plane767.png"));
    movespeed = 5;
    health = 60;
}

pl767::pl767(double move,int hea)
{
    this->setPixmap(QPixmap(":/images/plane767.png"));
    movespeed = move;
    health = hea;
}

void pl767::plmove()
{
    this->moveBy(-movespeed,0);
}
