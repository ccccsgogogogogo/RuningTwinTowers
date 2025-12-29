#include "bulletblue.h"

BulletBlue::BulletBlue(QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent)
{
    MoveSpeed = 5;
}

BulletBlue::BulletBlue(QPoint pos)
{
    this->setPos(pos);
    MoveSpeed = 5;
}

BulletBlue::BulletBlue(QPoint pos,QPixmap pixmap)
{
    this->setPixmap(pixmap);
    this->setPos(pos);
    MoveSpeed = 5;
}
BulletBlue::BulletBlue(QPoint pos,QPixmap pixmap,QPoint dir)
{
    this->setPixmap(pixmap);
    this->setPos(pos);
    this->MoveDir = dir;
    MoveSpeed = 5;
}
void BulletBlue::BulletBlueMove()
{
    this->moveBy(MoveDir.x() * MoveSpeed,MoveDir.y() * MoveSpeed);
}
