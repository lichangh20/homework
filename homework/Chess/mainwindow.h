#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<mydialog.h>
#include<webdialog.h>
#include<mychess.h>
#include<globalvariable.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //为棋子分配随机数
    void random();
    //在棋盘上摆放旗子初始位置
    void laychess();

protected:
//    //重载鼠标按下事件
//    void mousePressEvent(QMouseEvent *ev) override;



private:
    Ui::MainWindow *ui;

    //客户端窗口变量
    Mydialog mdg;

    //服务器窗口变量
    Webdialog wdg;

    int startX=9; //兵营横坐标起始值
    int startY=9;//兵营纵坐标起始值
    int gridW=83;//棋子的宽度
    int gridH=40;//棋子的高度
    int distanceX=16;//水平方向相邻棋子间距
    int distanceY=9;//竖直方向相邻棋子间距
    int middleY=111;//中间位置相邻棋子竖直间距

    int numbersList[50];//用于存储棋子对应的随机数

    mychess chs[60];//棋子变量,前50个为正常棋子，后10个为虚拟棋子(即不代表任何种类棋)，仅用于满足鼠标点击事件

    int num=-1;//用于判断是否有棋子发出信号,暂时没用到
};
#endif // MAINWINDOW_H
