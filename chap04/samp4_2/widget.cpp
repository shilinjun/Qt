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

void Widget::on_btnAppend_clicked() //在字符串的后面添加字符串
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString str2=ui->lineEditStr2->text();  //读取str2

    str1.append(str2);  //str1 = str1 + str2
    ui->lineEditResult->setText(str1);  //将结果填到结果栏中
}

void Widget::on_btnPrepend_clicked()    //在字符串前面添加字符串
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString str2=ui->lineEditStr2->text();  //读取str2

    str1.prepend(str2);  //str1 = str1 + str2
    ui->lineEditResult->setText(str1);  //将结果填到结果栏中
}

void Widget::on_btnToUpper_clicked()    //将字符串内的字母都变成大写
{
    QString str1=ui->lineEditStr1->text(),str2;  //读取str1,准备str2接收转化后的结果

    str2 = str1.toUpper();
    ui->lineEditResult->setText(str2);  //将结果填到结果栏中
}

void Widget::on_btnToLower_clicked()
{
    QString str1=ui->lineEditStr1->text(),str2;  //读取str1,准备str2接收转化后的结果

    str2 = str1.toLower();
    ui->lineEditResult->setText(str2);  //将结果填到结果栏中
}

void Widget::on_btnLeft_clicked()   //返回最左边的N个字符，此处我们把str2用于输入N
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString str2=ui->lineEditStr2->text();  //读取str2
    QString result;

    int num = str2.toInt();
    if(num != 0)
    {
        result = str1.left(num);
    }
    else
    {
        result.sprintf("%s","str2 must be number!");
    }
    ui->lineEditResult->setText(result);  //将结果填到结果栏中
}

void Widget::on_btnRight_clicked()  //返回最右边的N个字符，此处我们把str2用于输入N
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString str2=ui->lineEditStr2->text();  //读取str2
    QString result;

    int num = str2.toInt();
    if(num != 0)
    {
        result = str1.right(num);
    }
    else
    {
        result.sprintf("%s","str2 must be number!");
    }
    ui->lineEditResult->setText(result);  //将结果填到结果栏中
}

void Widget::on_btnSection_clicked()    //分割字符串
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString str2=ui->lineEditStr2->text();  //读取str2
    QString result;

    result = str1.section(str2.at(0),1,2);  //从str1中，以str2的第一个字符x为关键字，取第1个x到第2个x之间的字符串
    ui->lineEditResult->setText(result);  //将结果填到结果栏中
}

void Widget::on_btnSimolified_clicked() //去掉首尾的空格，中间连续的空格也用一个空格替换
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString result;

    result = str1.simplified();
    ui->lineEditResult->setText(result);  //将结果填到结果栏中
}

void Widget::on_btnTrimmed_clicked()    //仅去掉首尾的空格
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString result;

    result = str1.trimmed();
    ui->lineEditResult->setText(result);  //将结果填到结果栏中
}

void Widget::on_btnCount_clicked()  //计算字符串的字符个数，汉字也算一个字符
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString result;

    int N = str1.count();
    //int N = str1.size();
    //int N = str1.length();
    result.sprintf("%d",N);
    ui->lineEditResult->setText(result);  //将结果填到结果栏中
}

void Widget::on_btnSize_clicked()    //计算字符串的字符个数，汉字也算一个字符
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString result;

    //int N = str1.count();
    int N = str1.size();
    //int N = str1.length();
    result.sprintf("%d",N);
    ui->lineEditResult->setText(result);  //将结果填到结果栏中
}

void Widget::on_btnIndexOf_clicked()    //查找str2在str1中第一次出现的位置
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString str2=ui->lineEditStr2->text();  //读取str2
    QString result;

    int N = str1.indexOf(str2);
    result.sprintf("%d",N);
    ui->lineEditResult->setText(result);  //将结果填到结果栏中
}

void Widget::on_btnLastIndexOf_clicked()    //查找str2在str1中最后一次出现的位置
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString str2=ui->lineEditStr2->text();  //读取str2
    QString result;

    int N = str1.lastIndexOf(str2);
    result.sprintf("%d",N);
    ui->lineEditResult->setText(result);  //将结果填到结果栏中
}

void Widget::on_btnEndsWith_clicked()   //判断str1是否以str2结尾
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString str2=ui->lineEditStr2->text();  //读取str2
    QString result;

    if(str1.endsWith(str2,Qt::CaseSensitive))   //区分大小写
    {
        result.sprintf("%s","true");
    }
    else
    {
        result.sprintf("%s","false");
    }
    ui->lineEditResult->setText(result);  //将结果填到结果栏中
}

void Widget::on_btnStartsWith_clicked() //判断str1是否以str2开始
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString str2=ui->lineEditStr2->text();  //读取str2
    QString result;

    if(str1.endsWith(str2,Qt::CaseSensitive))   //区分大小写
    {
        result.sprintf("%s","true");
    }
    else
    {
        result.sprintf("%s","false");
    }
    ui->lineEditResult->setText(result);  //将结果填到结果栏中
}

void Widget::on_btnContains_clicked()   //判断字符串内是否包含某个字符串
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString str2=ui->lineEditStr2->text();  //读取str2
    QString result;

    if(str1.contains(str2, Qt::CaseSensitive))   //区分大小写
    {
        result.sprintf("%s","str1 contains str2");
        ui->checkBoxContains->setCheckState(Qt::Checked);
    }
    else
    {
        result.sprintf("%s","str1 does not contain str2");
        ui->checkBoxContains->setCheckState(Qt::Unchecked);
    }
    ui->lineEditResult->setText(result);  //将结果填到结果栏中
}

void Widget::on_btnIsNull_clicked() //判断字符串是否为空，只有'\0'的空字符，返回false,只有未赋值的字符串，才返回true
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString result;

    result.sprintf("%s",str1.isNull()?"true":"false");
    ui->lineEditResult->setText(result);  //将结果填到结果栏中
}

void Widget::on_btnIsEmpty_clicked()    //判断字符串是否为空，只有'\0'的空字符，也返回true
{
    QString str1=ui->lineEditStr1->text();  //读取str1
    QString result;

    result.sprintf("%s",str1.isEmpty()?"true":"false");
    ui->lineEditResult->setText(result);  //将结果填到结果栏中
}
