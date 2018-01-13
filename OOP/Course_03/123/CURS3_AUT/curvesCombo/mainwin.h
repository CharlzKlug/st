//..\curvesCombo\mainwin.h           22.09.2015  Кожевников А.А.
#ifndef MAINWIN_H
#define MAINWIN_H
#include "function.h"
#include "mypainter.h"
typedef double TFunc (double);
typedef TFunc* PFunc;
class MainWin : public QMainWindow, virtual public MyPainter
{
    Q_OBJECT

    QGroupBox *group;
    QComboBox *comboExp;
    QDockWidget *dock;
    QWidget *wid;
     //виджеты для ввода параметров табулирования a, b, h
    QSlider *sliderA, *sliderB, *sliderN;
    QLabel *labelA, *labelB, *labelN;
    static QList<PFunc>lstFunc;                              //список указателей на функции
    QStringList lstExp;                                           //список символьных выражений
    Function *obj;                                                                  //указатель на объект
    //    qreal a, b, h;
    //    int n;                                                               //параметры табулирования
    void readExpressions();
public:
   MainWin(QWidget *parent = 0);
   void createWidgets();
   void createLayouts();
   void createConnections();
   QRect &rectScreen();
   ~MainWin();
protected:
   void paintEvent(QPaintEvent *ev);
public slots:
   void slotComboExp(int k);
   //void slotComboString(const QString&);
   void slotSlider(int);
};
#endif // MAINWIN_H
