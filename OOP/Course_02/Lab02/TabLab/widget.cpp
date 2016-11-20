#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8")); //изменения
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); //изменения
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")); //изменения

    tabWidget = new QTabWidget;
    tabWidget->setMovable(true);
    tabWidget->setTabsClosable(true);
    tabWidget->setTabPosition(QTabWidget::South);
    //QWidget * newTab = new QWidget(tabWidget);
    tabWidget -> addTab(new Page("Ручное размещение объектов", 0), tr("Первая закладка"));
    tabWidget ->addTab(new Page("Компоновка QHBoxLayout", 1), tr("Вторая закладка"));
    tabWidget ->addTab(new Page("Компоновка QVBoxLayout", 2), tr("Третья закладка"));
    tabWidget ->addTab(new Page("Компоновка QGridLayout", 3), tr("Четвёртая закладка"));
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
