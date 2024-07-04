#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //先将底色画上
    on_hSliderColor_valueChanged(0);

    //将颜色条拉动和底色变化的处理函数连接
    QObject::connect(ui->hSliderRed,SIGNAL(valueChanged(int)),this,SLOT(on_hSliderColor_valueChanged(int)));
    QObject::connect(ui->hSliderGreen,SIGNAL(valueChanged(int)),this,SLOT(on_hSliderColor_valueChanged(int)));
    QObject::connect(ui->hSliderBlue,SIGNAL(valueChanged(int)),this,SLOT(on_hSliderColor_valueChanged(int)));
    QObject::connect(ui->hSliderAlpha,SIGNAL(valueChanged(int)),this,SLOT(on_hSliderColor_valueChanged(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_hSliderColor_valueChanged(int value)
{
    //拖动Red、Green、Blue 颜色滑动条时设置textEdit的底色
    Q_UNUSED(value);

    QColor color;
    int R=ui->hSliderRed->value();
    int G=ui->hSliderGreen->value();
    int B=ui->hSliderBlue->value();
    int alpha=ui->hSliderAlpha->value();

    color.setRgb(R,G,B,alpha); //使用QColor的setRgb()函数获得颜色
    QPalette pal=ui->textEdit->palette();
    pal.setColor(QPalette::Base,color); //设置底色
    ui->textEdit->setPalette(pal);
}
