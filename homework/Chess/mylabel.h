#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include<QLabel>

class mylabel : public QLabel
{
    Q_OBJECT
public:
    explicit mylabel(QWidget *parent = nullptr);

protected:
    //重载鼠标按下事件
    void mousePressEvent(QMouseEvent *ev) override;

signals:

};

#endif // MYLABEL_H
