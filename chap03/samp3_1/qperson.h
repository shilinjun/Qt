#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>

class QPerson : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author","Wang")
    Q_CLASSINFO("company","UPC")
    Q_CLASSINFO("version","1.0.0")
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged) //读属性age的值时调用age()，修改时调setAge()，属性发生变化时发送ageChanged信号
    Q_PROPERTY(QString name MEMBER m_name)  //将属性name和变量m_name关联起来
    Q_PROPERTY(int score MEMBER m_score)    //将属性score和变量m_score关联起来
private:
    int m_age = 10;
    int m_score = 79;
    QString m_name;
public:
    explicit QPerson(QString fName, QObject *parent = nullptr);
    int age();
    void setAge(int value);
    void incAge();
signals:
    void ageChanged(int value);
public slots:
};

#endif // QPERSON_H
