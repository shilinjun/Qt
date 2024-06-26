#include "qwdialog.h"
#include "ui_qwdialog.h"

QWDialog::QWDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialog)
{
    ui->setupUi(this);
    connect(ui->rBtnBlue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->rBtnRed,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->rBtnBlack,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
}

QWDialog::~QWDialog()
{
    delete ui;
}

void QWDialog::on_checkBoxUnder_clicked(bool checked)
{
    QFont font=ui->textEdit->font();
    font.setUnderline(checked);
    ui->textEdit->setFont(font);
}

void QWDialog::on_checkBoxItalic_clicked(bool checked)
{
    QFont font=ui->textEdit->font();
    font.setItalic(checked);
    ui->textEdit->setFont(font);
}

void QWDialog::on_checkBoxBold_clicked(bool checked)
{
    QFont font=ui->textEdit->font();
    font.setBold(checked);
    ui->textEdit->setFont(font);
}

void QWDialog::setTextFontColor()
{
    QPalette plet=ui->textEdit->palette();
    if (ui->rBtnBlue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    else if (ui->rBtnRed->isChecked())
        plet.setColor(QPalette::Text,Qt::red);
    else if (ui->rBtnBlack->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    else
        plet.setColor(QPalette::Text,Qt::black);
    ui->textEdit->setPalette(plet);
}

