#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setStyleSheet("background: black;");
    autopilotIsEnabled = false;
    QGroupBox * controlPanel = new QGroupBox(tr("Control panel"));
    QVBoxLayout * controlPanelLayout = new QVBoxLayout;

    // Слайдер для вращения вокруг оси Z
    aroundZSlider = new QSlider(Qt::Horizontal, controlPanel);
    aroundZSlider->setMinimum(0);
    aroundZSlider->setMaximum(360);
    aroundZSlider->setValue(0);
    zAngleLabel = new QLabel("Z angle: " + QString::number(aroundZSlider->value()),
                             controlPanel);
    connect(aroundZSlider, SIGNAL(valueChanged(int)), this,
            SLOT(sliderZchanged(int)));

    // Слайдер для вращения вокруг оси X
    aroundXSlider = new QSlider(Qt::Horizontal, controlPanel);
    aroundXSlider->setMinimum(0);
    aroundXSlider->setMaximum(360);
    aroundXSlider->setValue(0);
    xAngleLabel = new QLabel("X angle: " + QString::number(aroundXSlider->value()),
                             controlPanel);
    connect(aroundXSlider, SIGNAL(valueChanged(int)), this,
            SLOT(sliderXchanged(int)));

    // Слайдер для вращения вокруг оси Y
    aroundYSlider = new QSlider(Qt::Horizontal, controlPanel);
    aroundYSlider->setMinimum(0);
    aroundYSlider->setMaximum(360);
    aroundYSlider->setValue(0);
    yAngleLabel = new QLabel("Y angle: " + QString::number(aroundYSlider->value()),
                             controlPanel);
    connect(aroundYSlider, SIGNAL(valueChanged(int)), this,
            SLOT(sliderYchanged(int)));

    // Клавиша автопилота
    autoPilotButton = new QPushButton("Enable autopilot", controlPanel);
    connect(autoPilotButton, SIGNAL(clicked()), SLOT(buttonAutopilotPressed()));

    // Задание фигуры
    qreal dots[2][3]={{0, 0, 0}, {100, 0, 0}};
    int myLink[] = {0, 1};

    qreal tetraDots[4][3] = {{0, 0, 10},
                             {0, -10, 0},
                             {-5, 5, 0},
                             {5, 5, 0}};

    int tetraLinks[] = {0, 1,
                        0, 2,
                        0, 3,
                        1, 0,
                        1, 2,
                        1, 3,
                        2, 0,
                        2, 1,
                        2, 3,
                        3, 0,
                        3, 1,
                        3, 2};
    object3d = new Object3D(&tetraDots[0][0], 4, &tetraLinks[0], 24);

    controlPanelLayout->addWidget(zAngleLabel);
    controlPanelLayout->addWidget(aroundZSlider);

    controlPanelLayout->addWidget(xAngleLabel);
    controlPanelLayout->addWidget(aroundXSlider);

    controlPanelLayout->addWidget(yAngleLabel);
    controlPanelLayout->addWidget(aroundYSlider);

    controlPanelLayout->addWidget(autoPilotButton);

    controlPanel->setLayout(controlPanelLayout);
    controlPanel->show();

}

void Widget::buttonAutopilotPressed(){
    // Реакция на нажатие клавиши автопилота
    if (autopilotIsEnabled) {
        myAutopilot->stop();
        aroundXSlider->setEnabled(true);
        aroundYSlider->setEnabled(true);
        aroundZSlider->setEnabled(true);
        autoPilotButton->setText("Enable autopilot");
        autopilotIsEnabled = false;
    }
    else {
        myThread = new QThread;
        myAutopilot = new Autopilot(object3d->getAngleX(),
                                    object3d->getAngleY(),
                                    object3d->getAngleZ());
        myAutopilot->moveToThread(myThread);
        connect(myAutopilot, SIGNAL(newAngles(qreal,qreal,qreal)),
                SLOT(autopilotDatas(qreal,qreal,qreal)));
        connect(myThread, SIGNAL(started()), myAutopilot, SLOT(start()));
        connect(myAutopilot, SIGNAL(finished()), myThread, SLOT(quit()));
        connect(myAutopilot, SIGNAL(finished()), myAutopilot, SLOT(deleteLater()));
        connect(myThread, SIGNAL(finished()), myThread, SLOT(deleteLater()));
        aroundXSlider->setEnabled(false);
        aroundYSlider->setEnabled(false);
        aroundZSlider->setEnabled(false);
        QPalette disablePalette = aroundXSlider->palette();
        disablePalette.setCurrentColorGroup(QPalette::Active);
        aroundXSlider->setPalette(disablePalette);
        autoPilotButton->setText("Disable autopilot");
        myThread->start();
        autopilotIsEnabled=true;
    }

    /*
    myThread = new QThread;
    myAutopilot = new Autopilot(object3d->getAngleX(),
                                object3d->getAngleY(),
                                object3d->getAngleZ());
    myAutopilot->moveToThread(myThread);
    connect(myAutopilot, SIGNAL(newAngles(qreal,qreal,qreal)),
            SLOT(autopilotDatas(qreal,qreal,qreal)));
    connect(myThread, SIGNAL(started()), myAutopilot, SLOT(start()));
    myThread->start();
    */
    /*
    if (myAutopilot->isEnabledP()) {myAutopilot->stop();}
    else {
        myAutopilot->setStartAngles(object3d->getAngleX(),
                                    object3d->getAngleY(),
                                    object3d->getAngleZ());
        myAutopilot->start();
    }*/
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
            windowHalfWidth = this->width()/2,
            stretchX, // Коэффициент растяжения по X
            stretchY; // Коэффициент растяжения по Y
    int firstDot, secondDot;
    for (int i = 0; i < object3d->getLinksCount(); i++){
        firstDot = object3d->getLinkFirstDot(i);
        secondDot = object3d->getLinkSecondDot(i);
        stretchX = windowHalfWidth / object3d->getMaxDistance();
        stretchY = windowHalfHeight / object3d->getMaxDistance();
        painter.drawLine(QPoint(object3d->getY(firstDot) * stretchX +
                                windowHalfWidth,
                                object3d->getX(firstDot) * stretchY +
                                windowHalfHeight),
                         QPoint(object3d->getY(secondDot) * stretchX +
                                windowHalfWidth,
                                object3d->getX(secondDot) * stretchY +
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

void Widget::autopilotDatas(qreal XAngle, qreal YAngle, qreal ZAngle){
    object3d->setXAngle(XAngle);
    object3d->setYAngle(YAngle);
    object3d->setZAngle(ZAngle);
    update();
}
