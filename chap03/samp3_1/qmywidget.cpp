#include "qmywidget.h"
#include "ui_qmywidget.h"

QmyWidget::QmyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QmyWidget)
{
    ui->setupUi(this);
    boy=new QPerson("王小明");
    boy->setProperty("score",95);
    boy->setProperty("age",11);
    boy->setProperty("sex","Boy");//动态属性
    connect(boy,&QPerson::ageChanged,this,&QmyWidget::on_ageChanged);   //函数指针的形式关联
    ui->spinBoxBoy->setValue(boy->age());   //将年龄填入框内显示

    girl=new QPerson("张小丽");
    girl->setProperty("score",81);
    girl->setProperty("age",20);
    girl->setProperty("sex","Girl");//动态属性
    connect(girl,&QPerson::ageChanged,this,&QmyWidget::on_ageChanged);  //函数指针的形式关联
    ui->spinBoxGirl->setValue(girl->age()); //将年龄填入框内显示

    ui->spinBoxBoy->setProperty("isBoy",true); //动态属性
    ui->spinBoxGirl->setProperty("isBoy",false);

    connect(ui->spinBoxGirl,SIGNAL(valueChanged(int)),this,SLOT(on_spin_valueChanged(int)));    //SIGNAL形式关联，因为为QSpinBox有两个valueChanged()信号
    connect(ui->spinBoxBoy,SIGNAL(valueChanged(int)),this,SLOT(on_spin_valueChanged(int)));
}

QmyWidget::~QmyWidget()
{
    delete ui;
    delete boy;
    delete girl;
}

void QmyWidget::on_ageChanged(int value)
{
    //响应QPerson的ageChanged()信号
    Q_UNUSED(value);
    QPerson *aPerson = qobject_cast<QPerson *>(sender()); //类型投射,指向发送者，也就是13或者20行的boy或者girl
    QString hisName=aPerson->property("name").toString(); //姓名
    QString hisSex=aPerson->property("sex").toString(); //动态属性
    int hisAge=aPerson->age();//通过接口函数获取年龄
    // int hisAge=aPerson->property("age").toInt();//也可以通过属性获得年龄
    ui->textEdit->appendPlainText(hisName+","+hisSex+QString::asprintf(",年龄=%d",hisAge));
}

void QmyWidget::on_spin_valueChanged(int arg1)
{
    //响应界面上spinBox的valueChanged(int)信号
    Q_UNUSED(arg1);
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(sender()); // //类型投射,指向发送者,也就是24或25行的spinBoxGirl或者spinBoxBoy
    if (spinBox->property("isBoy").toBool())
        boy->setAge(spinBox->value());
    else
        girl->setAge(spinBox->value());
}

void QmyWidget::on_btnClassInfo_clicked()
{
    //"类的元对象信息"按钮
    const QMetaObject *meta = boy->metaObject();    //获得boy的元对象，元对象类QMetaObject封装了访问类的元对象的各种接口函数
    ui->textEdit->clear();
    ui->textEdit->appendPlainText("==元对象信息==\n");
    ui->textEdit->appendPlainText(QString("类名称：%1\n").arg(meta->className()));

    ui->textEdit->appendPlainText("property");
    //propertyOffset:返回类的第一个属性的序号,第一个属性的序号不一定是0
    //propertyCount:返回类的属性个数。
    for (int i=meta->propertyOffset();i<meta->propertyCount();i++)
    {
        //返回序号为index的属性对象，返回值是QMetaProperty类型，它封装了对属性的更多特征查询功能，以及属性值的读写功能。
        QMetaProperty prop=meta->property(i);
        const char* propName=prop.name();
        QString propValue=boy->property(propName).toString();
        ui->textEdit->appendPlainText(QString("属性名称=%1，属性值=%2").arg(propName).arg(propValue));
    }

    ui->textEdit->appendPlainText("");
    ui->textEdit->appendPlainText("classInfo");

    //classInfoOffset:获取元对象的classinfo在内存中的位置
    //classInfoCount:元对象的classinfo个数
    for (int i=meta->classInfoOffset();i<meta->classInfoCount();++i)
    {
        //QMetaClassInfo类封装了类的classInfo的访问接口函数，只有name()和value()两个接口函数
        QMetaClassInfo classInfo=meta->classInfo(i);
        ui->textEdit->appendPlainText(QString("Name=%1; Value=%2").arg(classInfo.name()).arg(classInfo.value()));
    }
}

void QmyWidget::on_btnGirlInc_clicked()
{
    girl->incAge();
}

void QmyWidget::on_btnBoyInc_clicked()
{
    boy->incAge();
}

void QmyWidget::on_btnClear_clicked()
{
    ui->textEdit->clear();
}
