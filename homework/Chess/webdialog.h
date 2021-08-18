#ifndef WEBDIALOG_H
#define WEBDIALOG_H

#include <QWidget>

namespace Ui {
class Webdialog;
}

class Webdialog : public QWidget
{
    Q_OBJECT

public:
    explicit Webdialog(QWidget *parent = nullptr);
    ~Webdialog();

signals:
    //发射信号给主函数
    void ASignal();

private:
    Ui::Webdialog *ui;
};

#endif // WEBDIALOG_H
