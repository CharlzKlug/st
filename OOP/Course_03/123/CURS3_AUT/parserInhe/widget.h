//BAKALAVR\CURS3\parserInhe\widget.h         16.08.2017 Кожевников А.А.
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "exprInhe.h"
#include "parserInhe.h"
#include "myPainter.h"

class Widget : public QWidget, public MyPainter
{
    Q_OBJECT
    QTableWidget *table;
    QGroupBox *group;
    QLineEdit *edit;
    QPushButton   *butTab, *butGraph;
    QDoubleSpinBox *spinA, *spinB, *spinH;
    QDockWidget *dock;
    ExprInhe *objExpr;
/*можно включить в описание класа
    qreal a, b, h;
    int n;
    QPolygonF node;
    QRectF rectW;
*/
    void createWidgets();
    void createLayouts();
    void createConnections();
    QRect &rectScreen();
public:
    Widget( QWidget *par=0);
     ~Widget(){}
protected:
   void paintEvent(QPaintEvent *ev);
public slots:
   void showTable();
   void showGraph();
   void slotABH(qreal);
   void slotEdit();
};
#endif // WIDGET_H


