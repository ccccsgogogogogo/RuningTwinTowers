#ifndef CAR_H
#define CAR_H
#include <QGraphicsPixmapItem>
#include <QTimer>

class car : public QGraphicsPixmapItem
{

public:
    car(QGraphicsPixmapItem *parent = nullptr);
    double movespeed;
    int health;
    int CarDeadCheck = 0;
    QPoint CarDeadPoint;

    car(double move, int hea);
    void CarMove();
    void CarDead();
};

#endif // CAR_H
