#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QPainter>
#include <top.h>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>
#include "controlwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Top* drawWidget;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //void paintEvent(QEvent *);
};

#endif // MAINWINDOW_H
