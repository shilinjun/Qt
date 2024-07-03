#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnCel_clicked()    //计算
{
    int num=ui->spinBoxNum->value();
    float price=ui->dSpinBoxPrice->value();
    float total=num*price;
    ui->dSpinBoxTotal->setValue(total);
}

void Widget::on_btnDec_clicked()
{
    //读取十进制数，以其他进制显示
    int val=ui->spinBoxDec->value();
    ui->spinBoxBin->setValue(val);
    ui->spinBoxHex->setValue(val);
}

void Widget::on_btnBin_clicked()
{
    //读取二进制数，以其他进制显示
    int val=ui->spinBoxBin->value();
    ui->spinBoxDec->setValue(val);
    ui->spinBoxHex->setValue(val);
}

void Widget::on_btnHex_clicked()
{
    //读取十六进制数，以其他进制显示
    int val=ui->spinBoxHex->value();
    ui->spinBoxDec->setValue(val);
    ui->spinBoxBin->setValue(val);
}
