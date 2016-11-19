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
    tabWidget -> addTab(new Page(), tr("Первая закладка"));
    tabWidget ->addTab(new Page(), tr("Вторая закладка"));
    tabWidget ->addTab(new Page(), tr("Третья закладка"));
    tabWidget ->addTab(new Page(), tr("Четвёртая закладка"));
    tabWidget ->addTab(new Page(), tr("Пятая закладка"));
    tabWidget ->addTab(new Page(), tr("Шестая закладка"));
    tabWidget ->addTab(new Page(), tr("Седьмая закладка"));
    QVBoxLayout * layout = new QVBoxLayout();
    layout->setMargin(0);
    layout ->addWidget(tabWidget);

    setLayout(layout);
    //tabWidget -> show();
}

Widget::~Widget()
{

}
