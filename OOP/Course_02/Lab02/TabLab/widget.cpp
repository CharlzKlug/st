#include "widget.h"
#include "singleimagepage.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    this->setStyleSheet("QWidget{background-color: qradialgradient(cx: 0.5, cy: 0.5, radius: 0.5, fx: 0.5, fy: 0.5, stop: 0 #FF92BB, stop: 0.5 white, stop: 1 blue);}"
                        "QLabel{background-color: none;}"
                        "QTextEdit{background-color: none;}");

    //this->setStyleSheet("QLabel{background-color: none;}");
    //this->setStyleSheet("QLabel { border-style: outset; border-width: 2px; border-color: beige; }");
    tabWidget = new QTabWidget;
    //connect(tabBar(), SIGNAL(tabCloseRequested()), SLOT(QApplication::quit()));
    tabWidget->setMovable(true);
    tabWidget->setTabsClosable(true);

    tabWidget->setTabPosition(QTabWidget::South);
    //tabWidget->setStyleSheet("QTabWidget::pane{background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E0E0E0, stop: 1 blue);}");
    //QWidget * newTab = new QWidget(tabWidget);
    tabWidget -> addTab(new Page("Ручное размещение объектов", 0),
                        tr("Первая закладка"));
    tabWidget ->addTab(new Page("Компоновка QHBoxLayout", 1), tr("Вторая закладка"));
    tabWidget ->addTab(new Page("Компоновка QVBoxLayout", 2), tr("Третья закладка"));
    tabWidget ->addTab(new Page("Компоновка QGridLayout", 3),
                       tr("Четвёртая закладка"));
    tabWidget->addTab(new SingleImagePage("Images/Other/La_Sagrada_Familia.jpg",
                                          500, 451),
                      tr("Пятая закладка"));

  /*  tabWidget->addTab(new SingleImagePage("Images/Other/Conservatory.jpg"),
                      tr("Шестая закладка"));
    tabWidget->addTab(new SingleImagePage("Images/Other/Train.jpg"),
                      tr("Седьмая закладка"));
                      */
    //tabWidget ->addTab(new Page(), tr("Пятая закладка"));
    //tabWidget ->addTab(new Page(), tr("Шестая закладка"));
    //tabWidget ->addTab(new Page(), tr("Седьмая закладка"));
    QVBoxLayout * layout = new QVBoxLayout();
    layout->setMargin(0);
    layout ->addWidget(tabWidget);


    setLayout(layout);
    //tabWidget -> show();
}

Widget::~Widget()
{

}
