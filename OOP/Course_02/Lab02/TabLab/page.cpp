#include "page.h"

Page::Page(QWidget *parent) :
    QWidget(parent)
{
    //QLabel * label;
    QFrame * myFrame = new QFrame;
    myFrame->setFrameStyle(QFrame::Box | QFrame::Raised);
    //label = new QLabel("First Label");
    QVBoxLayout * mainLayout = new QVBoxLayout;
    QGroupBox * groupBox = new QGroupBox(tr("Exclusive Radio Buttons"));
    QVBoxLayout * frameLayout = new QVBoxLayout;
    frameLayout->addWidget(groupBox);
    //groupBox->setGeometry(0, 0, myFrame->width(), myFrame->height());
    QPixmap pix("Images/Seasons/Winter.jpg");
    QPalette pal;
    QLabel * label1 = new QLabel(tr("First Label"), groupBox);
    pal.setBrush(label1->backgroundRole(), QBrush(pix));
    label1->setPalette(pal);
    label1->setAutoFillBackground(true);
    label1->setFixedSize(pix.width(), pix.height());
    label1->setGeometry(50, 50, label1->width(), label1->height());
    QLabel * label2 = new QLabel(tr("Second Label"), groupBox);
    label2->setGeometry(150, 50, label2->width(), label2->height());
    QLabel * label3 = new QLabel(tr("Third Label"), groupBox);
    label3->setGeometry(50, 100, label3->width(), label3->height());
    QTextEdit * textEdit = new QTextEdit(groupBox);
    textEdit->setGeometry(150, 100, 150, 90);
    myFrame->setLayout(frameLayout);
    //mainLayout -> addWidget(label);
    mainLayout->addWidget(myFrame);
    setLayout(mainLayout);
}
