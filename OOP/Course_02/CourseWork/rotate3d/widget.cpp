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
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(rect(), Qt::AlignCenter, "Qt");
    painter.drawLine(QPoint(0, 0), QPoint(x, y));
}

Widget::~Widget()
{

}

void Widget::sliderZchanged(int value){
    zAngleLabel->setText("Z angle: " + QString::number(value));
}

void Widget::sliderXchanged(int value){
    xAngleLabel->setText("X angle: " + QString::number(value));
}

void Widget::sliderYchanged(int value){
    yAngleLabel->setText("Y angle: " + QString::number(value));
}
