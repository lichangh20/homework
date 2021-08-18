#ifndef MYCHESS_H
#define MYCHESS_H

#include <QWidget>
#include<QLabel>

namespace Ui {
class mychess;
}

class mychess : public QLabel
{
    Q_OBJECT

public:
    explicit mychess(QWidget *parent = nullptr);
    ~mychess();
    //用于标识该棋子属于哪种棋牌，不同的数字对应不同的图片(即种类),从mainwindow的numberlist传入
    //-1代表虚拟棋子，即不代表任何棋子
    //蓝方：
    //0,1,2分别代表军旗，司令，军长，各一个
    //3,4,5,6,7分别代表师长，旅长，团长，营长，炸弹，各两个
    //8,9,10，11分别代表连长，排长，工兵，地雷，各三个
    //红方：
    //12,13,14,分别代表军旗，司令，军长，各一个
    //15,16,17,18,19分别代表师长，旅长，团长，营长，炸弹，各两个
    //20,21,22,23分别代表连长，排长，工兵，地雷，各三个
    int kind=-1;

    int number=-1;//标识棋子顺序，用于接发信号(0-49)代表正常棋子

    //11,13,17,21,23,36,38,42,46,48处为行营，其余处为位置
    int position=-1;//表示棋子位置，用于判断其在地图上所处的位置(按顺序走下来0-59)


    //判断是否被点击过，初始为0，点击后变为1，且换图片
    bool check=false;

    //用于根据棋子的kind值传递相应图片
    void judge();

    //用于判断是否位于行营，是则为true，否则为false
    bool judgeposition();

    //判断棋盘上相应位置是否有棋子，有则为1，没有则为0
    bool exist=0;

protected:
    //重载鼠标按下事件
    void mousePressEvent(QMouseEvent *ev) override;


private:
    Ui::mychess *ui;

};

#endif // MYCHESS_H
