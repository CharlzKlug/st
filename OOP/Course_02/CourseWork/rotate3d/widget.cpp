#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    x = 200;
    y = 200;
    this->setStyleSheet("background: black;");
    QGroupBox * controlPanel = new QGroupBox(tr("Control panel"));
    QVBoxLayout * controlPanelLayout = new QVBoxLayout;
    aroundZSlider = new QSlider(Qt::Horizontal, controlPanel);
    aroundZSlider->setMinimum(0);
    aroundZSlider->setMaximum(360);
    aroundZSlider->setValue(0);
    zAngleLabel = new QLabel("Z angle: " + QString::number(aroundZSlider->value()),
                             controlPanel);
    connect(aroundZSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderZchanged(int)));


    aroundXSlider = new QSlider(Qt::Horizontal, controlPanel);
    aroundXSlider->setMinimum(0);
    aroundXSlider->setMaximum(360);
    aroundXSlider->setValue(0);
    xAngleLabel = new QLabel("X angle: " + QString::number(aroundXSlider->value()),
                             controlPanel);
    connect(aroundXSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderXchanged(int)));

    aroundYSlider = new QSlider(Qt::Horizontal, controlPanel);
    aroundYSlider->setMinimum(0);
    aroundYSlider->setMaximum(360);
    aroundYSlider->setValue(0);
    yAngleLabel = new QLabel("Y angle: " + QString::number(aroundYSlider->value()),
                             controlPanel);
    connect(aroundYSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderYchanged(int)));

    qreal dots[2][3]={{0, 0, 0}, {100, 0, 0}};
    int myLink[] = {0, 1};
    object3d = new Object3D(&dots[0][0], 2, &myLink[0], 2);

    controlPanelLayout->addWidget(zAngleLabel);
    controlPanelLayout->addWidget(aroundZSlider);

    controlPanelLayout->addWidget(xAngleLabel);
    controlPanelLayout->addWidget(aroundXSlider);

    controlPanelLayout->addWidget(yAngleLabel);
    controlPanelLayout->addWidget(aroundYSlider);

    controlPanel->setLayout(controlPanelLayout);
    controlPanel->show();
}

void Widget::butPress(){
    x = 400;
    y = 10;
    update();
}

void Widget::paintEvent(QPaintEvent *){
    //this->setWindowTitle("1111");
    this->setWindowTitle("Width: " + QString::number(this->width()) +
                         " Height: " + QString::number(this->height()));
    QPainter painter(this);
    painter.setPen(Qt::blue);
    //painter.setFont(QFont("Arial", 30));
    //painter.drawText(rect(), Qt::AlignCenter, "Qt");
    //painter.drawLine(QPoint(0, 0), QPoint(x, y));
    qreal windowHalfHeight = this->height()/2,
            windowHalfWidth = this->width()/2;
    for (int i = 0; i < object3d->getLinksCount(); i++){
        painter.drawLine(QPoint(object3d->getY(object3d->getLinkFirstDot(i)) *
                                windowHalfWidth / object3d->getMaxDistance() +
                                windowHalfWidth,
                                object3d->getX(object3d->getLinkFirstDot(i)) *
                                windowHalfHeight / object3d->getMaxDistance() +
                                windowHalfHeight),
                         QPoint(object3d->getY(object3d->getLinkSecondDot(i)) *
                                windowHalfWidth / object3d->getMaxDistance()+
                                windowHalfWidth,
                                object3d->getX(object3d->getLinkSecondDot(i)) *
                                windowHalfHeight / object3d->getMaxDistance() +
                                windowHalfHeight));
    }
}

Widget::~Widget()
{

}

void Widget::sliderZchanged(int value){
    zAngleLabel->setText("Z angle: " + QString::number(value));
    object3d->setZAngle(value*3.14/180);
    update();
}

void Widget::sliderXchanged(int value){
    xAngleLabel->setText("X angle: " + QString::number(value));
    object3d->setXAngle(value*3.14/180);
    update();
}

void Widget::sliderYchanged(int value){
    yAngleLabel->setText("Y angle: " + QString::number(value));
    object3d->setYAngle(value*3.14/180);
    update();
}
