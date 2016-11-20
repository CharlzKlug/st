#ifndef PAGE_H
#define PAGE_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QFrame>
#include <QGroupBox>
#include <QTextEdit>
#include <QPixmap>
#include <QString>

class Page : public QWidget
{
    Q_OBJECT
public:

    //Расшифровка для mode: 0 - ручная компоновка,
    // 1 - QHBoxLayout, 2 - QVBoxLayout, 3 - QGridLayout.
    explicit Page(QString str, int mode, QWidget *parent = 0);

signals:

public slots:

};

#endif // PAGE_H
