#ifndef TOP_H
#define TOP_H
#include <QWidget>

class Top : public QWidget {
    //Bottom * m_bottom;
    void paintEvent(QPaintEvent *) {
        QPainter p(this);
        p.setPen(Qt::NoPen);
        p.setBrush(Qt::blue);
        p.drawRect(0, 0, 1000, 1000);
        //m_bottom->paint(&p);
        p.setBrush(Qt::green);
        p.drawRect(50, 50, 500, 500);
    }
public:
    Top(QWidget * parent = 0) :
        QWidget(parent) {}
};

#endif // TOP_H
