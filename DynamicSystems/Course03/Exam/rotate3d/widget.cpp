#include "widget.h"

// Конструктор главного объекта
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
    zAngleLabel = new QLabel("Z angle: " +
                             QString::number(aroundZSlider->value()),
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

    // Задание выпадающего списка с фигурами
    shapeComboBox = new QComboBox;
    shapeComboBox->addItem("Cube");
    shapeComboBox->addItem("Pyramid");
    shapeComboBox->addItem("Star");
    connect(shapeComboBox, SIGNAL(currentIndexChanged(int)), SLOT(selectShape()));

    // Задание фигуры
    qreal cubeDots[8][3] = {{50, -50, -50}, {50, -50, 50},
                            {50, 50, 50}, {50, 50, -50},
                            {-50, -50, -50}, {-50, -50, 50},
                            {-50, 50, 50}, {-50, 50, -50}};
    int cubeLinks[] = {0, 1, 0, 4, 0, 3, 1, 2, 1, 5, 2, 6, 2, 3, 3, 7, 5, 6, 5, 4,
                       6, 7, 4, 7};
    object3d = new Object3D(&cubeDots[0][0], 8, &cubeLinks[0], 24);

    // Добавление виджетов на слой компоновки
    controlPanelLayout->addWidget(zAngleLabel);
    controlPanelLayout->addWidget(aroundZSlider);

    controlPanelLayout->addWidget(xAngleLabel);
    controlPanelLayout->addWidget(aroundXSlider);

    controlPanelLayout->addWidget(yAngleLabel);
    controlPanelLayout->addWidget(aroundYSlider);

    controlPanelLayout->addWidget(autoPilotButton);

    controlPanelLayout->addWidget(shapeComboBox);
    controlPanel->setLayout(controlPanelLayout);
    controlPanel->show();
}

void Widget::buttonAutopilotPressed(){
    // Реакция на нажатие клавиши автопилота
    if (autopilotIsEnabled) {
        // Если автопилот уже был запущен
        myAutopilot->stop();
        aroundXSlider->setEnabled(true);
        aroundYSlider->setEnabled(true);
        aroundZSlider->setEnabled(true);
        autoPilotButton->setText("Enable autopilot");
        autopilotIsEnabled = false;
    }
    else {
        // Если автопилот не был запущен
        myThread = new QThread;
        myAutopilot = new Autopilot(object3d->getAngleX(),
                                    object3d->getAngleY(),
                                    object3d->getAngleZ());
        myAutopilot->moveToThread(myThread);
        connect(myAutopilot, SIGNAL(newAngles(qreal,qreal,qreal)),
                SLOT(autopilotDatas(qreal,qreal,qreal)));
        connect(myAutopilot, SIGNAL(pausedSignal()),
                SLOT(autopilotPaused()));
        connect(myThread, SIGNAL(started()), myAutopilot,
                SLOT(start()));
        connect(myAutopilot, SIGNAL(finished()), myThread,
                SLOT(quit()));
        connect(myAutopilot, SIGNAL(finished()), myAutopilot,
                SLOT(deleteLater()));
        connect(myThread, SIGNAL(finished()), myThread,
                SLOT(deleteLater()));
        aroundXSlider->setEnabled(false);
        aroundYSlider->setEnabled(false);
        aroundZSlider->setEnabled(false);

        // Смена раскраски слайдеров
        QPalette disablePalette = aroundXSlider->palette();
        disablePalette.setColor(QPalette::Disabled,
                                QPalette::Light,
                                QColor(128, 128, 128));
        aroundXSlider->setPalette(disablePalette);
        aroundYSlider->setPalette(disablePalette);
        aroundZSlider->setPalette(disablePalette);
        autoPilotButton->setText("Disable autopilot");
        myThread->start();
        autopilotIsEnabled=true;
    }
}

void Widget::paintEvent(QPaintEvent *){
    // Процедура отрисовки окна с изображением
    this->setWindowTitle("Width: " +
                         QString::number(this->width()) +
                         " Height: " +
                         QString::number(this->height()));
    QPainter painter(this);
    painter.setPen(Qt::blue);
    qreal windowHalfHeight = this->height()/2,
            windowHalfWidth = this->width()/2;
    int firstDot, secondDot;

    // Отрисовка трёхмерного объекта
    for (int i = 0; i < object3d->getLinksCount(); i++){
        firstDot = object3d->getLinkFirstDot(i);
        secondDot = object3d->getLinkSecondDot(i);
        painter.drawLine(QPoint(object3d->getY(firstDot) +
                                windowHalfWidth,
                                object3d->getX(firstDot) +
                                windowHalfHeight),
                         QPoint(object3d->getY(secondDot) +
                                windowHalfWidth,
                                object3d->getX(secondDot) +
                                windowHalfHeight));
    }
}

Widget::~Widget()
{
    // Деструктор виджета
}

void Widget::sliderZchanged(int value){
    // Реакция на изменение слайдера с углом Z
    zAngleLabel->setText("Z angle: " +
                         QString::number(value));
    object3d->setZAngle(value*3.14/180);
    update();
}

void Widget::sliderXchanged(int value){
    // Реакция на изменение слайдера с углом X
    xAngleLabel->setText("X angle: " +
                         QString::number(value));
    object3d->setXAngle(value*3.14/180);
    update();
}

void Widget::sliderYchanged(int value){
    // Реакция на изменение слайдера с углом Y
    yAngleLabel->setText("Y angle: " +
                         QString::number(value));
    object3d->setYAngle(value*3.14/180);
    update();
}

void Widget::autopilotDatas(qreal XAngle, qreal YAngle, qreal ZAngle){
    // Реакция на сигнал с новыми углами поворотов от автопилота
    object3d->setXAngle(XAngle);
    object3d->setYAngle(YAngle);
    object3d->setZAngle(ZAngle);
    aroundXSlider->setValue((((int)(XAngle * 180 / 3.14) % 360)+360)%360);
    aroundYSlider->setValue((((int)(YAngle * 180 / 3.14) % 360)+360)%360);
    aroundZSlider->setValue((((int)(ZAngle * 180 / 3.14) % 360)+360)%360);
    update();
}

void Widget::selectShape(){
    // Реакция на выбор фигуры из ComboBox-а
    if (!autopilotIsEnabled){
        setNewObject();
    }
    else myAutopilot->pauseOnOff();
}

void Widget::setNewObject(){
    // Процедура установки нового объекта в myObject
    switch (shapeComboBox->currentIndex()) {
    case 0:
    {
        // Реализация трёхмерного объекта "Куб"
        qreal cubeDots[8][3] = {{50, -50, -50}, {50, -50, 50}, {50, 50, 50},
                                {50, 50, -50}, {-50, -50, -50}, {-50, -50, 50},
                                {-50, 50, 50}, {-50, 50, -50}};
        int cubeLinks[] = {0, 1, 0, 4, 0, 3, 1, 2, 1, 5, 2, 6,
                           2, 3, 3, 7, 5, 6, 5, 4, 6, 7, 4, 7};
        object3d->setObject(&cubeDots[0][0], 8, &cubeLinks[0], 24);
        update();
    }
        break;
    case 1:
    {
        // Реализация трёхмерного объекта "Пирамида"
        qreal tetraDots[4][3] = {{0, 0, 100}, {0, -100, 0}, {-50, 50, 0},
                                 {50, 50, 0}};

        int tetraLinks[] = {0, 1, 0, 2, 0, 3, 1, 0, 1, 2, 1, 3, 2, 0, 2, 1,
                            2, 3, 3, 0, 3, 1, 3, 2};
        object3d->setObject(&tetraDots[0][0], 4, &tetraLinks[0], 24);
        update();
    }
        break;
    case 2:
    {
        qreal starDots[12][3] = {{200, 0, 0}, {60, 190, 0}, {-160, 116, 0},
                                 {-160, -116, 0}, {60, -190, 0}, {60, 44, 0},
                                 {-22, 72, 0}, {-76, 0, 0}, {-22, -72, 0},
                                 {60, -44, 0}, {0, 0, 25}, {0, 0, -25}};
        int starLinks[] = {0, 5, 0, 10, 0, 11, 0, 9, 1, 5, 1, 6, 1, 11,
                          1, 10, 2, 6, 2, 7, 2, 11, 2, 10, 3, 7, 3, 8,
                          3, 11, 3, 10, 4, 8, 4, 9, 4, 11, 4, 10, 5, 11,
                          5, 10, 6, 11, 6, 10, 7, 11, 7, 10, 8, 11, 8, 10,
                          9, 11, 9, 10};
        object3d->setObject(&starDots[0][0], 12, &starLinks[0], 60);
        update();

    }
        break;
    default:
        break;
    }
}

void Widget::autopilotPaused(){
    // Смена объекта при паузе автопилота
    setNewObject();
    myAutopilot->pauseOnOff();
}
