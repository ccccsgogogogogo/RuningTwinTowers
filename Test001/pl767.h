#ifndef PL767_H
#define PL767_H

#include <QGraphicsPixmapItem>

class pl767 : public QGraphicsPixmapItem
{
public:
    pl767(QGraphicsPixmapItem *parent = nullptr);
    double movespeed;
    int health;
    pl767(double move,int hea);
    void plmove();
};

#endif // PL767_H
