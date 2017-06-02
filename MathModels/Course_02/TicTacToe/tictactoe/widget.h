#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QSignalMapper>
#include <QMessageBox>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QPushButton* buttonsArray[10][10];
    int field[10][10]; // Игровое поле. Используется для минимакса.
    int winLength; // Длина ряда для выигрыша
    QSignalMapper* signalMapper;
    bool isWinX();
    bool isWin(int, int);
    void resetButtons();
    int ratingOfPosition(int, bool); // Рейтинг позиции
    int bestMove(); // Возвращает лучший ход в виде целого числа
    int bestMoveDepth(int);
    // Лучший ход в виде целого числа с некоторой глубиной.
    bool isWinO();
    int ratingPosition();
    int rateHoriz(int, int, int);
    int rateVert(int, int, int);
    int rateDiagOne(int, int, int);
    // По диагонали сверху-вниз слева-направо
    int rateDiagTwo(int, int, int);
    // По диагонали сверху-вниз справа-налево
    int rate(int, int, int, int, int); // Обобщённая фунция оценки
public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void catchSignal(int);
};

#endif // WIDGET_H
