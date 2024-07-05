#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    fTimer=new QTimer(this);
    fTimer->stop();     //默认处于停止状态
    ui->btnStop->setEnabled(false); //停止按钮默认置灰
    fTimer->setInterval(1000);//设置定时周期, 单位：毫秒

    connect(fTimer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_timer_timeout()
{
    //定时器中断响应
    QTime curTime=QTime::currentTime();     //获取当前时间
    ui->lcdHour->display(curTime.hour());   //显示小时
    ui->lcdMin->display(curTime.minute());  //显示分钟
    ui->lcdSec->display(curTime.second());  //显示秒
    int va=ui->progressBar->value();
    va++;
    if (va>100)
        va=0;
    ui->progressBar->setValue(va);
}

void Widget::on_btnGetDateTime_clicked()
{
    //获取当前日期时间，为三个专用编辑器设置日期时间数据，并转换为字符串
    QDateTime curDateTime=QDateTime::currentDateTime();
    ui->timeEdit->setTime(curDateTime.time());
    ui->lineEditTime->setText(curDateTime.toString("hh:mm:ss"));
    ui->dateEdit->setDate(curDateTime.date());
    ui->lineEditDate->setText(curDateTime.toString("yyyy-MM-dd"));
    ui->dateTimeEdit->setDateTime(curDateTime);
    ui->lineEditDateTime->setText(curDateTime.toString("yyyy-MM-dd hh:mm:ss"));
}

void Widget::on_btnSetDateTime_clicked()
{
    //字符串转换为 QDateTime
    QString str = ui->lineEditDateTime->text();
    str = str.trimmed();    //去掉字符串首尾的空格
    if(!str.isEmpty())
    {
       // qDebug()<<"str is:"<<str;
        QDateTime dateTime = QDateTime::fromString(str,"yyyy-MM-dd hh:mm:ss");
        ui->dateTimeEdit->setDateTime(dateTime);
    }
}

void Widget::on_btnSetTime_clicked()
{
    //字符串转换为 QDateTime
    QString str = ui->lineEditTime->text();
    str = str.trimmed();    //去掉字符串首尾的空格
    if(!str.isEmpty())
    {
        QDateTime dateTime = QDateTime::fromString(str,"hh:mm:ss");
        ui->timeEdit->setDateTime(dateTime);
    }
}

void Widget::on_btnSetDate_clicked()
{
    //字符串转换为 QDateTime
    QString str = ui->lineEditDate->text();
    str = str.trimmed();    //去掉字符串首尾的空格
    if(!str.isEmpty())
    {
        QDateTime dateTime = QDateTime::fromString(str,"yyyy-MM-dd");
        ui->dateEdit->setDateTime(dateTime);
    }
}

void Widget::on_calendarWidget_selectionChanged()
{
    //在日历上选择日期
    QDate dt=ui->calendarWidget->selectedDate();
    QString str=dt.toString("yyyy年M月d日");
    ui->lineEditSel->setText(str);
}

void Widget::on_btnStart_clicked()
{
    fTimer->start();//定时器开始工作
    fTimeCounter.start();//计时器开始工作,将当前时间作为计时器的开始时间
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
    ui->btnSetMs->setEnabled(false);
}

void Widget::on_btnStop_clicked()
{
    fTimer->stop();//定时器结束
    int tmMsec = fTimeCounter.elapsed();//返回自上次调用start（）或restart（）以来经过的毫秒数。
    int ms = tmMsec%1000;
    int sec = tmMsec/1000;

    QString str=QString::asprintf("流逝时间：%d 秒，%d 毫秒",sec,ms);
    ui->labelOverTime->setText(str);
    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);
    ui->btnSetMs->setEnabled(true);
}

void Widget::on_btnSetMs_clicked()
{
    int num = ui->spinBoxMs->value();
    fTimer->setInterval(num);//设置定时周期, 单位：毫秒
}
