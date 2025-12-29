#ifndef SUPPLY_H
#define SUPPLY_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Supply : public QGraphicsPixmapItem
{

public:
    Supply(QGraphicsPixmapItem *parent = nullptr);
    double movespeed;
    void SupplyMove();
signals:

};

#endif // SUPPLY_H
