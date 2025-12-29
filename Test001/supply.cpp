#include "supply.h"

Supply::Supply(QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/bullet_supply.png"));
    movespeed = 1.8;
}

void Supply::SupplyMove()
{
    this->moveBy(-movespeed,0);
}
