#include "widget.h"

Dots::Dots(QWidget *parent)
    : QWidget(parent)
{
}

Dots::~Dots()
{

}

void Dots::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::blue);
    p.drawRect(0, 0, 1000, 1000);
    //m_bottom->paint(&p);
    p.setBrush(Qt::green);
    p.drawRect(50, 50, 500, 500);

}
