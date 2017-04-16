#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);

    QVBoxLayout* myLayout = new QVBoxLayout;
    QHBoxLayout* colornameLayout = new QHBoxLayout;
    QHBoxLayout* layoutRGB = new QHBoxLayout;
    QHBoxLayout* layoutBWY = new QHBoxLayout;
    QHBoxLayout* layoutSBPO = new QHBoxLayout;


    /*
    red=255;
    green=100;
    blue=150;
    */
    buttonColor = new QPushButton();
//    buttonColor->setStyleSheet("background-color:QColor("+QString::number(red)+","+
//                               QString::number(green)+","+QString::number(blue)+");");
    setRandomColor();
    learnSpeed = 0.3;
    labelColorName = new QLabel("Название цвета");
    buttonRed = new QPushButton("Красный");
    buttonGreen = new QPushButton("Зелёный");
    buttonBlue = new QPushButton("Синий");
    buttonBlack = new QPushButton("Чёрный");
    buttonWhite = new QPushButton("Белый");
    buttonYellow = new QPushButton("Жёлтый");
    buttonSkyBlue = new QPushButton("Голубой");
    buttonPurple = new QPushButton("Фиолетовый");
    buttonOrange = new QPushButton("Оранжевый");
    buttonNext = new QPushButton("Далее");
    QObject::connect(buttonNext, SIGNAL(clicked()), this, SLOT(next()));
    QSignalMapper* signalMapper = new QSignalMapper(this);
    signalMapper->setMapping(buttonRed, 0);
    signalMapper->setMapping(buttonGreen, 1);
    signalMapper->setMapping(buttonBlue, 2);
    signalMapper->setMapping(buttonBlack, 3);
    signalMapper->setMapping(buttonWhite, 4);
    signalMapper->setMapping(buttonYellow, 5);
    signalMapper->setMapping(buttonSkyBlue, 6);
    signalMapper->setMapping(buttonPurple, 7);
    signalMapper->setMapping(buttonOrange, 8);

    QObject::connect(buttonRed, SIGNAL(clicked()), signalMapper, SLOT(map()));
    QObject::connect(buttonGreen, SIGNAL(clicked()), signalMapper, SLOT(map()));
    QObject::connect(buttonBlue, SIGNAL(clicked()), signalMapper, SLOT(map()));
    QObject::connect(buttonBlack, SIGNAL(clicked()), signalMapper, SLOT(map()));
    QObject::connect(buttonWhite, SIGNAL(clicked()), signalMapper, SLOT(map()));
    QObject::connect(buttonYellow, SIGNAL(clicked()), signalMapper, SLOT(map()));
    QObject::connect(buttonSkyBlue, SIGNAL(clicked()), signalMapper, SLOT(map()));
    QObject::connect(buttonPurple, SIGNAL(clicked()), signalMapper, SLOT(map()));
    QObject::connect(buttonOrange, SIGNAL(clicked()), signalMapper, SLOT(map()));

    QObject::connect(signalMapper, SIGNAL(mapped(int)), this,
                     SLOT(learnNeurons(int)));

    for (int i = 0; i<4; i++)
        for (int j = 0; j<3; j++){
            neurons[i][j] = 0.6 * rand()/RAND_MAX - 0.3;
        }

    colornameLayout->addWidget(buttonColor);
    colornameLayout->addWidget(labelColorName);
    //myLayout->addWidget(buttonColor);
    //myLayout->addWidget(labelColorName);
    layoutRGB->addWidget(buttonRed);
    layoutRGB->addWidget(buttonGreen);
    layoutRGB->addWidget(buttonBlue);

    layoutBWY->addWidget(buttonBlack);
    layoutBWY->addWidget(buttonWhite);
    layoutBWY->addWidget(buttonYellow);

    layoutSBPO->addWidget(buttonSkyBlue);
    layoutSBPO->addWidget(buttonPurple);
    layoutSBPO->addWidget(buttonOrange);

    myLayout->addLayout(colornameLayout);
    myLayout->addLayout(layoutRGB);
    myLayout->addLayout(layoutBWY);
    myLayout->addLayout(layoutSBPO);
    //myLayout->addLayout();
    //myLayout->addWidget(buttonRed);
    //myLayout->addWidget(buttonGreen);
    myLayout->addWidget(buttonNext);
    this->setLayout(myLayout);
    detectColor();
}

Widget::~Widget()
{

}

void Widget::setRandomColor(){
    red = 255.0 * rand()/RAND_MAX;
    green = 255.0 * rand()/RAND_MAX;
    blue = 255.0 * rand()/RAND_MAX;
    buttonColor->setStyleSheet("background-color:QColor("+
                               QString::number(red)+","+
                               QString::number(green)+","+
                               QString::number(blue)+");");

}

int Widget::perceptronReaction(int n)
{
    //double n;
    double sum = 0;
    sum += neurons[n][0] * red;
    sum += neurons[n][1] * green;
    sum += neurons[n][2] * blue;
    if (sum >= 0) return 1;
    return 0;
}

void Widget::detectColor()
{
    int result = 0;
    for (int i = 0; i<4; i++)
        result += perceptronReaction(i)*pow(2, i);
    switch (result) {
    case 0:
        labelColorName->setText("Красный");
        break;
    case 1:
        labelColorName->setText("Зелёный");
        break;
    case 2:
        labelColorName->setText("Синий");
        break;
    case 3:
        labelColorName->setText("Чёрный");
        break;
    case 4:
        labelColorName->setText("Белый");
        break;
    case 5:
        labelColorName->setText("Жёлтый");
        break;
    case 6:
        labelColorName->setText("Голубой");
        break;
    case 7:
        labelColorName->setText("Фиолетовый");
        break;
    case 8:
        labelColorName->setText("Оранжевый");
        break;
    default:
        labelColorName->setText("Не определено");

    }
}

void Widget::next()
{
    setRandomColor();
    detectColor();
}

void Widget::learnNeurons(int correctData)
{
    int remain, sigma, reaction;
    for (int i = 0; i<4; i++)
    {
        remain = correctData % 2;
        reaction = perceptronReaction(i);
        if (remain != reaction)
        {
            sigma = remain - reaction;
            neurons[i][0] += learnSpeed * sigma * red;
            neurons[i][1] += learnSpeed * sigma * green;
            neurons[i][2] += learnSpeed * sigma * blue;
        }
        correctData = correctData / 2;
    }
    detectColor();
}
