#include "singleimagepage.h"

SingleImagePage::SingleImagePage(QString picture, int imageWidth,
                                 int imageHeight, QWidget *parent) : QWidget(parent)
{
    //this->setStyleSheet("background-color: blue;");
    //QLabel * pictureLabel = new QLabel("<IMG SRC=\"" + picture +
    //                                 "\">");
    QLabel * pictureLabel = new QLabel;
    QVBoxLayout * myLayout = new QVBoxLayout;
    //myLayout->setMargin(0);

    pictureLabel->setFixedSize(imageWidth, imageHeight);
    pictureLabel->setStyleSheet("background-image: url("+ picture +");"
                                "border-style:solid;"
                                "border-width: 1px;"
                                "border-color: green;");
    myLayout->addWidget(pictureLabel);
    setLayout(myLayout);
}
