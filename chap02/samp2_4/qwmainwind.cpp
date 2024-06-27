#include "qwmainwind.h"
#include "ui_qwmainwind.h"

QWMainWind::QWMainWind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWMainWind)
{
    ui->setupUi(this);
    iniUI();
    iniSignalSlots();
}

QWMainWind::~QWMainWind()
{
    delete ui;
}

void QWMainWind::iniUI()
{
    spinFontSize = new QSpinBox;//文字大小 SpinBox
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->txtEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);
    ui->mainToolBar->addWidget(new QLabel("字体大小"));
    ui->mainToolBar->addWidget(spinFontSize);//SpinBox添加到工具栏

    setCentralWidget(ui->txtEdit);
}

void QWMainWind::iniSignalSlots()
{
    //信号与槽的关联
    connect(spinFontSize,SIGNAL(valueChanged(int)),this,SLOT(on_spinFontSize_valueChanged(int)));
}

void QWMainWind::on_actBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->txtEdit->currentCharFormat();
    if (checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void QWMainWind::on_txtEdit_copyAvailable(bool b)
{
    //更新cut,copy,paste的enabled属性
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->txtEdit->canPaste());
}

void QWMainWind::on_txtEdit_selectionChanged()
{
    //更新粗体、斜体和下划线3种action的checked属性
    QTextCharFormat fmt;
    fmt=ui->txtEdit->currentCharFormat();
    //获取文字的格式
    ui->actBold->setChecked(fmt.font().bold()); //是否粗体
}

void QWMainWind::on_spinFontSize_valueChanged(int aFontSize)
{
    //改变字体大小的SpinBox
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize); //设置字体大小
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}
