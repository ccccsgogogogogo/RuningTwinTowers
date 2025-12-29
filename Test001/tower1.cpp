#include "tower1.h"

Tower1::Tower1(QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/TwinTowers.jpg"));

    movespeed = 4;
    jumpspeed = 10;
    currentspeedup = 0;
    health = 100;
    shootspeed = 600;
    StepThreeBossMoveSpeed = 0.4;

}

Tower1::Tower1(double move, double jump, int shoot)
{
    movespeed = move;
    jumpspeed = jump;
    shootspeed = shoot;
}

void Tower1::moveLeft()
{
    this->moveBy(-movespeed,0);
}

void Tower1::moveRight()
{
    this->moveBy(movespeed,0);
}

void Tower1::moveDown()
{
    this->moveBy(0,movespeed);
}

void Tower1::moveUp()
{
    this->moveBy(0,-movespeed);
}






