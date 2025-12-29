#ifndef BULLETBLUE_H
#define BULLETBLUE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>
class BulletBlue : public QGraphicsPixmapItem
{

public:
    //子弹类型
    enum BulletType
    {
        BT_Player,
        BT_Enemy
    };


    explicit BulletBlue(QGraphicsPixmapItem *parent = nullptr);

    QPoint MoveDir;
    BulletBlue(QPoint pos);
    BulletBlue(QPoint pos,QPixmap pixmap);
    BulletBlue(QPoint pos,QPixmap pixmap,QPoint dir = QPoint(1,0));

    void BulletBlueMove();

    int MoveSpeed;
    ~BulletBlue()
    {

    }
signals:

};

#endif // BULLETBLUE_H
