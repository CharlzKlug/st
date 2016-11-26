#include "singleimagepage.h"

SingleImagePage::SingleImagePage(QString picture, int imageWidth,
                                 int imageHeight, QWidget *parent) : QWidget(parent)
{
    QLabel * pictureLabel = new QLabel;
    QVBoxLayout * myLayout = new QVBoxLayout;
    pictureLabel->setFixedSize(imageWidth, imageHeight);
    pictureLabel->setStyleSheet("background-image: url("+ picture +");"
                                "border-style:solid;"
                                "border-width: 1px;"
                                "border-color: green;");
    myLayout->addWidget(pictureLabel);
    setLayout(myLayout);
}
