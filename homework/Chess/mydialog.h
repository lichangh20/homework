#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QWidget>

namespace Ui {
class Mydialog;
}

class Mydialog : public QWidget
{
    Q_OBJECT

public:
    explicit Mydialog(QWidget *parent = nullptr);
    ~Mydialog();

signals:
    //发射信号给主函数
    void mySignal();

private:
    Ui::Mydialog *ui;
};

#endif // MYDIALOG_H
