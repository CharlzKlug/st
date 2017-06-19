#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QWidget* wgt = new QWidget(this);
    QLabel* redLabel = new QLabel(wgt);
    redLabel->setStyleSheet("background-color: red");

    QLabel* yellowLabel = new QLabel(wgt);
    yellowLabel->setStyleSheet("background-color: yellow");

    QLabel* blueLabel = new QLabel(wgt);
    blueLabel->setStyleSheet("background-color: blue");

    QVBoxLayout* myLayout = new QVBoxLayout;
    myLayout->addWidget(wgt);
    //wgt->resize(500, 500);
    this->setLayout(myLayout);
    this->resize(600, 600);
    wgt->resize(this->width(), this->height());

    QTimer* myTimer = new QTimer();

    QStateMachine* psm = new QStateMachine;

    QState* pStateOne = new QState(psm);

    int startX, startHeight, endHeight;
    startX = 400;
    startHeight = 10;
    endHeight = 500;

    QRect yellowEnd(startX, 0, 100, endHeight);
    QRect blueEnd(startX, endHeight, 100, 50);
    QRect redEnd(startX, startHeight+endHeight+100, 100, 0);


    psm->setInitialState(pStateOne);

    QState* pStateTwo = new QState(psm);

    QRect yellowStart(startX, 0, 100, startHeight);
    QRect blueStart(startX, startHeight, 100, 50);
    QRect redStart(startX, startHeight+50, 100, endHeight+50);

    redLabel->setGeometry(redStart);
    yellowLabel->setGeometry(yellowStart);
    blueLabel->setGeometry(blueStart);


    pStateOne->addTransition(myTimer, SIGNAL(timeout()), pStateTwo);
    pStateTwo->addTransition(myTimer, SIGNAL(timeout()), pStateOne);

    QPropertyAnimation* yellowToVertAnim =
            new QPropertyAnimation(yellowLabel, "geometry");
    yellowToVertAnim->setDuration(1000);
    yellowToVertAnim->setStartValue(yellowEnd);
    yellowToVertAnim->setEndValue(yellowStart);
    yellowToVertAnim->setEasingCurve(QEasingCurve::OutCirc);
    connect(pStateTwo, SIGNAL(entered()), yellowToVertAnim, SLOT(start()));

    QPropertyAnimation* blueToVertAnim =
            new QPropertyAnimation(blueLabel, "geometry");
    blueToVertAnim->setDuration(1000);
    blueToVertAnim->setStartValue(blueEnd);
    blueToVertAnim->setEndValue(blueStart);
    blueToVertAnim->setEasingCurve(QEasingCurve::OutCirc);
    connect(pStateTwo, SIGNAL(entered()), blueToVertAnim, SLOT(start()));

    QPropertyAnimation* redToVertAnim =
            new QPropertyAnimation(redLabel, "geometry");
    redToVertAnim->setDuration(1000);
    redToVertAnim->setStartValue(redEnd);
    redToVertAnim->setEndValue(redStart);
    redToVertAnim->setEasingCurve(QEasingCurve::OutCirc);
    //connect(pStateTwo, SIGNAL(entered()), redToVertAnim, SLOT(start()));

    QPropertyAnimation* yellowToHorizAnim =
            new QPropertyAnimation(yellowLabel, "geometry");
    yellowToHorizAnim->setDuration(1000);
    yellowToHorizAnim->setStartValue(yellowStart);
    yellowToHorizAnim->setEndValue(yellowEnd);
    connect(pStateOne, SIGNAL(entered()), yellowToHorizAnim, SLOT(start()));

    QPropertyAnimation* blueToHorizAnim =
            new QPropertyAnimation(blueLabel, "geometry");
    blueToHorizAnim->setDuration(1000);
    blueToHorizAnim->setStartValue(blueStart);
    blueToHorizAnim->setEndValue(blueEnd);
    connect(pStateOne, SIGNAL(entered()), blueToHorizAnim, SLOT(start()));

    QPropertyAnimation* redToHorizAnim =
            new QPropertyAnimation(redLabel, "geometry");
    redToHorizAnim->setDuration(1000);
    redToHorizAnim->setStartValue(redStart);
    redToHorizAnim->setEndValue(redEnd);
    //connect(pStateOne, SIGNAL(entered()), redToHorizAnim, SLOT(start()));

    psm->start();
    myTimer->start(3000);
}

Widget::~Widget()
{

}

QRect Widget::yellowHoriz()
{
    return QRect (0, 0, this->width(), this->height()/3);
}

QRect Widget::blueHoriz()
{
    return QRect (0,this->height()/3, this->width(), this->height()/3);
}
