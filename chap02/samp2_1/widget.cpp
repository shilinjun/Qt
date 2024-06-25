#include "widget.h"
#include "ui_widget.h"      //widget.ui对应的类定义文件

Widget::Widget(QWidget *parent) :   //构造函数头部:4~6行
    QWidget(parent),         //执行父类QWidget的构造函数
    ui(new Ui::Widget) //创建一个Ui::Widget类的对象ui。这个ui就是Widget的private部分定义的指针变量ui
{
    //构造实现
    ui->setupUi(this);  //这个函数实现窗口的生成与各种属性的设置、信号与槽的关联
}

Widget::~Widget()
{
    delete ui;  //删除new创建的指针ui
}
