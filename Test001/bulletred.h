#ifndef BULLETRED_H
#define BULLETRED_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>
class BulletRed : public QGraphicsPixmapItem
{

    enum BulletType
    {
        BT_Player,
        BT_Enemy
    };

public:
    explicit BulletRed(QGraphicsPixmapItem *parent = nullptr);
    BulletBlue(QPoint pos,QString imgUrl,BulleBlue::BulletType)
signals:

};

#endif // BULLETRED_H
