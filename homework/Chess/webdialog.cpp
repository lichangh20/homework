#include "webdialog.h"
#include "ui_webdialog.h"

Webdialog::Webdialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Webdialog)
{
    ui->setupUi(this);

    //固定大小
    this->setFixedSize(300,200);
    setWindowTitle("Create the connection");

    connect(ui->ButtonOk,&QPushButton::clicked,
            [=]()
            {
                this->close();
                emit ASignal();
            }
            );

    connect(ui->ButtonCancel,&QPushButton::clicked,
            [=]()
            {
                this->close();
            }
            );
}

Webdialog::~Webdialog()
{
    delete ui;
}
