#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/plane767.png"));
    this->setWindowTitle("RunningTowers");
    this->setFixedSize(1152,630);

    accountcheck = 0;
    SceneNum = 0;
    Gravity = 10;
    GameView.setSceneRect(QRect(0,0,1152,630));
    GameView.setParent(this);
    StartScene.setSceneRect(QRect(0,0,1152,630));


    StartBackGround1.setPixmap(QPixmap(":/images/start.jpg"));
    StartBackGround2.setPixmap(QPixmap(":/images/start.jpg"));

    StartScene.addItem(&StartBackGround2);
    StartScene.addItem(&StartBackGround1);

    StartBackGround1.setPos(0,0);
    StartBackGround2.setPos(1152,0);

    GameButtonClickedAudio.setParent(this);
    GameButtonClickedAudio.setMedia(QUrl("qrc:/music/opendoor.mp3"));




    StartTimer = new QTimer(this);
    StartTimer->start(10);

    StartScene.addItem(&mcar);
    StartScene.addItem(&plane);

    mcar.setPos(500,580);
    plane.setPos(700,200);
    plane.setScale(0.5);
    mcar.setScale(0.5);


    StartGameButton = new QToolButton();
    Exit = new QToolButton();
    ClassicGame = new QToolButton();
    Multiplayer = new QToolButton();
    Back = new QToolButton();
    GameOption = new QToolButton();
    LogIn = new QPushButton();
    GetHighestScore = new QPushButton();

    LogIn->setText("账号");
    LogIn->move(10,10);
    LogIn->resize(100,40);
    GetHighestScore->setText("历史最高分");
    GetHighestScore->move(10,60);
    GetHighestScore->resize(100,40);

    Back->setIcon(QIcon(":/images/Back.jpg"));
    ClassicGame->setIcon(QIcon(":/images/ClassicGame.jpg"));
    Multiplayer->setIcon(QIcon(":/images/Multiplayer.jpg"));
    Exit->setIcon(QIcon(":/images/ExitButto.jpg"));
    StartGameButton->setIcon(QIcon(":/images/StartButton.jpg"));
    GameOption->setIcon(QIcon(":/images/GameOptionButton.jpg"));

    StartScene.addWidget(Back);
    StartScene.addWidget(ClassicGame);
    StartScene.addWidget(Multiplayer);
    StartScene.addWidget(Exit);
    StartScene.addWidget(StartGameButton);
    StartScene.addWidget(GameOption);
    StartScene.addWidget(LogIn);
    StartScene.addWidget(GetHighestScore);
    Exit->setIconSize(QSize(237,73));
    StartGameButton->setIconSize(QSize(248,63));
    Multiplayer->setIconSize(QSize(310,70));
    ClassicGame->setIconSize(QSize(292,75));
    Back->setIconSize(QSize(180,73));
    GameOption->setIconSize(QSize(300,80));

    Exit->move(457,300);
    StartGameButton->move(452,200);
    ClassicGame->move(430,220);
    Multiplayer->move(421,250);
    Back->move(486,350);
    GameOption->move(426,250);

    StartGameButton->setAutoRaise(true);
    Exit->setAutoRaise(true);
    Back->setAutoRaise(true);
    ClassicGame->setAutoRaise(true);
    Multiplayer->setAutoRaise(true);
    GameOption->setAutoRaise(true);

    GameOption->hide();
    ClassicGame->hide();
    Back->hide();
    Multiplayer->hide();

    connect(StartTimer,&QTimer::timeout,this,&Widget::StartBackgroundMove);
    connect(GetHighestScore,&QPushButton::clicked,this,&Widget::GetHighestScoreClicked);
    connect(Exit,&QToolButton::clicked,this,&Widget::ExitClicked);
    connect(StartGameButton,&QToolButton::clicked,this,&Widget::StartGameButtonClicked);
    connect(Back,&QToolButton::clicked,this,&Widget::BackClicked);
    connect(ClassicGame,&QToolButton::clicked,this,&Widget::ClassicGameClicked);
    connect(Multiplayer,&QToolButton::clicked,this,&Widget::MultiplayerClicked);

    Player.shootspeed = 600;
    f16firecheck = 0;

    currentcar = 0;
    currentplane1 = 0;
    currentplane2 = 0;
    ClassicGameStepThreeFriendPlaneMoveCheck = 0;

    ClassicGameStepNum = 1;

    ClassicGameBackGround1.setPixmap(QPixmap(":/images/ClassicGameBackground.jpg"));
    ClassicGameBackGround2.setPixmap(QPixmap(":/images/ClassicGameBackground.jpg"));

    ClassicGameAudio1.setParent(this);
    ClassicGameAudio1.setMedia(QUrl("qrc:/music/view~.mp3"));
    ClassicGameAudio2.setParent(this);
    ClassicGameAudio2.setMedia(QUrl("qrc:/music/dongji~.mp3"));
    ClassicGameAudio3.setParent(this);
    ClassicGameAudio3.setMedia(QUrl("qrc:/music/mus.mp3"));

    ClassicGameAudio1.setVolume(10);
    ClassicGameAudio2.setVolume(10);
    ClassicGameAudio3.setVolume(10);

    supplyNum = 30;

    ClassicGameScore = 0;

    ClassicGameScorePrint = new QLabel();
    ClassicGameScorePrint->setText("ur score: " + QString::number(ClassicGameScore));
    supplyPrintLabel = new QLabel();
    supplyPrintLabel->setText(QString::number(supplyNum));

    ClassicGameTowerType = 1;

    ClassicGameTowerHealthBar = new QProgressBar;
    ClassicGameTowerHealthBar->setRange(0,100);
    ClassicGameTowerHealthBar->setValue(100);
    ClassicGameTowerHealthBar->setOrientation(Qt::Horizontal);
    ClassicGameTowerHealthBar->move(0,150);

    StopButtonIsClicked = 0;
    StopButton = new QToolButton();

    ClassicGameReloadButton = new QToolButton();
    ClassicGameEndButton = new QToolButton();
    supplyPrintToolButton = new QToolButton();

    ClassicGameReloadButton->setIcon(QIcon(":/images/again.png"));
    ClassicGameEndButton->setIcon(QIcon(":/images/gameover.png"));
    StopButton->setIcon(QIcon(":/images/pause_nor.png"));
    supplyPrintToolButton->setIcon(QIcon(":/images/bullet_supply.png"));

    ClassicGameReloadButton->setIconSize(QSize(300,41));
    ClassicGameEndButton->setIconSize(QSize(300,41));
    StopButton->setIconSize(QSize(60,45));
    ClassicGameScorePrint->resize(1000,35);

    ClassicGameScorePrint->setStyleSheet("background-color: rgb(44, 86, 173, 0)");
    StopButton->setStyleSheet("background-color: rgb(44, 86, 173, 0)");
    supplyPrintLabel->resize(1000,35);
    supplyPrintLabel->setStyleSheet("background-color: rgb(44, 86, 173, 0)");
    supplyPrintToolButton->setStyleSheet("background-color: rgb(44, 86, 173, 0)");
    supplyPrintToolButton->setIconSize(QSize(29,44));

    QFont w;
    w.setPointSize(14);
    ClassicGameScorePrint->setFont(w);
    supplyPrintLabel->setFont(w);

    ClassicGameReloadButton->move(426,310);
    ClassicGameEndButton->move(426,400);
    StopButton->move(5,50);
    ClassicGameScorePrint->move(100,50);
    supplyPrintLabel->move(70,150);
    supplyPrintToolButton->move(20,180);

    ClassicGameReloadButton->hide();
    ClassicGameEndButton->hide();
    StopButton->show();
    ClassicGameScorePrint->show();
    supplyPrintLabel->show();

    ClassicGameReloadButton->setAutoRaise(true);
    ClassicGameEndButton->setAutoRaise(true);
    StopButton->setAutoRaise(true);


    QFont w2;
    w2.setPointSize(40);

    ClassicGameStepThreeEnd = new QLabel();
    ClassicGameStepThreeEnd->setFont(w2);
    ClassicGameStepThreeEnd->resize(1000,300);
    ClassicGameStepThreeEnd->move(210,-180);
    ClassicGameStepThreeEnd->hide();
    ClassicGameStepThreeEnd->setStyleSheet("background-color: rgb(44, 86, 173, 0)");
    ClassicGameStepThreeEnd->setText("Game Over");

    ClassicGameScene.addItem(&ClassicGameBackGround1);
    ClassicGameScene.addItem(&ClassicGameBackGround2);
    ClassicGameScene.addItem(&StepTwoBoss);
    ClassicGameScene.addItem(&StepThreeBoss);
    ClassicGameScene.addItem(&plane1);
    ClassicGameScene.addItem(&plane2);
    ClassicGameScene.addItem(&Player);
    ClassicGameScene.addItem(&car1);
    ClassicGameScene.addItem(&supply);
    ClassicGameScene.addWidget(StopButton);
    ClassicGameScene.addItem(&planestep3);
    ClassicGameScene.addWidget(ClassicGameTowerHealthBar);
    ClassicGameScene.addWidget(ClassicGameReloadButton);
    ClassicGameScene.addWidget(ClassicGameEndButton);
    ClassicGameScene.addWidget(ClassicGameScorePrint);
    ClassicGameScene.addWidget(supplyPrintToolButton);
    ClassicGameScene.addWidget(supplyPrintLabel);
    ClassicGameScene.addWidget(ClassicGameStepThreeEnd);

    planestep3.hide();


    StepTwoBoss.setPixmap(QPixmap(":/images/Tower2.jpg"));

    supply.setPos(1500,250);
    car1.setPos(850,578);
    car1.setScale(0.5);
    Player.setPos(300,320);
    Player.setScale(0.5);
    plane1.setScale(0.5);
    plane1.setPos(1500,500);
    plane2.setScale(0.5);
    plane2.setPos(700,100);
    planestep3.setPos(-220,280);
    planestep3.setScale(0.5);
    StepThreeBoss.setScale(0.55);
    StepThreeBoss.setPos(1200,150);
    StepTwoBoss.setScale(0.5);
    StepTwoBoss.setPos(1200,220);


    ClassicGameBackGround1.setPos(0,0);
    ClassicGameBackGround2.setPos(1152,0);

    ClassicGameBackgroundTimer = new QTimer(this);
    ClassicGamePlane_CarMoveTimer = new QTimer(this);
    SurviveTimer = new QTimer(this);
    ClassicGamePlane1DeadTimer = new QTimer(this);
    ClassicGamePlane2DeadTimer = new QTimer(this);
    ClassicGameCarDeadTimer = new QTimer(this);
    ClassicGameStepTwoPlayerTypeChangeTimer = new QTimer(this);
    StepThreeEndLabelTimer = new QTimer(this);

    ClassicGamePlaneShootTimer = new QTimer(this);
    BulletMoveTimer = new QTimer(this);
    AddPlaneTimer = new QTimer(this);
    BgmTimer = new QTimer(this);
    BossMoveTimer = new QTimer(this);
    BossMoveTimer2 = new QTimer(this);
    connect(LogIn,&QPushButton::clicked,this,&Widget::LogInClicked);
    connect(ClassicGameBackgroundTimer,&QTimer::timeout,this,&Widget::ClassicGameBackgroundMove);
    connect(ClassicGameBackgroundTimer,&QTimer::timeout,this,&Widget::ClassicGamePlayerMove);
    connect(ClassicGameBackgroundTimer,&QTimer::timeout,this,&Widget::ClassicGamePlane_CarMove);
    connect(ClassicGamePlane_CarMoveTimer,&QTimer::timeout,this,&Widget::ClassicGamePlane_CarMoveSpeedChange);
    connect(ClassicGameBackgroundTimer,&QTimer::timeout,this,&Widget::ClassicGamePlayerHealthCheck);
    connect(ClassicGameReloadButton,&QToolButton::clicked,this,&Widget::ClassicGameReloadButtonClicked);
    connect(ClassicGameEndButton,&QToolButton::clicked,this,&Widget::ClassicGameEndButtonClicked);
    connect(StopButton,&QToolButton::clicked,this,&Widget::StopButtonClicked);
    connect(GameOption,&QToolButton::clicked,this,&Widget::GameOptionClicked);
    connect(SurviveTimer,&QTimer::timeout,this,&Widget::ClassicGameScoreUpdate);
    connect(BgmTimer,&QTimer::timeout,[this](){
        ClassicGameAudio3.play();
    });


    connect(ClassicGamePlaneShootTimer,&QTimer::timeout,this,&Widget::Widget::BulletShoot);
    connect(BulletMoveTimer,&QTimer::timeout,[this](){
        QRect Plane1Area = QRect(plane1.x(),plane1.y(),plane1.pixmap().width()/2,plane1.pixmap().height()/2);
        QRect Plane2Area = QRect(plane2.x(),plane2.y(),plane2.pixmap().width()/2,plane2.pixmap().height()/2);
        QRect CarArea = QRect(car1.x(),car1.y(),car1.pixmap().width()/2,car1.pixmap().height()/2);
        QRect StepTwoBossArea = QRect(StepTwoBoss.x(),StepTwoBoss.y(),StepTwoBoss.pixmap().width()/2,StepTwoBoss.pixmap().height()/2);
        QRect StepThreeBossArea = QRect(StepThreeBoss.x(),StepThreeBoss.y(),StepThreeBoss.pixmap().width()/2,StepThreeBoss.pixmap().height()/2);

        for(auto bullet : BulletList)
        {
            bullet->BulletBlueMove();
            if(bullet->x() > 1140)
            {
                BulletList.removeOne(bullet);
                ClassicGameScene.removeItem(bullet);

            }

            QPoint BulletPoint = QPoint(bullet->x() + bullet->pixmap().width()/2,bullet->y());
            if(Plane1Area.contains(BulletPoint) && bullet->x() <= 1130)
            {

                plane1.health-=20;
                BulletList.removeOne(bullet);
                ClassicGameScene.removeItem(bullet);

                if(plane1.health<=0)
                {
                    ClassicGamePlane1Dead();

                    ClassicGameScore += 3;
                    ClassicGameAudio1.play();

                    plane1.setX(1350);
                    plane1.health = 60;
                    if(plane1.y() + 40 > 420)
                    {
                        plane1.setY(plane2.y() - 380);
                    }
                    else
                    {
                        plane1.setY(plane2.y() + 40);
                    }
                    if(1 == plane1type && ClassicGameStepNum >= 2)
                    {
                        plane1.setPixmap(QPixmap(":/images/f16.png"));
                        ++plane1type;
                        plane1.setScale(0.3);
                    }

                }
            }

            if(Plane2Area.contains(BulletPoint) && bullet->x() <= 1130)
            {
                plane2.health-=20;
                BulletList.removeOne(bullet);
                ClassicGameScene.removeItem(bullet);

                if(plane2.health<=0)
                {
                    ClassicGamePlane2Dead();

                    ClassicGameScore += 3;
                    ClassicGameAudio2.play();

                    plane2.setX(1350);
                    plane2.health = 60;
                    if(plane2.y() + 160 > 450)
                    {
                        plane2.setY(plane2.y() - 290);
                    }
                    else
                    {
                        plane2.setY(plane2.y() + 160);
                    }
                    if(1 == plane2type && ClassicGameStepNum >= 2)
                    {
                        plane2.setPixmap(QPixmap(":/images/f16.png"));
                        ++plane2type;
                        plane2.setScale(0.3);
                    }

                }
            }

            if(CarArea.contains(BulletPoint) && bullet->x() <= 1130)
            {
                car1.health-=20;
                ClassicGameScene.removeItem(bullet);
                BulletList.removeOne(bullet);

                if(car1.health<=0)
                {
                    ClassicGameCarDead();

                    ClassicGameScore += 1;
                    ClassicGameAudio2.play();

                    car1.setX(1200);
                    car1.health = 40;
                }
            }
            if(StepTwoBossArea.contains(BulletPoint) && bullet->x() <= 1130)
            {
                ClassicGameScene.removeItem(bullet);
                BulletList.removeOne(bullet);

                StepTwoBoss.health -= 5;
                if(StepTwoBoss.health <= 0)
                {
                    StepTwoBossDead();
                }
            }
            if(StepThreeBossArea.contains(BulletPoint) && bullet->x() <= 1130)
            {
                ClassicGameScene.removeItem(bullet);
                BulletList.removeOne(bullet);

                StepThreeBoss.health -= 1;
                if(StepThreeBoss.health <= 0)
                {
                    StepThreeBossDead();
                }
            }
        }
        for(auto bullet : BulletList2)
        {
            bullet->BulletBlueMove();
            if(bullet->x() < 0 || bullet->y() < 0 || bullet->y() > 630)
            {
                BulletList2.removeOne(bullet);
                ClassicGameScene.removeItem(bullet);

            }
            QPoint BulletPoint = QPoint(bullet->x() + bullet->pixmap().width()/2,bullet->y());
            QRect PlayerArea = QRect(Player.x(),Player.y(),Player.pixmap().width()/2,Player.pixmap().height()/2);
            QRect FriendPlaneArea = QRect(planestep3.x(),planestep3.y(),planestep3.pixmap().width()/2,planestep3.pixmap().height()/2);

            if(PlayerArea.contains(BulletPoint))
            {
                BulletList2.removeOne(bullet);
                ClassicGameScene.removeItem(bullet);


                Player.health -= 5;
                ClassicGameTowerHealthBar->setValue(Player.health);
            }
            if(FriendPlaneArea.contains(BulletPoint))
            {
                BulletList2.removeOne(bullet);
                ClassicGameScene.removeItem(bullet);

                Player.health -= 3;
                ClassicGameTowerHealthBar->setValue(Player.health);
            }

        }
    });


    addplanecheck = 0;

    GameView.setScene(&StartScene);
    GameView.setParent(this);
    GameView.show();

    Player.show();

    StartScene.addWidget(&account);
    account.move(120,20);
    account.resize(150,25);
    account.hide();
}
//3
void Widget::keyPressEvent(QKeyEvent *event)
{
    if(ClassicGameTowerType != 3)
    {
        switch(event->key())
        {
            case Qt::Key_W: if((Player.y() >= 320 && 1 == ClassicGameTowerType) || (Player.y() >=530 && 2 == ClassicGameTowerType)) Player.currentspeedup = Player.jumpspeed; break;
            case Qt::Key_S: Player.setPixmap(QPixmap(":/images/Tower2.jpg")), Player.moveBy(0,218), ClassicGameTowerType = 2, Player.movespeed = 2; break;
            case Qt::Key_A: KeyList.append(event->key()); break;
            case Qt::Key_D: KeyList.append(event->key()); break;
            case Qt::Key_E: ClassicGameStepTwo(); break;
        }
    }
    else if(3 == ClassicGameTowerType)
    {
        switch(event->key())
        {
            case Qt::Key_W: KeyList2.append(event->key()); break;
            case Qt::Key_S: KeyList2.append(event->key());  break;
            case Qt::Key_A: KeyList2.append(event->key()); break;
            case Qt::Key_D: KeyList2.append(event->key()); break;
            case Qt::Key_E: ClassicGameStepThree(); break;
        }
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if(ClassicGameTowerType != 3)
    {
        if(KeyList.contains(event->key()))
        {
            KeyList.removeOne(event->key());
        }
        if(event->key() == Qt::Key_S)
        {
            Player.setPixmap(QPixmap(":/images/TwinTowers.jpg"));
            Player.moveBy(0,-218);
            Player.movespeed = 4;
            ClassicGameTowerType = 1;
        }
    }
    if(3 == ClassicGameTowerType)
    {
        if(KeyList2.contains(event->key()))
        {
            KeyList2.removeOne(event->key());
        }
    }
}

void Widget::BulletShoot()
{
    QPixmap bulletimage(":/images/bullet1.png");
    QPoint playerpos(Player.x() + Player.pixmap().width() / 2,Player.y() + Player.pixmap().height()/4 - bulletimage.height()/2);
    BulletBlue* bullet = new BulletBlue(playerpos,bulletimage,QPoint(1,0));

    ClassicGameScene.addItem(bullet);
    BulletList.append(bullet);

    if(2 <= plane1type && 2 <= plane2type)
    {
        ++f16firecheck;
        if(0 == f16firecheck % 3)
        {
            QPixmap enemybulletimage(":/images/bullet2.png");
            if(1150 >= plane1.x() && 50 <= plane1.x())
            {
                QPoint f16_1pos(plane1.x(),plane1.y() + plane1.pixmap().height()/4);
                BulletBlue* f16_1bullet = new BulletBlue(f16_1pos,enemybulletimage,QPoint(-1,0));
                BulletList2.append(f16_1bullet);
                ClassicGameScene.addItem(f16_1bullet);
            }
            if(1150 >= plane2.x() && 50 <= plane2.x())
            {
                QPoint f16_2pos(plane2.x(),plane2.y() + plane2.pixmap().height()/4);
                BulletBlue* f16_2bullet = new BulletBlue(f16_2pos,enemybulletimage,QPoint(-1,0));
                BulletList2.append(f16_2bullet);
                ClassicGameScene.addItem(f16_2bullet);
            }
            if(100 <= f16firecheck)
            {
                f16firecheck = 0;
            }

        }
    }
    if(StepTwoBoss.health > 0)
    {
        ++BossFireCheck;
        QPixmap bulletimage2(":/images/bullet2.png");

        if(BossFireCheck <= 10)
        {
            QPoint pos2_1(StepTwoBoss.x(),StepTwoBoss.y()+StepTwoBoss.pixmap().height()/4);
            QPoint pos2_2(StepTwoBoss.x(),StepTwoBoss.y()+StepTwoBoss.pixmap().height()/2);

            BulletBlue* bullet2_1 = new BulletBlue(pos2_1,bulletimage2,QPoint(-3,-1));
            BulletBlue* bullet2_2 = new BulletBlue(pos2_2,bulletimage2,QPoint(-3,1));
            BulletBlue* bullet2_3 = new BulletBlue(pos2_1,bulletimage2,QPoint(-1,0));
            BulletList2.append(bullet2_1);
            BulletList2.append(bullet2_2);
            BulletList2.append(bullet2_3);
            ClassicGameScene.addItem(bullet2_1);
            ClassicGameScene.addItem(bullet2_2);
            ClassicGameScene.addItem(bullet2_3);
        }
        else if(BossFireCheck > 15 && BossFireCheck <= 25)
        {
            QPoint pos2_1(StepTwoBoss.x(),StepTwoBoss.y()+StepTwoBoss.pixmap().height()/4);
            QPoint pos2_2(StepTwoBoss.x(),StepTwoBoss.y()+StepTwoBoss.pixmap().height()/2);
            BulletBlue* bullet2_1 = new BulletBlue(pos2_1,bulletimage2,QPoint(-2,0));
            BulletBlue* bullet2_2 = new BulletBlue(pos2_2,bulletimage2,QPoint(-2,0));
            BulletList2.append(bullet2_1);
            BulletList2.append(bullet2_2);
            ClassicGameScene.addItem(bullet2_1);
            ClassicGameScene.addItem(bullet2_2);
        }
        else if(BossFireCheck >= 30)
        {
            BossFireCheck = 0;
        }
    }
    if(3 == ClassicGameStepNum)
    {
        if(StepThreeBoss.health > 0)
        {
            ++BossFireCheck;
            QPixmap bulletimage2(":/images/bullet2.png");

            if(BossFireCheck <= 6)
            {
                QPoint pos3_1(StepThreeBoss.x(),StepThreeBoss.y()+StepThreeBoss.pixmap().height()/4);
                QPoint pos3_2(StepThreeBoss.x(),StepThreeBoss.y()+StepThreeBoss.pixmap().height()/2);
                QPoint pos3_3(StepThreeBoss.x(),StepThreeBoss.y()+StepThreeBoss.pixmap().height()/2+StepThreeBoss.pixmap().height()/4);
                BulletBlue* bullet3_1 = new BulletBlue(pos3_1,bulletimage2,QPoint(-1,0));
                BulletBlue* bullet3_2 = new BulletBlue(pos3_2,bulletimage2,QPoint(-2,0));
                BulletBlue* bullet3_3 = new BulletBlue(pos3_3,bulletimage2,QPoint(-1,0));
                BulletList2.append(bullet3_1);
                BulletList2.append(bullet3_2);
                BulletList2.append(bullet3_3);
                ClassicGameScene.addItem(bullet3_1);
                ClassicGameScene.addItem(bullet3_2);
                ClassicGameScene.addItem(bullet3_3);
            }
            else if(BossFireCheck > 8 && BossFireCheck <= 14)
            {
                QPoint pos3_1(StepThreeBoss.x(),StepThreeBoss.y()+StepThreeBoss.pixmap().height()/4);
                QPoint pos3_2(StepThreeBoss.x(),StepThreeBoss.y()+StepThreeBoss.pixmap().height()/2);
                BulletBlue* bullet3_1 = new BulletBlue(pos3_1,bulletimage2,QPoint(-2,0));
                BulletBlue* bullet3_2 = new BulletBlue(pos3_2,bulletimage2,QPoint(-2,0));
                BulletList2.append(bullet3_1);
                BulletList2.append(bullet3_2);
                ClassicGameScene.addItem(bullet3_1);
                ClassicGameScene.addItem(bullet3_2);
            }
            else if(BossFireCheck >= 16)
            {
                BossFireCheck = 0;
            }
            if(0 == BossFireCheck % 3)
            {
                QPoint pos3_4(StepThreeBoss.x(),StepThreeBoss.y()+StepThreeBoss.pixmap().height()/4);
                BulletBlue* bullet3_4 = new BulletBlue(pos3_4,bulletimage2,QPoint(-2,1));
                BulletList2.append(bullet3_4);
                ClassicGameScene.addItem(bullet3_4);
            }
            if(2 == BossFireCheck % 3)
            {
                QPoint pos3_5(StepThreeBoss.x(),StepThreeBoss.y()+StepThreeBoss.pixmap().height()/4);
                BulletBlue* bullet3_5 = new BulletBlue(pos3_5,bulletimage2,QPoint(-2,-1));
                BulletList2.append(bullet3_5);
                ClassicGameScene.addItem(bullet3_5);
            }

        }
        QPoint pos2(planestep3.x() + planestep3.pixmap().width() / 2,planestep3.y() + planestep3.pixmap().height()/4 - bulletimage.height()/2);
        BulletBlue* bullet2 = new BulletBlue(pos2,bulletimage,QPoint(1,0));
        ClassicGameScene.addItem(bullet2);
        BulletList.append(bullet2);
    }
}

void Widget::GameEndScoreRecordFile()
{
    QDateTime current_time = QDateTime::currentDateTime();
    QString current_date =current_time.toString("yyyy.MM.dd hh:mm:ss");
    QString Score = QString::number(ClassicGameScore);
    QString filelocation = QCoreApplication::applicationDirPath() + "/Record/GameScoreRecord.text";
    QFile file(filelocation);

    QString supnum = QString::number(supplyNum);

    if(file.open(QIODevice::Append))
    {

        file.write(current_date.toUtf8() + "\n");
        file.write(PlayerName.toUtf8() + "\n");
        file.write(Score.toUtf8() + "\n");
        file.write(supnum.toUtf8() + "\n");
        file.write(QString::number(ClassicGameStepNum - 1).toUtf8() + "\n");
        file.close();
    }
}

void Widget::ClassicGamePlayerMove()
{
    if(ClassicGameTowerType != 3)
    {
        for(int keyCode : KeyList)
        {
            switch(keyCode)
            {
                case Qt::Key_A: if(Player.x() > 0) Player.moveLeft(); break;
                case Qt::Key_D: if(Player.x() + Player.pixmap().width() / 2 < 1152) Player.moveRight(); break;
            }
        }
        if(Player.y() <= 330 && 1 == ClassicGameTowerType)
        {
            Player.currentspeedup -= 0.02 * 10;
            Player.moveBy(0,-Player.currentspeedup);
        }
        else if(Player.y() <= 550 && 2 == ClassicGameTowerType)
        {
            Player.currentspeedup -= 0.02 * 10;
            Player.moveBy(0,-Player.currentspeedup);
        }
        if(Player.y() >= 320 && 1 == ClassicGameTowerType)
        {
            Player.currentspeedup = 0;
            Player.setY(320);
        }
        else if(Player.y() >= 538 && 2 == ClassicGameTowerType)
        {
            Player.currentspeedup = 0;
            Player.setY(538);
        }
    }
    if(3 == ClassicGameTowerType)
    {
        for(int keyCode : KeyList2)
        {
            switch(keyCode)
            {
                case Qt::Key_W: if(Player.y() > 60) Player.moveUp(); break;
                case Qt::Key_S: if(Player.y() < 550) Player.moveDown(); break;
                case Qt::Key_A: if(Player.x() > 0) Player.moveLeft(); break;
                case Qt::Key_D: if(Player.x() + Player.pixmap().width() / 2 < 1152) Player.moveRight(); break;
            }
        }

    }
}

void Widget::StepTowBossMove()
{
    ++BossMoveCheck1;
    ++BossMoveCheck2;
    if(1 == BossMoveCheck1)
    {
        BossMoveTimer->start(10);
        connect(BossMoveTimer,&QTimer::timeout,this,&Widget::StepTowBossMove);
    }
    if(StepTwoBoss.x() > 825)
    {
        StepTwoBoss.moveBy(-1,0);
    }
    if(BossMoveCheck1 <= 101 && BossMoveCheck1 >= 2)
    {
        StepTwoBoss.moveBy(-0.4,0);
    }
    if(BossMoveCheck1 <= 201 && BossMoveCheck1 >= 102)
    {
        StepTwoBoss.moveBy(0.4,0);
        if(201 == BossMoveCheck1)
        {
            BossMoveCheck1 = 1;
        }
    }
    if(BossMoveCheck2 <= 400 && BossMoveCheck2 >= 1)
    {
        StepTwoBoss.moveBy(0,0.6);
    }
    if(BossMoveCheck2 <= 800 && BossMoveCheck2 >= 401)
    {
        StepTwoBoss.moveBy(0,-0.6);
        if(800 == BossMoveCheck2)
        {
            BossMoveCheck2 = 0;
        }
    }
    if(0 == StepTwoBoss.health || 0 == Player.health)
    {
        BossMoveCheck1 = 0;
        BossMoveCheck2 = 0;

        disconnect(BossMoveTimer,&QTimer::timeout,this,&Widget::StepTowBossMove);

    }
}

void Widget::StepThreeBossMove()
{
    ++BossMoveCheck1;
    ++BossMoveCheck2;

    if(1 == BossMoveCheck1)
    {
        BossMoveTimer2->start(10);
        connect(BossMoveTimer2,&QTimer::timeout,this,&Widget::StepThreeBossMove);
    }
    if(StepThreeBoss.x() > 925)
    {
        StepThreeBoss.moveBy(-1,0);
    }
    if(BossMoveCheck1 <= 101 && BossMoveCheck1 >= 2)
    {
        StepThreeBoss.moveBy(-0.5,0);
    }
    if(BossMoveCheck1 <= 201 && BossMoveCheck1 >= 102)
    {
        StepThreeBoss.moveBy(0.4,0);
        if(201 == BossMoveCheck1)
        {
            BossMoveCheck1 = 1;
        }
    }
    if(BossMoveCheck2 <= 400 && BossMoveCheck2 >= 1)
    {
        StepThreeBoss.moveBy(0,StepThreeBoss.StepThreeBossMoveSpeed);
    }
    if(BossMoveCheck2 <= 800 && BossMoveCheck2 >= 401)
    {
        StepThreeBoss.moveBy(0,-StepThreeBoss.StepThreeBossMoveSpeed);
        if(800 == BossMoveCheck2)
        {
            BossMoveCheck2 = 0;
        }
    }
    if(0 == StepThreeBoss.health || 0 == Player.health)
    {
        BossMoveCheck1 = 0;
        BossMoveCheck2 = 0;

        disconnect(BossMoveTimer2,&QTimer::timeout,this,&Widget::StepThreeBossMove);
    }
}

void Widget::LogInClicked()
{
    GameButtonClickedAudio.play();
    if(0 == accountcheck)
    {
        LogIn->setText("设置账号");
        account.show();

        accountcheck = 1;
    }
    else if(1 == accountcheck && account.text() != "")
    {
        PlayerName = account.text();
        LogIn->setText("已设置账号");
        account.hide();
        accountcheck = 0;
    }
}
void Widget::GetHighestScoreClicked()
{
    QMessageBox::about(NULL, "历史分数", GetScore());
}
QString Widget::GetScore()
{
    QString filelocation = QCoreApplication::applicationDirPath() + "/Record/GameScoreRecord.text";
    QFile file(filelocation);
    QString NameStr,Score;
    QString LastScore("0"),FinalReturnStr("");
    if(file.open(QIODevice::ReadOnly))
    {
        int readtype = 0;
        QTextStream in(&file);
        while(!in.atEnd())
        {
            ++readtype;
            QString lineStr = in.readLine();
            if(2 == readtype)
            {
                NameStr = lineStr;
            }
            if(3 == readtype)
            {
                Score = lineStr;
                if(Score.toInt() > LastScore.toInt())
                {
                    FinalReturnStr = "账号: ";
                    FinalReturnStr += NameStr;
                    FinalReturnStr += " 分数: ";
                    FinalReturnStr += Score;
                }
                LastScore = Score;
            }
            if(readtype >= 5)
            {
                readtype = 0;
            }
        }
        return FinalReturnStr;
    }
}

void Widget::MultiplayerClicked()
{

    GameButtonClickedAudio.play();
    GameView.setSceneRect(QRect(0,81,1152,630));
    ClassicGameScene.setSceneRect(QRect(0,0,1158,711));
    GameView.setScene(&MultiplayerScene);

    SceneNum = 2;

    StartTimer->stop();
}
void Widget::GameOptionClicked()
{

    GameButtonClickedAudio.play();
}

//1
void Widget::StartGameButtonClicked()
{


    GameButtonClickedAudio.play();

    StartGameButton->hide();
    Exit->hide();
    ClassicGame->show();
    Multiplayer->hide();
    Back->show();
}

void Widget::ExitClicked()
{

    GameButtonClickedAudio.play();
    this->close();
}

void Widget::BackClicked()
{

    GameButtonClickedAudio.play();
    GameOption->hide();
    ClassicGame->hide();
    Back->hide();
    Multiplayer->hide();
    StartGameButton->show();
    Exit->show();
}

void Widget::StartBackgroundMove()
{
    StartBackGround1.moveBy(-1,0);
    StartBackGround2.moveBy(-1,0);
    if(StartBackGround1.x() <= - 1152)
    {
        StartBackGround1.setPos(0,0);
        StartBackGround2.setPos(1152,0);
    }
    mcar.moveBy(-1 * mcar.movespeed,0);
    if(mcar.x() <= -200)
    {
        mcar.setX(1300);
    }
    plane.plmove();
    if(plane.x() <= -300)
    {
        plane.setX(1500);
    }
}

void Widget::ClassicGameClicked()
{

    KeyList.clear();
    KeyList2.clear();
    StepThreeEndLabelMoveSpeed = 2;
    f16firecheck = 0;
    ClassicGameStepThreeEnd->hide();
    ClassicGameStepThreeEnd->move(400,-180);
    Player.show();
    Player.shootspeed = 600;
    Player.movespeed = 4;
    BossMoveCheck1 = 0;
    BossMoveCheck2 = 0;
    ClassicGameStepThreeFriendPlaneMoveCheck = 0;
    GameButtonClickedAudio.play();
    GameView.setSceneRect(QRect(0,81,1152,630));
    ClassicGameScene.setSceneRect(QRect(0,0,1158,711));
    GameView.setScene(&ClassicGameScene);

    ClassicGameStepThreeFriendPlaneMoveCheck2 = 50;
    SceneNum = 1;
    ClassicGameAudio3.play();
    StartTimer->stop();
    BgmTimer->start(130000);
    ClassicGameBackgroundTimer->start(10);
    ClassicGamePlane_CarMoveTimer->start(1500);
    SurviveTimer->start(2000);
    plane1.movespeed = 2.3;
    plane2.movespeed = 2;
    car1.movespeed = 1.6;
    ClassicGameStepTwoPlayerTypeChangeCheck = 0;
    plane1.health = 60;
    plane2.health = 60;
    plane1type = 1;
    plane2type = 1;
    Player.setPixmap(QPixmap(":/images/TwinTowers.jpg"));
    Player.setScale(0.5);

}

void Widget::ClassicGameBackgroundMove()
{
    supply.SupplyMove();
    ClassicGameBackGround1.moveBy(-1,0);
    ClassicGameBackGround2.moveBy(-1,0);
    if(ClassicGameBackGround1.x() <= -1158)
    {
        ClassicGameBackGround1.setX(0);
        ClassicGameBackGround2.setX(1158);
    }
    if(supply.x() < -200)
    {
        supply.setX(2000);
    }
    if(ClassicGameStepThreeFriendPlaneMoveCheck != 0)
    {
        ClassicGameStepThreeFriendPlaneMoveCheck2 += 0.5;
        if(1 == ClassicGameStepThreeFriendPlaneMoveCheck)
        {
            planestep3.moveBy(0,1);
            if(planestep3.y() >= 420)
            {
                ClassicGameStepThreeFriendPlaneMoveCheck = 2;
            }
        }
        if(2 == ClassicGameStepThreeFriendPlaneMoveCheck)
        {
            planestep3.moveBy(0,-1);
            if(planestep3.y() <= 150)
            {
                ClassicGameStepThreeFriendPlaneMoveCheck = 1;
            }
        }

        if(ClassicGameStepThreeFriendPlaneMoveCheck2 <= 50)
        {
            planestep3.moveBy(0.5,0);
        }
        if(ClassicGameStepThreeFriendPlaneMoveCheck2 > 50 && ClassicGameStepThreeFriendPlaneMoveCheck2 <= 100)
        {
            planestep3.moveBy(-0.5,0);
            if(ClassicGameStepThreeFriendPlaneMoveCheck2 >= 100)
            {
                ClassicGameStepThreeFriendPlaneMoveCheck2 = 0;
            }
        }
    }

}

void Widget::StopButtonClicked()
{

    GameButtonClickedAudio.play();
    if(0 == StopButtonIsClicked)
    {

        StopButtonIsClicked = 1;

        BulletMoveTimer->stop();
        BossMoveTimer->stop();
        BossMoveTimer2->stop();
        SurviveTimer->stop();
        ClassicGameBackgroundTimer->stop();
        ClassicGamePlane_CarMoveTimer->stop();
        ClassicGamePlaneShootTimer->stop();
        StopButton->setIcon(QIcon(":/images/resume_nor.png"));
    }
    else if(1 == StopButtonIsClicked)
    {
        StopButtonIsClicked = 0;

        if(2 == ClassicGameStepNum)
        {
            BulletMoveTimer->start(10);
            BossMoveTimer->start(10);
        }
        else if(3 == ClassicGameStepNum)
        {
            BulletMoveTimer->start(10);
            BossMoveTimer2->start(10);
        }
        SurviveTimer->start(2000);
        ClassicGameBackgroundTimer->start(10);
        ClassicGamePlane_CarMoveTimer->start(1500);
        if(ClassicGameTowerType >= 3)
        {
            ClassicGamePlaneShootTimer->start(Player.shootspeed);
        }
        StopButton->setIcon(QIcon(":/images/pause_nor.png"));
    }

}

void Widget::GameEndLabelMove()
{
    ClassicGameStepThreeEnd->move(ClassicGameStepThreeEnd->x(),ClassicGameStepThreeEnd->y() + StepThreeEndLabelMoveSpeed);
    StepThreeEndLabelMoveSpeed += 2;
    if(ClassicGameStepThreeEnd->y() >= 80)
    {
        StepThreeEndLabelTimer->stop();
        StepThreeEndLabelMoveSpeed = 2;
        disconnect(StepThreeEndLabelTimer,&QTimer::timeout,this,&Widget::GameEndLabelMove);

    }
}

void Widget::ClassicGameScoreUpdate()
{
    ClassicGameScore += 1;
    ClassicGameScorePrint->setText("ur score: " + QString::number(ClassicGameScore));
}

void Widget::ClassicGamePlane1Dead()
{

    ++currentplane1;
    if(1 == currentplane1)
    {
        connect(ClassicGamePlane1DeadTimer,&QTimer::timeout,this,&Widget::ClassicGamePlane1Dead);
        Plane1DeadPoint = QPoint(plane1.x(),plane1.y());
        ClassicGamePlane1DeadTimer->start(500);
        Plane1Dead.setPixmap(QPixmap(":/images/enemy2_down3.png"));
        Plane1Dead.setPos(Plane1DeadPoint);
        ClassicGameScene.addItem(&Plane1Dead);

    }
    if(2 == currentplane1)
    {
        Plane1Dead.setPixmap(QPixmap(":/images/enemy2_down4.png"));

    }
    if(3 == currentplane1)
    {
        currentplane1 = 0;
        ClassicGameScene.removeItem(&Plane1Dead);
        ClassicGamePlane1DeadTimer->stop();
        disconnect(ClassicGamePlane1DeadTimer,&QTimer::timeout,this,&Widget::ClassicGamePlane1Dead);
    }
}

void Widget::ClassicGamePlane2Dead()
{

    ++currentplane2;
    if(1 == currentplane2)
    {
        connect(ClassicGamePlane2DeadTimer,&QTimer::timeout,this,&Widget::ClassicGamePlane2Dead);
        Plane2DeadPoint = QPoint(plane2.x(),plane2.y());
        ClassicGamePlane2DeadTimer->start(500);
        Plane2Dead.setPixmap(QPixmap(":/images/enemy2_down3.png"));
        Plane2Dead.setPos(Plane2DeadPoint);
        ClassicGameScene.addItem(&Plane2Dead);
    }
    if(2 == currentplane2)
    {
        Plane2Dead.setPixmap(QPixmap(":/images/enemy2_down4.png"));
    }
    if(3 == currentplane2)
    {
        currentplane2 = 0;
        ClassicGameScene.removeItem(&Plane2Dead);
        ClassicGamePlane2DeadTimer->stop();
        disconnect(ClassicGamePlane2DeadTimer,&QTimer::timeout,this,&Widget::ClassicGamePlane2Dead);
    }
}

void Widget::ClassicGameCarDead()
{
    ++currentcar;
    if(1 == currentcar)
    {
        connect(ClassicGameCarDeadTimer,&QTimer::timeout,this,&Widget::ClassicGameCarDead);
        CarDeadPoint = QPoint(car1.x(),car1.y());
        ClassicGameCarDeadTimer->start(500);
        CarDead.setPixmap(QPixmap(":/images/enemy2_down3.png"));
        CarDead.setPos(CarDeadPoint);
        ClassicGameScene.addItem(&CarDead);

    }
    if(2 == currentcar)
    {
        CarDead.setPixmap(QPixmap(":/images/enemy2_down4.png"));
    }
    if(3 == currentcar)
    {
        currentcar = 0;
        ClassicGameScene.removeItem(&CarDead);
        ClassicGameCarDeadTimer->stop();
        disconnect(ClassicGameCarDeadTimer,&QTimer::timeout,this,&Widget::ClassicGameCarDead);
    }
}

void Widget::ClassicGamePlane_CarMoveSpeedChange()
{
    plane1.movespeed += 0.03;
    plane2.movespeed += 0.03;
    car1.movespeed += 0.03;
}

void Widget::ClassicGameStep3AddPlane()
{
    ++addplanecheck;
    if(1 == addplanecheck)
    {
        planestep3.setPixmap(QPixmap(":/images/plane767_2.png"));
        connect(AddPlaneTimer,&QTimer::timeout,this,&Widget::ClassicGameStep3AddPlane);
        AddPlaneTimer->start(10);
    }
    if(planestep3.x() <= 20)
    {
        planestep3.moveBy(1,0);
    }
    if(planestep3.x() >= 20)
    {
        ClassicGameStepThreeFriendPlaneMoveCheck = 1;
        AddPlaneTimer->stop();
        addplanecheck = 0;
        disconnect(AddPlaneTimer,&QTimer::timeout,this,&Widget::ClassicGameStep3AddPlane);
    }


}

void Widget::ClassicGamePlane_CarMove()
{
    plane1.plmove();
    plane2.plmove();
    car1.CarMove();
    if(car1.x() <= -450)
    {
        car1.setX(1500);
    }
    if(plane1.x() <= -500)
    {
        plane1.setX(1500);
        if(3 == ClassicGameTowerType)
        {
            if(plane1.y() + 40 > 420)
            {
                plane1.setY(plane2.y() - 380);
            }
            else
            {
                plane1.setY(plane2.y() + 40);
            }
        }
        if(1 == plane1type && ClassicGameStepNum >= 2)
        {
            plane1.setPixmap(QPixmap(":/images/f16.png"));
            plane1.setScale(0.3);
            ++plane1type;
        }
    }
    if(plane2.x() <= -400)
    {
        plane2.setX(1300);
        if(3 == ClassicGameTowerType)
        {
            if(plane2.y() + 160 > 450)
            {
                plane2.setY(plane2.y() - 290);
            }
            else
            {
                plane2.setY(plane2.y() + 160);
            }
        }
        if(1 == plane2type && ClassicGameStepNum >= 2)
        {
            plane2.setPixmap(QPixmap(":/images/f16.png"));
            plane2.setScale(0.3);
            ++plane2type;
        }
    }
}
//2
void Widget::ClassicGameStepTwoPlayerTypeChange()
{
    ++ClassicGameStepTwoPlayerTypeChangeCheck;
    if(1 == ClassicGameStepTwoPlayerTypeChangeCheck)
    {

        ClassicGameStepTwoPlayerTypeChangeTimer->start(500);
        Player.setPixmap(QPixmap(":/images/enemy3_down6.png"));
        connect(ClassicGameStepTwoPlayerTypeChangeTimer,&QTimer::timeout,this,&Widget::ClassicGameStepTwoPlayerTypeChange);
    }
    if(2 == ClassicGameStepTwoPlayerTypeChangeCheck)
    {

        Player.setPixmap(QPixmap(":/images/plane767_2.png"));
        disconnect(ClassicGameStepTwoPlayerTypeChangeTimer,&QTimer::timeout,this,&Widget::ClassicGameStepTwoPlayerTypeChange);
        ClassicGameStepTwoPlayerTypeChangeTimer->stop();
        ClassicGameStepTwoPlayerTypeChangeCheck = 0;
    }
}

void Widget::StepTwoBossDead()
{
    ++BossDeadCheck;
    if(1 == BossDeadCheck)
    {
        StepTwoBoss.setPixmap(QPixmap(":/images/enemy2_down3.png"));
        BossMoveTimer->start(500);
        ClassicGameScore += 15;
        ClassicGameAudio2.play();
        connect(BossMoveTimer,&QTimer::timeout,this,&Widget::StepTwoBossDead);
    }
    if(2 == BossDeadCheck)
    {
        StepTwoBoss.setPixmap(QPixmap(":/images/enemy3_down6.png"));
    }
    if(3 == BossDeadCheck)
    {
        StepTwoBoss.hide();
        BossMoveTimer->stop();
        BossDeadCheck = 0;

        StepTwoBoss.setScale(0.5);
        StepTwoBoss.setPos(1200,220);
        disconnect(BossMoveTimer,&QTimer::timeout,this,&Widget::StepTwoBossDead);
    }
}

void Widget::StepThreeBossDead()
{
    ++BossDeadCheck;
    if(1 == BossDeadCheck)
    {
        ClassicGameAudio2.play();
        ClassicGameScore += 22;
        StepThreeBoss.setPixmap(QPixmap(":/images/enemy2_down3.png"));
        BossMoveTimer->start(500);
        connect(BossMoveTimer,&QTimer::timeout,this,&Widget::StepThreeBossDead);
    }
    if(2 == BossDeadCheck)
    {
        StepThreeBoss.setPixmap(QPixmap(":/images/enemy3_down6.png"));
    }
    if(3 == BossDeadCheck)
    {
        StepThreeBoss.hide();
        BossMoveTimer->stop();
        BossDeadCheck = 0;

        StepThreeBoss.setScale(0.55);
        StepThreeBoss.setPos(1200,150);

        disconnect(BossMoveTimer,&QTimer::timeout,this,&Widget::StepThreeBossDead);
    }
}

void Widget::ClassicGamePlayerHealthCheck()
{
    if(ClassicGameTowerType != 3)
    {
        QRect BuildingArea = QRect(Player.x(),Player.y(),Player.pixmap().width() / 2,Player.pixmap().height() / 2);
        QPoint Plane1Area = QPoint(plane1.x() + plane1.pixmap().width()/8,plane1.y() + plane1.pixmap().height()/4);
        QPoint Plane2Area = QPoint(plane2.x() + plane2.pixmap().width()/8,plane2.y() + plane2.pixmap().height()/4);
        QPoint CarArea = QPoint(car1.x(),car1.y());
        QPoint SupplyArea = QPoint(supply.x(),supply.y());

        if(BuildingArea.contains(SupplyArea) && ClassicGameTowerType != 3)
        {
            if(Player.health + 15 <= 100)
            {
                Player.health += 15;
                ClassicGameTowerHealthBar->setValue(Player.health);
            }
            supply.setX(2000);
            ++supplyNum;
            supplyPrintLabel->setText(QString::number(supplyNum));
        }
        if(BuildingArea.contains(Plane1Area) && 1 == ClassicGameTowerType)
        {

            ClassicGamePlane1Dead();
            ClassicGameAudio1.play();
            Player.health -= 50;
            plane1.setX(1850);
            ClassicGameTowerHealthBar->setValue(Player.health);
        }
        if(BuildingArea.contains(Plane2Area) && 1 == ClassicGameTowerType)
        {
            ClassicGamePlane2Dead();
            ClassicGameAudio1.play();
            Player.health -= 50;
            plane2.setX(1250);
            ClassicGameTowerHealthBar->setValue(Player.health);
        }
        if(BuildingArea.contains(CarArea) && 1 == ClassicGameTowerType)
        {
            ClassicGameCarDead();

            ClassicGameAudio2.play();
            Player.health -= 20;
            car1.setX(1200);
            car1.CarDead();
            ClassicGameTowerHealthBar->setValue(Player.health);
        }
        if(BuildingArea.contains(Plane1Area) && 2 == ClassicGameTowerType)
        {

            ClassicGamePlane1Dead();

            ClassicGameAudio1.play();
            Player.health -= 20;
            plane1.setX(1450);
            ClassicGameTowerHealthBar->setValue(Player.health);
        }
        if(BuildingArea.contains(Plane2Area) && 2 == ClassicGameTowerType)
        {
            ClassicGamePlane2Dead();

            ClassicGameAudio1.play();
            Player.health -= 20;
            plane2.setX(1350);
            ClassicGameTowerHealthBar->setValue(Player.health);
        }
        if(BuildingArea.contains(CarArea) && 2 == ClassicGameTowerType)
        {
            ClassicGameCarDead();

            ClassicGameAudio2.play();
            Player.health -= 5;
            car1.setX(1200);
            ClassicGameTowerHealthBar->setValue(Player.health);
        }
        if(Player.health <= 0)
        {
            ClassicGameTowerHealthBar->setValue(0);
            ClassicGameBackgroundTimer->stop();
            ClassicGamePlane_CarMoveTimer->stop();
            SurviveTimer->stop();
            ClassicGameReloadButton->show();
            ClassicGameStepThreeEnd->setText("当前分数:" + QString::number(ClassicGameScore));
            StepThreeEndLabelTimer->start(15);
            connect(StepThreeEndLabelTimer,&QTimer::timeout,this,&Widget::GameEndLabelMove);
            ClassicGameStepThreeEnd->show();
            ClassicGameEndButton->show();
            Player.setPixmap(QPixmap(":/images/enemy2_down3.png"));
            BgmTimer->stop();

            GameEndScoreRecordFile();
        }
    }
    else if(ClassicGameTowerType >= 3)
    {
        QPoint PlayerPoint = QPoint(Player.x() + Player.pixmap().width() / 3,Player.y() + Player.pixmap().height()/4);
        QRect SupplyArea = QRect(supply.x(),supply.y(),supply.pixmap().width(),supply.pixmap().height());
        QRect Plane1Area = QRect(plane1.x(),plane1.y(),plane1.pixmap().width()/2,plane1.pixmap().height()/2);
        QRect Plane2Area = QRect(plane2.x(),plane2.y(),plane2.pixmap().width()/2,plane2.pixmap().height()/2);
        QRect CarArea = QRect(car1.x(),car1.y(),car1.pixmap().width()/2,car1.pixmap().height()/2);

        if(Player.x() > StepTwoBoss.x() || Player.x() > StepThreeBoss.x())
        {
            Player.health -= 100;
        }
        if(SupplyArea.contains(PlayerPoint))
        {
            if(Player.shootspeed - 20 >= 200)
            {
                Player.shootspeed -= 20;
                ClassicGamePlaneShootTimer->start(Player.shootspeed);

            }
            if(Player.health + 15 <= 100)
            {
                Player.health += 15;
                ClassicGameTowerHealthBar->setValue(Player.health);
            }
            supply.setX(2000);
            ++supplyNum;
            supplyPrintLabel->setText(QString::number(supplyNum));
        }
        if(Plane1Area.contains(PlayerPoint))
        {
            ClassicGamePlane1Dead();
            Player.health -= 80;
            ClassicGameAudio1.play();

            plane1.setX(1450);
            ClassicGameTowerHealthBar->setValue(Player.health);
        }
        if(Plane2Area.contains(PlayerPoint))
        {
            ClassicGamePlane2Dead();
            Player.health -= 80;
            ClassicGameAudio1.play();

            plane2.setX(1350);
            ClassicGameTowerHealthBar->setValue(Player.health);
        }
        if(CarArea.contains(PlayerPoint))
        {
            ClassicGameCarDead();
            ClassicGameAudio2.play();
            Player.health -= 30;
            car1.setX(1200);
            ClassicGameTowerHealthBar->setValue(Player.health);
        }
        if(Player.health <= 0)
        {


            ClassicGameAudio2.play();
            ClassicGameTowerHealthBar->setValue(0);
            ClassicGameBackgroundTimer->stop();
            ClassicGamePlane_CarMoveTimer->stop();
            SurviveTimer->stop();
            BulletMoveTimer->stop();
            ClassicGamePlaneShootTimer->stop();
            ClassicGameReloadButton->show();
            ClassicGameEndButton->show();
            ClassicGameStepThreeEnd->setText("当前分数:" + QString::number(ClassicGameScore));
            ClassicGameStepThreeEnd->show();
            StepThreeEndLabelTimer->start(15);
            connect(StepThreeEndLabelTimer,&QTimer::timeout,this,&Widget::GameEndLabelMove);
            Player.setPixmap(QPixmap(":/images/enemy2_down3.png"));
            planestep3.setPixmap(QPixmap(":/images/enemy2_down3.png"));
            BgmTimer->stop();
            BossMoveTimer->stop();
            BossMoveTimer2->stop();
            GameEndScoreRecordFile();
        }
    }
}

void Widget::ClassicGameReloadButtonClicked()
{


    KeyList.clear();
    KeyList2.clear();
    StepThreeEndLabelMoveSpeed = 2;
    Player.shootspeed = 600;
    Player.movespeed = 4;
    ClassicGameStepThreeEnd->hide();
    ClassicGameStepThreeEnd->move(210,-180);
    ClassicGameStepThreeFriendPlaneMoveCheck = 0;
    f16firecheck = 0;

    Player.setPixmap(QPixmap(":/images/TwinTowers.jpg"));
    ClassicGameTowerType = 1;
    ClassicGameReloadButton->hide();
    ClassicGameEndButton->hide();
    ClassicGameScore = 0;
    ClassicGameScorePrint->setText("ur score: " + QString::number(ClassicGameScore));
    ClassicGameStepNum = 1;
    plane1.movespeed = 2.3;
    plane2.movespeed = 2;
    car1.movespeed = 1.6;
    ClassicGameStepThreeFriendPlaneMoveCheck2 = 50;
    Player.show();
    supplyNum = 0;
    supplyPrintLabel->setText(QString::number(supplyNum));
    plane1.health = 60;
    plane2.health = 60;

    BossMoveCheck1 = 0;
    BossMoveCheck2 = 0;

    StepThreeBoss.setScale(0.6);
    StepThreeBoss.setPos(1200,150);
    StepTwoBoss.setScale(0.5);
    StepTwoBoss.setPos(1200,350);

    car1.setPos(850,578);
    car1.setScale(0.5);
    Player.setPos(300,320);
    Player.setScale(0.5);
    plane1.setScale(0.5);
    plane1.setPos(1500,500);
    plane2.setScale(0.5);
    plane2.setPos(700,100);
    plane1type = 1;
    plane2type = 1;
    ClassicGameBackGround1.setPos(0,0);
    ClassicGameBackGround2.setPos(1158,0);
    ClassicGameTowerHealthBar->setValue(100);

    planestep3.setPos(-220,280);
    planestep3.hide();
    Player.health = 100;
    BossMoveTimer->stop();
    ClassicGamePlaneShootTimer->stop();
    ClassicGameBackgroundTimer->start(10);
    ClassicGamePlane_CarMoveTimer->start(1500);
    SurviveTimer->start(2000);
    BulletMoveTimer->stop();
    for(auto bullet : BulletList)
    {
        ClassicGameScene.removeItem(bullet);
        BulletList.removeOne(bullet);
        delete bullet;
    }
    for(auto bullet : BulletList2)
    {
        ClassicGameScene.removeItem(bullet);
        BulletList.removeOne(bullet);
        delete bullet;
    }
    plane1.setPixmap(QPixmap(":/images/plane767.png"));
    plane2.setPixmap(QPixmap(":/images/plane767.png"));
}

void Widget::ClassicGameEndButtonClicked()
{

    KeyList.clear();
    KeyList2.clear();

    Player.shootspeed = 600;
    ClassicGameStepThreeFriendPlaneMoveCheck = 0;

    Player.setPixmap(QPixmap(":/images/TwinTowers.jpg"));
    ClassicGameTowerType = 1;
    ClassicGameReloadButton->hide();
    ClassicGameEndButton->hide();
    ClassicGameScore = 0;
    ClassicGameScorePrint->setText("ur score: " + QString::number(ClassicGameScore));
    Player.health = 100;
    ClassicGameTowerHealthBar->setValue(100);
    planestep3.setPos(-220,280);
    planestep3.hide();
    ClassicGameStepNum = 1;
    plane1.movespeed = 2.3;
    plane2.movespeed = 2;
    car1.movespeed = 1.6;

    supplyNum = 0;
    supplyPrintLabel->setText(QString::number(supplyNum));

    car1.setPos(850,578);
    car1.setScale(0.5);
    Player.setPos(300,320);
    Player.setScale(0.5);
    plane1.setScale(0.5);
    plane1.setPos(1500,500);
    plane2.setScale(0.5);
    plane2.setPos(700,100);
    ClassicGameBackGround1.setPos(0,0);
    ClassicGameBackGround2.setPos(1158,0);
    ClassicGameTowerHealthBar->setValue(100);
    ClassicGameBackgroundTimer->stop();
    ClassicGamePlane_CarMoveTimer->stop();
    ClassicGamePlaneShootTimer->stop();
    GameView.setSceneRect(QRect(0,0,1152,630));
    GameView.setScene(&StartScene);
    BossMoveTimer->stop();
    StartTimer->start(10);
    BulletMoveTimer->stop();

    for(auto bullet : BulletList)
    {
        ClassicGameScene.removeItem(bullet);
        BulletList.removeOne(bullet);
        delete bullet;
    }
    for(auto bullet : BulletList2)
    {
        ClassicGameScene.removeItem(bullet);
        BulletList.removeOne(bullet);
        delete bullet;
    }
    plane1.setPixmap(QPixmap(":/images/plane767.png"));
    plane2.setPixmap(QPixmap(":/images/plane767.png"));

}

Widget::~Widget()
{
    for(auto bullet : BulletList)
    {
        ClassicGameScene.removeItem(bullet);
        BulletList.removeOne(bullet);

    }
    for(auto bullet : BulletList2)
    {
        ClassicGameScene.removeItem(bullet);
        BulletList.removeOne(bullet);

    }
    delete ui;
}

void Widget::ClassicGameStepTwo()
{
    KeyList.clear();
    if(ClassicGameStepNum != 1 || supplyNum < 20)
    {
        return;
    }
    ClassicGameAudio1.play();
    ClassicGameStepNum = 2;
    ClassicGameTowerType = 3;
    supplyNum -= 20;
    supplyPrintLabel->setText(QString::number(supplyNum));

    Player.health = 100;
    Player.movespeed = 2.5;
    BossDeadCheck = 0;
    StepTwoBoss.health = 100;
    BossFireCheck = 0;
    BossMoveCheck1 = 0;
    BossMoveCheck2 = 0;
    ClassicGamePlaneShootTimer->start(Player.shootspeed);
    BulletMoveTimer->start(10);
    StepTwoBoss.show();
    ClassicGameStepTwoPlayerTypeChange();
    StepTowBossMove();
}

void Widget::ClassicGameStepThree()
{

    if(ClassicGameStepNum != 2 || supplyNum < 10 || StepTwoBoss.health > 0)
    {
        return;
    }
    ClassicGameAudio1.play();
    ClassicGameStepNum = 3;
    supplyNum -= 10;
    supplyPrintLabel->setText(QString::number(supplyNum));

    Player.health = 100;
    Player.movespeed = 2;
    Player.shootspeed -= 80;
    StepThreeBoss.health = 100;
    StepThreeBoss.show();
    ClassicGameStep3AddPlane();
    ClassicGameStepThreeFriendPlaneMoveCheck2 = 50;
    BossFireCheck = 0;
    planestep3.show();
    BossMoveCheck1 = 0;
    BossMoveCheck2 = 0;
    StepThreeBossMove();
}
