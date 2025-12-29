#ifndef TOWER1_H
#define TOWER1_H

#include <QGraphicsPixmapItem>

class Tower1 : public QGraphicsPixmapItem
{

public:
    Tower1(QGraphicsPixmapItem *parent = nullptr);

    double movespeed;
    double jumpspeed;
    double currentspeedup;
    int health;
    int shootspeed;
    double StepThreeBossMoveSpeed = 0.4;
    Tower1(double move,double jump,int shoot);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
};

#endif // TOWER1_H
