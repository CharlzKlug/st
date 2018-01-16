#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <math.h>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>
#include "Autopilot.h"
#include <QComboBox>
#include <QLineEdit>
#include <QFormLayout>
#include "rkmethod.h"
#include <QString>

// Основной класс
class Widget : public QWidget
{
    Q_OBJECT
private:
    // Координата X первого тела
    QLineEdit * xALineEdit;

    // Координата Y первого тела
    QLineEdit * yALineEdit;

    // Масса первого тела
    QLineEdit* massALineEdit;

    // Скорость X первого тела
    QLineEdit* xASpeedLineEdit;

    // Скорость Y первого тела
    QLineEdit* yASpeedLineEdit;

    // Координата X второго тела
    QLineEdit* xBLineEdit;

    // Координата Y второго тела
    QLineEdit* yBLineEdit;

    // Масса второго тела
    QLineEdit* massBLineEdit;

    // Скорость X первого тела
    QLineEdit* xBSpeedLineEdit;

    // Скорость Y первого тела
    QLineEdit* yBSpeedLineEdit;

    // Приращение времени
    QLineEdit* dtLineEdit;

    // Масштаб графики
    QLineEdit* scaleLineEdit;

    // Объект решения Рунге-Кутта
    RKMethod* myRK;

    // Клавиша запуска автопилота
    QPushButton * autoPilotButton;

    // Объект автопилота
    Autopilot * myAutopilot;

    // Тред для автопилота
    QThread * myThread;

    // Отображение включённости автопилота
    bool autopilotIsEnabled;

    // Преобразование мирового вектора в экранную точку
    QPoint mSP(Vector, qreal);
public:
    Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~Widget();
public  slots:

    // Реакция на нажатие клавиши автопилота
    void buttonAutopilotPressed();

    // Реакция на сигнал тика от автопилота
    void onTick();

    // Реакция на паузу автопилота
    void autopilotPaused();
};

#endif // WIDGET_H
