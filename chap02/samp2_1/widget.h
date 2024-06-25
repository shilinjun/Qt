#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {  //一个命名空间Ui，包含一个类Widget
class Widget;   //不是下面的Widget，而是ui_widget.h文件里定义的类，用于描述界面组件的。
}

class Widget : public QWidget   //创建的时候选择的窗体基类是QWidget
{
    Q_OBJECT    //使用Qt的信号与槽机制的类都必须加入的一个宏

public:
    explicit Widget(QWidget *parent = 0);   //构造函数
    ~Widget();  //析构函数

private:
    Ui::Widget *ui; //使用Ui::Widget定义的一个指针
};

#endif // WIDGET_H
