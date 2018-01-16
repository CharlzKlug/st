#include "widget.h"

// Конструктор главного объекта
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setStyleSheet("background: black;");
    autopilotIsEnabled = false;
    QGroupBox * controlPanel = new QGroupBox(tr("Control panel"));
    QFormLayout* myLayout = new QFormLayout;

    // Координата X первого тела
    xALineEdit = new QLineEdit("0");

    // Координата Y первого тела
    yALineEdit = new QLineEdit("0");

    // Масса первого тела
    massALineEdit = new QLineEdit("6000000000000000000000000.0");

    // Скорость X первого тела
    xASpeedLineEdit = new QLineEdit("0");

    // Скорость Y первого тела
    yASpeedLineEdit = new QLineEdit("0");

    // Координата X второго тела
    xBLineEdit = new QLineEdit("384000");

    // Координата Y второго тела
    yBLineEdit = new QLineEdit("0");

    // Масса второго тела
    massBLineEdit = new QLineEdit("73400000000000000000000.0");

    // Скорость X второго тела
    xBSpeedLineEdit = new QLineEdit("0");

    // Скорость Y второго тела
    yBSpeedLineEdit = new QLineEdit("-3000");

    // Приращение времени
    dtLineEdit = new QLineEdit("0.01");

    // Масштаб графики
    scaleLineEdit = new QLineEdit("0.0008");

    // Клавиша автопилота
    autoPilotButton = new QPushButton("Enable autopilot", controlPanel);
    connect(autoPilotButton, SIGNAL(clicked()), SLOT(buttonAutopilotPressed()));

    // Создание объекта с методом Рунге-Кутта
    myRK = new RKMethod(
                // Положение тела A
                Vector(xALineEdit->text().toDouble(), yALineEdit->text().toDouble()),

                // Положение тела B
                Vector(xBLineEdit->text().toDouble(), yBLineEdit->text().toDouble()),

                // Скорость тела A
                Vector(xASpeedLineEdit->text().toDouble(), yASpeedLineEdit->text().toDouble()),

                // Скорость тела B
                Vector(xBSpeedLineEdit->text().toDouble(), yBSpeedLineEdit->text().toDouble()),

                // Приращение времени dt
                dtLineEdit->text().toDouble(),

                // Масса тела A
                massALineEdit->text().toDouble(),

                // Масса тела B
                massBLineEdit->text().toDouble());

    myLayout->addRow(tr("1st X:"), xALineEdit);
    myLayout->addRow(tr("1st Y:"), yALineEdit);
    myLayout->addRow(tr("1st mass:"), massALineEdit);
    myLayout->addRow(tr("1st X speed:"), xASpeedLineEdit);
    myLayout->addRow(tr("1st Y speed:"), yASpeedLineEdit);
    myLayout->addRow(tr("2nd X:"), xBLineEdit);
    myLayout->addRow(tr("2nd Y:"), yBLineEdit);
    myLayout->addRow(tr("2nd mass:"), massBLineEdit);
    myLayout->addRow(tr("2nd X speed:"), xBSpeedLineEdit);
    myLayout->addRow(tr("2nd Y speed:"), yBSpeedLineEdit);
    myLayout->addRow(tr("dt:"), dtLineEdit);
    myLayout->addRow(tr("Scale:"), scaleLineEdit);
    controlPanel->setLayout(myLayout);
    controlPanel->show();
}

void Widget::buttonAutopilotPressed(){
    // Реакция на нажатие клавиши автопилота
    if (autopilotIsEnabled) {
        // Если автопилот уже был запущен
        myAutopilot->stop();
        autoPilotButton->setText("Enable autopilot");
        autopilotIsEnabled = false;
    }
    else {
        // Если автопилот не был запущен
        myRK->resetAll(
                    // Положение тела A
                    Vector(xALineEdit->text().toDouble(), yALineEdit->text().toDouble()),

                    // Положение тела B
                    Vector(xBLineEdit->text().toDouble(), yBLineEdit->text().toDouble()),

                    // Скорость тела A
                    Vector(xASpeedLineEdit->text().toDouble(), yASpeedLineEdit->text().toDouble()),

                    // Скорость тела B
                    Vector(xBSpeedLineEdit->text().toDouble(), yBSpeedLineEdit->text().toDouble()),

                    // Приращение времени dt
                    dtLineEdit->text().toDouble(),

                    // Масса тела A
                    massALineEdit->text().toDouble(),

                    // Масса тела B
                    massBLineEdit->text().toDouble());

        myThread = new QThread;
        myAutopilot = new Autopilot();
        myAutopilot->moveToThread(myThread);
        connect(myAutopilot, SIGNAL(tick()),
                SLOT(onTick()));
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

    // Ось oY
    painter.drawLine(windowHalfWidth, 0, windowHalfWidth, this->height());
    painter.drawLine(windowHalfWidth, 0, windowHalfWidth - 5, 10);
    painter.drawLine(windowHalfWidth, 0, windowHalfWidth + 5, 10);
    painter.drawText(windowHalfWidth - 15, 15, "Y");

    // Ось oX
    painter.drawLine(this->width(), windowHalfHeight, 0, windowHalfHeight);
    painter.drawLine(this->width(), windowHalfHeight,
                     this->width() - 10, windowHalfHeight - 5);
    painter.drawLine(this->width(), windowHalfHeight,
                     this->width() - 10, windowHalfHeight + 5);
    painter.drawText(this->width() - 15, windowHalfHeight + 15, "X");

    // Рисуем тело A
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    painter.drawText(mSP(myRK->getr1(), scaleLineEdit->text().toDouble()) +
                     QPoint(-10, 10), "A");
    painter.drawEllipse(mSP(myRK->getr1(), scaleLineEdit->text().toDouble()), 2, 2);

    // Рисуем тело B
    painter.setPen(Qt::yellow);
    painter.setBrush(Qt::yellow);
    painter.drawText(mSP(myRK->getr2(), scaleLineEdit->text().toDouble()) +
                     QPoint(-10, 10), "B");
    painter.drawEllipse(mSP(myRK->getr2(), scaleLineEdit->text().toDouble()), 2, 2);

    // Справочная информация
    painter.setPen(Qt::white);
    painter.drawText(10, 20, "Time:" + QString::number(myRK->getTime()));
}

Widget::~Widget()
{
    // Деструктор виджета
}

void Widget::onTick(){
    myRK->iterate();
    update();
}

void Widget::autopilotPaused(){
    // Смена объекта при паузе автопилота
    myAutopilot->pauseOnOff();
}

QPoint Widget::mSP(Vector v, qreal s){
    return QPoint(this->width()/2 + v.getX() * s, this->height()/2 - v.getY() * s);
}
