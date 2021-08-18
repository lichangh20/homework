#include "mychess.h"
#include "ui_mychess.h"
#include<QPainter>
#include<QMouseEvent>
#include<QPen>
#include<globalvariable.h>

mychess::mychess(QWidget *parent) :
    QLabel(parent),
    ui(new Ui::mychess)
{
    ui->setupUi(this);

    //将整个类作为棋子
    this->setFixedSize(83,40);

    //正常棋子初始为问号占位符
    this->setPixmap(QPixmap("://png/blank_unknown.png"));
    this->setScaledContents(true);
}

mychess::~mychess()
{
    delete ui;
}

void mychess::mousePressEvent(QMouseEvent *ev)
{
    //只有鼠标左键点击的时候才处理
    if(ev->button()==Qt::LeftButton)
    {
        //只有当前存在棋子时才会做出下面的判断
        if(exist)
        {
            //若此时尚未被点击过，则添加图片，根据随机数数值(0-25)进行添加
            if(!check)
            {
                //传递图片
                judge();

                //检查过棋子，改变bool值
                check=true;
            }
            //else if(check)这步存在许多bug，需要日后继续完善
            //举例：存在许多绿框，等等
            //另一问题：如果有个棋子类exist=0,则其他棋子无法过去
            else if(check)
            {

                //选中及之后操作
                //先判断是否已经选中其他元素
                //观察全局变量棋子是否已经被占位,没有则跳过该步，有则进入该步，并在完成后将全局变量重新初始化
                if(globalVariable::chsGlobal!=nullptr)
                {
                    //先不判断是否能行，先将移动操作做出来(即只要移动就必定可以成功版)
                    //更特殊情况：移动后，原先棋子位置为空
                    this->kind=globalVariable::chsGlobal->kind;
                    this->number=globalVariable::chsGlobal->number;
                    judge();


                    //全局棋子属性回到初始阶段
                    globalVariable::chsGlobal=nullptr;
                }



                //确定没有选中其他元素后，再选中该元素
                else if(globalVariable::chsGlobal==nullptr)
                {
                    //加边框
                    this->setStyleSheet("QLabel{"
                                 "border:3px solid green;}");
                    //将全局变量赋值为棋子的属性
                    globalVariable::chsGlobal=new mychess;
                    globalVariable::chsGlobal->kind=this->kind;
                    globalVariable::chsGlobal->number=this->number;
                    globalVariable::chsGlobal->position=this->position;

                    //更新该棋子状态(假设可以移动)
                    this->exist=0;
                    judge();

                }
            }
        }

        //棋子不存在时单独判断
        else if(!exist)
        {
            //此时棋子类只能后手选择
            if(globalVariable::chsGlobal!=nullptr)
            {
                this->kind=globalVariable::chsGlobal->kind;
                this->number=globalVariable::chsGlobal->number;
                exist=true;
                judge();

                //全局棋子属性回到初始阶段
                globalVariable::chsGlobal=nullptr;
            }
        }
    }
    //否则不做处理，交给父类
    else
    {
        ev->ignore();
    }
}

void mychess::judge()
{
    //棋子存在时传入相应棋子的图片
    if(exist)
    {
    //蓝方：
    //0,1,2分别代表军旗，司令，军长，各一个
    if(kind==0)
        this->setPixmap(QPixmap("://png/blue_flag.png"));

    else if(kind==1)
        this->setPixmap(QPixmap("://png/blue_siling.png"));

    else if(kind==2)
        this->setPixmap(QPixmap("://png/blue_junz.png"));

    //3,4,5,6,7分别代表师长，旅长，团长，营长，炸弹，各两个
    else if(kind==3)
        this->setPixmap(QPixmap("://png/blue_shiz.png"));

    else if(kind==4)
        this->setPixmap(QPixmap("://png/blue_lvz.png"));

    else if(kind==5)
        this->setPixmap(QPixmap("://png/blue_tuanz.png"));

    else if(kind==6)
        this->setPixmap(QPixmap("://png/blue_yingz.png"));

    else if(kind==7)
        this->setPixmap(QPixmap("://png/blue_bomb.png"));

    //8,9,10，11分别代表连长，排长，工兵，地雷，各三个
    else if(kind==8)
        this->setPixmap(QPixmap("://png/blue_lianz.png"));

    else if(kind==9)
        this->setPixmap(QPixmap("://png/blue_paiz.png"));

    else if(kind==10)
        this->setPixmap(QPixmap("://png/blue_soldier.png"));

    else if(kind==11)
        this->setPixmap(QPixmap("://png/blue_dilei.png"));

    //红方：
    //12,13,14,分别代表军旗，司令，军长，各一个
    else if(kind==12)
        this->setPixmap(QPixmap("://png/red_flag.png"));

    else if(kind==13)
        this->setPixmap(QPixmap("://png/red_siling.png"));

    else if(kind==14)
        this->setPixmap(QPixmap("://png/red_junz.png"));

    //15,16,17,18,19分别代表师长，旅长，团长，营长，炸弹，各两个
    else if(kind==15)
        this->setPixmap(QPixmap("://png/red_shiz.png"));

    else if(kind==16)
        this->setPixmap(QPixmap("://png/red_lvz.png"));

    else if(kind==17)
        this->setPixmap(QPixmap("://png/red_tuanz.png"));

    else if(kind==18)
        this->setPixmap(QPixmap("://png/red_yingz.png"));

    else if(kind==19)
        this->setPixmap(QPixmap("://png/red_bomb.png"));

    //20,21,22,23分别代表连长，排长，工兵，地雷，各三个
    else if(kind==20)
        this->setPixmap(QPixmap("://png/red_lianz.png"));

    else if(kind==21)
        this->setPixmap(QPixmap("://png/red_paiz.png"));

    else if(kind==22)
        this->setPixmap(QPixmap("://png/red_soldier.png"));

    else if(kind==23)
        this->setPixmap(QPixmap("://png/red_dilei.png"));
    }

    //棋子不存在时，根据它在棋盘上所处位置传入空位置/空行营图片
    else if(!exist)
    {
        //传入空行营图片
        if(judgeposition())
           this->setPixmap(QPixmap("://png/blank_xingy.png"));

        //传入空位置图片
        else if(!judgeposition())
            this->setPixmap(QPixmap("://png/blank_soldier.png"));

    }

    //最后统一适应label标签大小
    this->setScaledContents(true);
}

bool mychess::judgeposition()
{
    if(position==11)
        return true;
    else if(position==13)
        return true;
    else if(position==17)
        return true;
    else if(position==21)
        return true;
    else if(position==23)
        return true;
    else if(position==36)
        return true;
    else if(position==38)
        return true;
    else if(position==42)
        return true;
    else if(position==46)
        return true;
    else if(position==48)
        return true;
    return false;
}
