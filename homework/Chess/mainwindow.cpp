#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QAction>
#include<QMessageBox>
#include<mydialog.h>
#include<webdialog.h>
#include<mylabel.h>
#include<QTime>
#include<mychess.h>
#include<globalvariable.h>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(500,715);

    //前置操作：为棋子分配随机数，每个棋子分别对应一个,第i个旗子的随机数对应numberlist[i]
    random();

    //设置图片内容
    ui->labelBackground->setPixmap(QPixmap("://png/chessboard.png"));

    //设置图片格式,让图片自动适应窗口大小
    ui->labelBackground->setScaledContents(true);

    //在棋盘上摆放旗子初始位置，并初始化棋子
    laychess();



    //先将背景隐藏
    ui->labelBackground->hide();

    //唤起服务器窗口
    connect(ui->actionCreate,&QAction::triggered,
            [=]()
            {
                wdg.show();

                connect(&wdg,&Webdialog::ASignal,
                        [=]()
                        {
                            //背景显示
                            ui->labelBackground->show();
                        }
                        );
            }
            );


    //唤起客户端窗口
    connect(ui->actionConnect,&QAction::triggered,
            [=]()
            {
                //展示窗口
                mdg.show();

                //客户端窗口画背景图
                connect(&mdg,&Mydialog::mySignal,
                        [=]()
                        {
                            //背景显示
                            ui->labelBackground->show();
                        }
                        );

            }
            );



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::random()
{
    //蓝方：
    //军旗，司令，军长
    for(int i=0;i<3;i++)
        numbersList[i]=i;

    //师长，旅长，团长，营长，炸弹
    for(int i=3;i<8;i++)
    {
        numbersList[2*i-3]=i;
        numbersList[2*i-2]=i;
    }

    //连长，排长，工兵，地雷
    for(int i=8;i<12;i++)
    {
        numbersList[3*i-11]=i;
        numbersList[3*i-10]=i;
        numbersList[3*i-9]=i;
    }

    //红方：
    //军旗，司令，军长
    for(int i=12;i<15;i++)
        numbersList[i+13]=i;

    //师长，旅长，团长，营长，炸弹
    for(int i=15;i<20;i++)
    {
        numbersList[2*i-2]=i;
        numbersList[2*i-1]=i;
    }

    //连长，排长，工兵，地雷
    for(int i=20;i<24;i++)
    {
        numbersList[3*i-22]=i;
        numbersList[3*i-21]=i;
        numbersList[3*i-20]=i;
    }

    //打乱顺序，重新排布
    //打乱三次，使打乱的更加彻底
    for (int j=0;j<3;j++)
    {
        for(int i=0;i<50;i++)
         {
            QTime t;
            t= QTime::currentTime();
            srand(t.msec()+t.second()*1000);
            int r = i+rand()%(50-i);
            int temp=numbersList[i];
            numbersList[i]=numbersList[r];
            numbersList[r]=temp;
         }
    }
}

void MainWindow::laychess()
{
    //0-4棋子，45-49棋子
    for(int i=0;i<5;i++)
    {
        chs[i].move(startX+i*(gridW+distanceX),startY);
        chs[i+45].move(startX+i*(gridW+distanceX),startY+10*(gridH+distanceY)+gridH+middleY);
        chs[i].position=i;
        chs[i+45].position=i+55;
    }

    //5-9棋子,40-44棋子
    for(int i=5;i<10;i++)
    {
        chs[i].move(startX+(i-5)*(gridW+distanceX),startY+gridH+distanceY);
        chs[i+35].move(startX+(i-5)*(gridW+distanceX),startY+9*(gridH+distanceY)+gridH+middleY);
        chs[i].position=i;
        chs[i+35].position=i+45;
    }

    //10-12棋子,37-39棋子
    for(int i=10;i<13;i++)
    {
        chs[i].move(startX+(2*i-20)*(gridW+distanceX),startY+2*(gridH+distanceY));
        chs[i+27].move(startX+(2*i-20)*(gridW+distanceX),startY+8*(gridH+distanceY)+gridH+middleY);
        chs[i].position=2*i-10;
        chs[i+27].position=2*i+25;
    }

    //13-14棋子，33-34棋子
    for(int i=13;i<15;i++)
    {
        chs[i].move(startX+(i-13)*(gridW+distanceX),startY+3*(gridH+distanceY));
        chs[i+20].move(startX+(i-13)*(gridW+distanceX),startY+7*(gridH+distanceY)+gridH+middleY);
        chs[i].position=i+2;
        chs[i+20].position=i+27;
    }

    //15-16棋子，35-36棋子
    for(int i=15;i<17;i++)
    {
        chs[i].move(startX+(i-12)*(gridW+distanceX),startY+3*(gridH+distanceY));
        chs[i+20].move(startX+(i-12)*(gridW+distanceX),startY+7*(gridH+distanceY)+gridH+middleY);
        chs[i].position=i+3;
        chs[i+20].position=i+28;
    }

    //17-19棋子，30-32棋子
    for(int i=17;i<20;i++)
    {
        chs[i].move(startX+(2*i-34)*(gridW+distanceX),startY+4*(gridH+distanceY));
        chs[i+13].move(startX+(2*i-34)*(gridW+distanceX),startY+6*(gridH+distanceY)+gridH+middleY);
        chs[i].position=2*i-14;
        chs[i+13].position=2*i+1;
    }

    //20-24棋子，25-29棋子
    for(int i=20;i<25;i++)
    {
        chs[i].move(startX+(i-20)*(gridW+distanceX),startY+5*(gridH+distanceY));
        chs[i+5].move(startX+(i-20)*(gridW+distanceX),startY+5*(gridH+distanceY)+gridH+middleY);
        chs[i].position=i+5;
        chs[i+5].position=i+5;
    }

    //50-51棋子，58-59棋子
    for(int i=50;i<52;i++)
    {
        chs[i].move(startX+(2*i-99)*(gridW+distanceX),startY+2*(gridH+distanceY));
        chs[i+8].move(startX+(2*i-99)*(gridW+distanceX),startY+8*(gridH+distanceY)+gridH+middleY);
        chs[i].position=2*i-89;
        chs[i+8].position=2*i-70;
    }

    //52,57棋子
    for(int i=52;i<53;i++)
    {
        chs[i].move(startX+(i-50)*(gridW+distanceX),startY+3*(gridH+distanceY));
        chs[i+5].move(startX+(i-50)*(gridW+distanceX),startY+7*(gridH+distanceY)+gridH+middleY);
        chs[i].position=i-35;
        chs[i+5].position=i-10;
    }

    //53-54棋子，55-56棋子
    for(int i=53;i<55;i++)
    {
        chs[i].move(startX+(2*i-105)*(gridW+distanceX),startY+4*(gridH+distanceY));
        chs[i+2].move(startX+(2*i-105)*(gridW+distanceX),startY+6*(gridH+distanceY)+gridH+middleY);
        chs[i].position=2*i-85;
        chs[i+2].position=2*i-70;
    }

    //给棋子传参，并使棋子显现
    for(int i=0;i<50;i++)
    {
        chs[i].kind=numbersList[i];
        chs[i].number=i;
        chs[i].exist=1;
        chs[i].setParent(ui->labelBackground);
    }

    for(int i=50;i<60;i++)
    {
        chs[i].number=i;
        chs[i].exist=0;
        chs[i].setParent(ui->labelBackground);
    }

    //更新初始状态下行营中伪棋子图片
    for(int i=50;i<60;i++)
    {
        chs[i].setPixmap(QPixmap("://png/blank_xingy.png"));
        chs[i].setScaledContents(true);
    }

}
