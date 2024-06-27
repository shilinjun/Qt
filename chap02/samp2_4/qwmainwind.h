#ifndef QWMAINWIND_H
#define QWMAINWIND_H

#include <QMainWindow>
#include <QSpinBox>
#include <QLabel>
#include <QTextCharFormat>

namespace Ui {
class QWMainWind;
}

class QWMainWind : public QMainWindow
{
    Q_OBJECT

public:
    explicit QWMainWind(QWidget *parent = 0);
    ~QWMainWind();

private slots:
    void on_actBold_toggled(bool arg1);

    void on_actBold_triggered(bool checked);

    void on_txtEdit_copyAvailable(bool b);

    void on_txtEdit_selectionChanged();

private:
    Ui::QWMainWind *ui;

    QSpinBox *spinFontSize;// 字体大小spinBox
    void iniUI(); //代码实现的UI初始化
    void iniSignalSlots(); //关联信号与槽
private slots:
    void on_spinFontSize_valueChanged(int aFontSize);
};

#endif // QWMAINWIND_H
