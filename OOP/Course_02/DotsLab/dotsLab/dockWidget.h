#ifndef DOCKWIDGET_H
#define DOCKWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLabel>

class SelectionWidget : public QWidget {
    Q_OBJECT
private:
    QComboBox* modes;
    QVBoxLayout* dockLayout;
    QLabel* dotsCount;

public:
    SelectionWidget(QWidget *parent = 0);
    ~DockWidget();
};

#endif // DOCKWIDGET_H
