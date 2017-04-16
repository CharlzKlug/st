#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>
#include <QTextCodec>
#include <QSignalMapper>
#include <math.h>

class Widget : public QWidget
{
    Q_OBJECT
private:
    int red, green, blue;
    double learnSpeed;
    QPushButton* buttonColor;

    QPushButton* buttonRed;
    QPushButton* buttonGreen;
    QPushButton* buttonBlue;
    QPushButton* buttonBlack;
    QPushButton* buttonWhite;
    QPushButton* buttonYellow;
    QPushButton* buttonSkyBlue;
    QPushButton* buttonPurple;
    QPushButton* buttonOrange;
    QPushButton* buttonNext;
    QLabel* labelColorName;
    double neurons[4][3];
    void setRandomColor();
    int firstBit, secondBit, thirdBit, fourthBit;
    int perceptronReaction(int);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void detectColor();
public slots:
    void next();
    void learnNeurons(int);
signals:
};

#endif // WIDGET_H
