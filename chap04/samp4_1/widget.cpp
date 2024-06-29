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

void Widget::on_btnCal_clicked()
{
    QString str=ui->editNum->text();//读取"数量"
    int num=str.toInt();
    str=ui->editPrice->text();//读取"单价"
    float price=str.toFloat();
    float total=num*price;
    //str=QString::number(total,'f',2);
    //str=QString::asprintf("%.2f",total);
    //str=str.setNum(total,'f',2);
    str=str.sprintf("%.2f",total);  //上面3行是另外3种实现方式
    ui->editTotal->setText(str);
}

void Widget::on_btnDec_clicked()
{
    //读取十进制数，转换为其他进制
    QString str=ui->editDec->text();//读取十进制框内的数值
    int val=str.toInt();//缺省为十进制

    // str=QString::number(val,16);// 转换为十六进制的字符串
    str=str.setNum(val,16);//十六进制
    str=str.toUpper();
    ui->editHex->setText(str);

    // str=QString::number(val,2);
    str=str.setNum(val,2); //二进制
    ui->editBin->setText(str);
}

void Widget::on_btnBin_clicked()
{
    //读取二进制数，转换为其他进制的数
    QString str=ui->editBin->text(); //读取二进制字符串

    //toInt()声明 int toInt(bool *ok = Q_NULLPTR, int base =10) const
    bool ok;
    int val=str.toInt(&ok,2);//以二进制数读入
    str=QString::number(val,10);//数字显示为十进制字符串
    ui->editDec->setText(str);

    str=str.setNum(val,16);//显示为十六进制
    str=str.toUpper();
    ui->editHex->setText(str);
}

void Widget::on_btnHex_clicked()
{
    //读取十六进制数，转换为其他进制的数
    QString str=ui->editHex->text(); //读取16进制字符串

    bool ok;
    int val=str.toInt(&ok,16);//以16进制数读入
    str=QString::number(val,10);//数字显示为十进制字符串
    ui->editDec->setText(str);

    str=str.setNum(val,2);//显示为2进制
    ui->editBin->setText(str);
}
