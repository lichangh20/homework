#include "mydialog.h"
#include "ui_mydialog.h"
#include<QKeyEvent>
#include <QRegExp>
#include<QMessageBox>

Mydialog::Mydialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mydialog)
{
    ui->setupUi(this);

    //设置标题
    setWindowTitle("Connect to server");

    //固定大小
    this->setFixedSize(451,494);

    //Cancel键功能
    connect(ui->ButtonCancel,&QPushButton::clicked,
            [=]()
            {
                //窗口关闭
                this->close();
            }
            );

    //OK键网络部分功能下周再做
    connect(ui->ButtonOk,&QPushButton::clicked,
            [=]()
            {
                //判断输入IP格式是否正确，正确向下进行，否则重新来过
                QString str=ui->lineEditIP->text();
                //正确IP地址的格式
                QRegExp rx("\\b((25[0-5]|2[0-4]\\d|[01]?\\d\\d?)\\.){3}(25[0-5]|2[0-4]\\d|[01]?\\d\\d?)\\b");
                //判断str格式是否正确，正确返回0，否则返回-1
                int res=rx.indexIn(str);
                //格式正确，继续操作
                if(res==0)
                {
                //窗口关闭
                this->close();
                //发射信号
                emit mySignal();
                }

                //格式不正确，重新输入
                else if(res==-1)
                {
                    //弹出关于对话框，提示用户重新输入
                    QMessageBox::about(this,"提示信息","您输入的IP地址有误，请重新输入");

                    //将lineEdit清空
                     ui->lineEditIP->setText("");
                }
            }
            );

    //除Delete键外其余基本键的编写
    connect(ui->pushButton1,&QPushButton::clicked,
            [=]()
            {
                //读取文本框内容
                QString str=ui->lineEditIP->text();

                //添加操作
                str+='1';

                //写回文本框
                ui->lineEditIP->setText(str);
            }
            );

    connect(ui->pushButton2,&QPushButton::clicked,
            [=]()
            {
                QString str=ui->lineEditIP->text();
                str+='2';
                ui->lineEditIP->setText(str);
            }
            );

    connect(ui->pushButton3,&QPushButton::clicked,
            [=]()
            {
                QString str=ui->lineEditIP->text();
                str+='3';
                ui->lineEditIP->setText(str);
            }
            );

    connect(ui->pushButton4,&QPushButton::clicked,
            [=]()
            {
                QString str=ui->lineEditIP->text();
                str+='4';
                ui->lineEditIP->setText(str);
            }
            );

    connect(ui->pushButton5,&QPushButton::clicked,
            [=]()
            {
                QString str=ui->lineEditIP->text();
                str+='5';
                ui->lineEditIP->setText(str);
            }
            );

    connect(ui->pushButton6,&QPushButton::clicked,
            [=]()
            {
                QString str=ui->lineEditIP->text();
                str+='6';
                ui->lineEditIP->setText(str);
            }
            );

    connect(ui->pushButton7,&QPushButton::clicked,
            [=]()
            {
                QString str=ui->lineEditIP->text();
                str+='7';
                ui->lineEditIP->setText(str);
            }
            );

    connect(ui->pushButton8,&QPushButton::clicked,
            [=]()
            {
                QString str=ui->lineEditIP->text();
                str+='8';
                ui->lineEditIP->setText(str);
            }
            );

    connect(ui->pushButton9,&QPushButton::clicked,
            [=]()
            {
                QString str=ui->lineEditIP->text();
                str+='9';
                ui->lineEditIP->setText(str);
            }
            );

    connect(ui->pushButton0,&QPushButton::clicked,
            [=]()
            {
                QString str=ui->lineEditIP->text();
                str+='0';
                ui->lineEditIP->setText(str);
            }
            );

    connect(ui->pushButtonpoint,&QPushButton::clicked,
            [=]()
            {
                QString str=ui->lineEditIP->text();
                str+='.';
                ui->lineEditIP->setText(str);
            }
            );


    //Delete键实现
    connect(ui->pushButtonDelete,&QPushButton::clicked,
            [=]()
            {
                QString str=ui->lineEditIP->text();

                //删除最后一个字符
                QString str1=str.left(str.size()-1);
                ui->lineEditIP->setText(str1);
            }
            );
}

Mydialog::~Mydialog()
{
    delete ui;
}


