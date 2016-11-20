#include "page.h"

Page::Page(QString str, int mode, QWidget *parent) :
    QWidget(parent)
{
    QFrame * myFrame = new QFrame;
    myFrame->setFrameStyle(QFrame::Box | QFrame::Raised);

    QVBoxLayout * mainLayout = new QVBoxLayout;
    QGroupBox * groupBox = new QGroupBox(str);
    QVBoxLayout * frameLayout = new QVBoxLayout;
    frameLayout->addWidget(groupBox);

    QPixmap pix("Images/Seasons/Winter.jpg");
    QPalette pal;
    QLabel * label1 = new QLabel( groupBox);
    pal.setBrush(label1->backgroundRole(), QBrush(pix));
    label1->setPalette(pal);
    label1->setAutoFillBackground(true);
    label1->setFixedSize(pix.width(), pix.height());
    //label1->setGeometry(50, 50, label1->width(), label1->height());

    QPixmap pix2("Images/Seasons/Spring.jpg");
    QPalette pal2;
    QLabel * label2 = new QLabel(groupBox);
    pal2.setBrush(label2->backgroundRole(), QBrush(pix2));
    label2->setPalette(pal2);
    label2->setAutoFillBackground(true);
    label2->setFixedSize(pix2.width(), pix2.height());
    //    label2->setGeometry(400, 50, label2->width(), label2->height());

    QLabel * label3 = new QLabel("<IMG BORDER=\"0\" SRC=\"Images/Seasons/Summer.jpg\">", groupBox);
//    label3->setGeometry(50, 400, 251, 154);

    QTextEdit * textEdit = new QTextEdit(groupBox);
//    textEdit->setGeometry(400, 400, 300, 150);
    textEdit->setText("<IMG BORDER=\"0\" SRC=\"Images/Seasons/Autumn.jpg\">");

    switch (mode) {
    case 0:
        label1->setGeometry(50, 50, label1->width(), label1->height());
        label2->setGeometry(400, 50, label2->width(), label2->height());
        label3->setGeometry(50, 400, 251, 154);
        textEdit->setGeometry(400, 400, 300, 150);
        break;
    case 1:
    {
        QHBoxLayout * groupBoxLayout = new QHBoxLayout;
        groupBoxLayout->addWidget(label1);
        groupBoxLayout->addWidget(label2);
        groupBoxLayout->addWidget(label3);
        groupBoxLayout->addWidget(textEdit);
        groupBox->setLayout(groupBoxLayout);
    }
        break;
    case 2:
    {
        QVBoxLayout * groupBoxLayout = new QVBoxLayout;
        groupBoxLayout->addWidget(label1);
        groupBoxLayout->addWidget(label2);
        groupBoxLayout->addWidget(label3);
        groupBoxLayout->addWidget(textEdit);
        groupBox->setLayout(groupBoxLayout);
    }
        break;
    case 3:
    {
        QGridLayout * groupBoxLayout = new QGridLayout();
        groupBoxLayout->addWidget(label1, 0,0);
        groupBoxLayout->addWidget(label2, 0, 1);
        groupBoxLayout->addWidget(label3, 1, 0);
        groupBoxLayout->addWidget(textEdit, 1, 1);
        groupBox->setLayout(groupBoxLayout);
    }
        break;
    default:
        break;
    }
/*


    */
    myFrame->setLayout(frameLayout);

    mainLayout->addWidget(myFrame);
    setLayout(mainLayout);
}
