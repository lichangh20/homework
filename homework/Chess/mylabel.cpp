#include "mylabel.h"
#include<QMouseEvent>
#include<QDebug>

mylabel::mylabel(QWidget *parent) : QLabel(parent)
{

}

void mylabel::mousePressEvent(QMouseEvent *ev)
{
    int i=ev->x();
    int j=ev->y();
    QString text= QString("<h1>Mouse press: (%1,%2)</h1>").arg(i).arg(j);
    qDebug()<<text;
}
