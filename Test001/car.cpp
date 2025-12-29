#include "car.h"

car::car(QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/car.png"));
    movespeed = 2;
    health = 40;
}

car::car(double move, int hea)
{
    this->setPixmap(QPixmap(":/images/car.png"));
    movespeed = move;
    health = hea;
}

void car::CarMove()
{
    this->moveBy(-movespeed,0);
}

void car::CarDead()
{
    ++CarDeadCheck;
    if(1 == CarDeadCheck)
    {
        CarDeadPoint = QPoint(this->x(),this->y());

        this->setPixmap(QPixmap(":/images/enemy2_down3.png"));
        this->setPos(CarDeadPoint);
        this->movespeed = 0;

    }
    if(2 == CarDeadCheck)
    {
        this->setPixmap(QPixmap(":/images/enemy2_down4.png"));
    }
    if(3 == CarDeadCheck)
    {
        CarDeadCheck = 0;

        this->setPixmap(QPixmap(":/images/car.png"));
        this->setX(1200);
        this->movespeed = 2;
    }
}


