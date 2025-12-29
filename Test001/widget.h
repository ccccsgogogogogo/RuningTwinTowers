#ifndef WIDGET_H
#define WIDGET_H
#include "car.h"
#include "pl767.h"
#include "tower1.h"
#include "supply.h"
#include "bulletblue.h"
#include <QTimer>
#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QPoint>
#include <QDebug>
#include <QRect>
#include <QToolButton>
#include <QKeyEvent>
#include <QList>
#include <QProgressBar>
#include <QMediaPlayer>
#include <QLabel>
#include <QDateTime>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    QGraphicsView GameView;
    QGraphicsScene StartScene;
    QGraphicsScene ClassicGameScene;
    QGraphicsScene MultiplayerScene;


    QGraphicsPixmapItem StartBackGround1;
    QGraphicsPixmapItem StartBackGround2;
    QGraphicsPixmapItem ClassicGameBackGround1;
    QGraphicsPixmapItem ClassicGameBackGround2;
    QGraphicsPixmapItem MultiplayerBackGround1;
    QGraphicsPixmapItem MultiplayerBackGround2;

    QGraphicsPixmapItem Plane1Dead;
    QGraphicsPixmapItem Plane2Dead;
    QGraphicsPixmapItem CarDead;



//    QGraphicsPixmapItem StartButton;
//    QGraphicsPixmapItem ExitButton;
    int ClassicGameTowerType;
    int Gravity;
    car mcar;
    pl767 plane;
    pl767 plane1;
    pl767 plane2;
    pl767 planestep3;
    Supply supply;
    Tower1 Player;
    Tower1 StepTwoBoss;
    Tower1 StepThreeBoss;
    car car1;
    int StepThreeEndLabelMoveSpeed;
    int supplyNum;
    int currentplane1;
    int currentplane2;
    int plane1type;
    int plane2type;
    int currentcar;
    int ClassicGameScore;
    int ClassicGameStepNum;
    int addplanecheck;
    int f16firecheck;
    int ClassicGameStepThreeFriendPlaneMoveCheck;
    int ClassicGameStepTwoPlayerTypeChangeCheck;
    int BossMoveCheck1;
    int BossMoveCheck2;
    int BossDeadCheck;
    int BossFireCheck;
    double ClassicGameStepThreeFriendPlaneMoveCheck2;

    QLabel* ClassicGameScorePrint;
    QLabel* supplyPrintLabel;
    QLabel* ClassicGameStepThreeEnd;
    QTimer* SurviveTimer;
    QProgressBar* ClassicGameTowerHealthBar;
    QMediaPlayer ClassicGameAudio1;
    QMediaPlayer ClassicGameAudio2;
    QMediaPlayer ClassicGameAudio3;
    QMediaPlayer GameButtonClickedAudio;

    QTimer* StartTimer;
    QTimer* ClassicGameBackgroundTimer;
    QTimer* ClassicGamePlane_CarMoveTimer;
    QTimer* ClassicGamePlane1DeadTimer;
    QTimer* ClassicGamePlane2DeadTimer;
    QTimer* ClassicGameCarDeadTimer;
    QTimer* ClassicGameStepTwoPlayerTypeChangeTimer;
    QTimer* ClassicGamePlaneShootTimer;
    QTimer* BulletMoveTimer;
    QTimer* AddPlaneTimer;
    QTimer* BgmTimer;
    QTimer* BossMoveTimer;
    QTimer* BossMoveTimer2;
    QTimer* MultiplayerTimer;
    QTimer* StepThreeEndLabelTimer;
    QLineEdit account;
    int accountcheck = 0;
    QToolButton* StartGameButton;
    QToolButton* Exit;
    QToolButton* ClassicGame;
    QToolButton* Multiplayer;
    QToolButton* supplyPrintToolButton;
    QToolButton* Back;
    QToolButton* ClassicGameReloadButton;
    QToolButton* ClassicGameEndButton;
    QToolButton* StopButton;
    QToolButton* GameOption;
    QPushButton* LogIn;
    QPushButton* GetHighestScore;
    int StopButtonIsClicked;
    void StopButtonClicked();
    void GameEndLabelMove();
    QPoint Plane1DeadPoint;
    QPoint Plane2DeadPoint;
    QPoint CarDeadPoint;
    QString PlayerName = "Defaut";
    bool LogInCheck = true;
    int SceneNum;

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);


    Widget(QWidget *parent = nullptr);
    ~Widget();
    QList<int> KeyList;
    QList<int> KeyList2;
    QList<BulletBlue*> BulletList;
    QList<BulletBlue*> BulletList2;
public slots:
    void StartBackgroundMove();
    void GetHighestScoreClicked();
    void StartGameButtonClicked();
    void ExitClicked();
    void BackClicked();
    void GameOptionClicked();
    void ClassicGameClicked();
    void ClassicGameBackgroundMove();
    void ClassicGamePlane_CarMove();
    void ClassicGamePlayerMove();
    void ClassicGamePlane_CarMoveSpeedChange();
    void ClassicGamePlayerHealthCheck();
    void ClassicGameStepTwo();
    void ClassicGameReloadButtonClicked();
    void ClassicGameEndButtonClicked();
    void ClassicGameScoreUpdate();
    void ClassicGameStep3AddPlane();
    void ClassicGameStepThree();
    void ClassicGameStepTwoPlayerTypeChange();
    void StepTowBossMove();
    void StepThreeBossMove();
    void StepTwoBossDead();
    void StepThreeBossDead();
    void BulletShoot();
    void GameEndScoreRecordFile();
    QString GetScore();
    void ClassicGamePlane1Dead();
    void ClassicGamePlane2Dead();
    void ClassicGameCarDead();
    void LogInClicked();
    void MultiplayerClicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
