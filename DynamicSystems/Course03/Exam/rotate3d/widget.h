#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <math.h>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QSlider>
#include <QLabel>
#include "Object3D.h"
#include "Autopilot.h"
#include <QComboBox>

// Основной класс
class Widget : public QWidget
{
    Q_OBJECT
private:
    // Слайдер поворота вокруг оси Z
    QSlider * aroundZSlider;
    QLabel * zAngleLabel;

    // Слайдер поворота вокруг оси X
    QSlider * aroundXSlider;
    QLabel * xAngleLabel;

    // Слайдер поворота вокруг оси Y
    QSlider * aroundYSlider;
    QLabel * yAngleLabel;

    // Трёхмерный объект
    Object3D * object3d;

    // Клавиша запуска автопилота
    QPushButton * autoPilotButton;

    // Объект автопилота
    Autopilot * myAutopilot;

    // Тред для автопилота
    QThread * myThread;

    // Отображение включённости автопилота
    bool autopilotIsEnabled;

    // ComboBox с трёхмерными фигурами
    QComboBox * shapeComboBox;

    // Процедура установки нового объекта
    void setNewObject();
public:
    Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~Widget();
public  slots:

    // Реакция на изменение слайдера с углом Z
    void sliderZchanged(int value);

    // Реакция на изменение слайдера с углом X
    void sliderXchanged(int value);

    // Реакция на изменение слайдера с углом Y
    void sliderYchanged(int value);

    // Реакция на нажатие клавиши автопилота
    void buttonAutopilotPressed();

    // Реакция на сигнал с новыми углами поворотов от автопилота
    void autopilotDatas(qreal XAngle,
                        qreal YAngle,
                        qreal ZAngle);

    // Реакция на выбор фигуры из ComboBox-а
    void selectShape();

    // Реакция на паузу автопилота
    void autopilotPaused();
};

#endif // WIDGET_H
