#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QWidget* wgt = new QWidget(this);

    QLabel* yellowLabel = new QLabel(wgt);
    yellowLabel->setStyleSheet("background-color: yellow");

    QLabel* blueLabel = new QLabel(wgt);
    blueLabel->setStyleSheet("background-color: blue");

    QLabel* redLabel = new QLabel(wgt);
    redLabel->setStyleSheet("background-color: red");
    QVBoxLayout* myLayout = new QVBoxLayout;
    myLayout->addWidget(wgt);
    //wgt->resize(500, 500);
    this->setLayout(myLayout);
    this->resize(600, 600);
    wgt->resize(this->width(), this->height());

    QTimer* myTimer = new QTimer();

    QStateMachine* psm = new QStateMachine;

    QState* pStateOne = new QState(psm);
    //QRect yellowHoriz(0, 0, wgt->width(), wgt->height()/3);
    //QRect blueHoriz(0,wgt->height()/3, wgt->width(), wgt->height()/3);
    QRect redHoriz(0, 2*wgt->height()/3, wgt->width(), wgt->height()/3);

    yellowLabel->setGeometry(yellowHoriz());
    blueLabel->setGeometry(blueHoriz());
    redLabel->setGeometry(redHoriz);

    psm->setInitialState(pStateOne);

    QState* pStateTwo = new QState(psm);
    QRect yellowVert(0, 0, wgt->width()/3, wgt->height());
    QRect blueVert(wgt->width()/3, 0, wgt->width()/3, wgt->height());
    QRect redVert(2*wgt->width()/3, 0, wgt->width()/3, wgt->height());

    pStateOne->addTransition(myTimer, SIGNAL(timeout()), pStateTwo);
    pStateTwo->addTransition(myTimer, SIGNAL(timeout()), pStateOne);

    QPropertyAnimation* yellowToVertAnim =
            new QPropertyAnimation(yellowLabel, "geometry");
    yellowToVertAnim->setDuration(1000);
    yellowToVertAnim->setStartValue(yellowHoriz());
    yellowToVertAnim->setEndValue(yellowVert);
    yellowToVertAnim->setEasingCurve(QEasingCurve::OutCirc);
    connect(pStateTwo, SIGNAL(entered()), yellowToVertAnim, SLOT(start()));

    QPropertyAnimation* blueToVertAnim =
            new QPropertyAnimation(blueLabel, "geometry");
    blueToVertAnim->setDuration(1000);
    blueToVertAnim->setStartValue(blueHoriz());
    blueToVertAnim->setEndValue(blueVert);
    blueToVertAnim->setEasingCurve(QEasingCurve::OutCirc);
    connect(pStateTwo, SIGNAL(entered()), blueToVertAnim, SLOT(start()));

    QPropertyAnimation* redToVertAnim =
            new QPropertyAnimation(redLabel, "geometry");
    redToVertAnim->setDuration(1000);
    redToVertAnim->setStartValue(redHoriz);
    redToVertAnim->setEndValue(redVert);
    redToVertAnim->setEasingCurve(QEasingCurve::OutCirc);
    connect(pStateTwo, SIGNAL(entered()), redToVertAnim, SLOT(start()));

    QPropertyAnimation* yellowToHorizAnim =
            new QPropertyAnimation(yellowLabel, "geometry");
    yellowToHorizAnim->setDuration(1000);
    yellowToHorizAnim->setStartValue(yellowVert);
    yellowToHorizAnim->setEndValue(yellowHoriz());
    connect(pStateOne, SIGNAL(entered()), yellowToHorizAnim, SLOT(start()));

    QPropertyAnimation* blueToHorizAnim =
            new QPropertyAnimation(blueLabel, "geometry");
    blueToHorizAnim->setDuration(1000);
    blueToHorizAnim->setStartValue(blueVert);
    blueToHorizAnim->setEndValue(blueHoriz());
    connect(pStateOne, SIGNAL(entered()), blueToHorizAnim, SLOT(start()));

    QPropertyAnimation* redToHorizAnim =
            new QPropertyAnimation(redLabel, "geometry");
    redToHorizAnim->setDuration(1000);
    redToHorizAnim->setStartValue(redVert);
    redToHorizAnim->setEndValue(redHoriz);
    connect(pStateOne, SIGNAL(entered()), redToHorizAnim, SLOT(start()));

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
