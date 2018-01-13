//BAKALAVR\..\CURS3_AUT\parsTreeRec\widget.h
//22.09.217  Кожевников А.А.
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "exprtree.h"
#include "parsTreeRec.h"
#include "myPainter.h"

class Widget : public QWidget, public MyPainter
{
    Q_OBJECT
    QTableWidget *table;
    QGroupBox *group;
    QLineEdit *edit;
    QPushButton   *butTab, *butGraph;
    QDoubleSpinBox *spinA, *spinB, *spinH;
    Exprtree *obj;   
    qreal a, b,  minF, maxF;
    int nNode;
    QPolygonF node;
    void createWidgets();
    void createLayouts();
    void createConnections();
    QRect &rectScreen();
public:
    Widget(QWidget *parent = 0);
     ~Widget(){}
public slots:
    void slotEdit();
    void slotABH(qreal);
    void showTable();
protected:
    virtual void paintEvent(QPaintEvent *);
};
#endif // WIDGET_H
