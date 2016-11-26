#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <page.h>
#include <QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QTabWidget * tabWidget; // Виджет отвечающий за табы

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void onTabCloseRequested();

signals:
    void tabCloseRequest();


};

#endif // WIDGET_H
