#ifndef SINGLEIMAGE_H
#define SINGLEIMAGE_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>

class SingleImagePage : public QWidget
{
    Q_OBJECT
public:

    explicit SingleImagePage(QString picture, int imageWidth,
                             int imageHeight, QWidget *parent = 0);

signals:

public slots:

};

#endif // SINGLEIMAGE_H
