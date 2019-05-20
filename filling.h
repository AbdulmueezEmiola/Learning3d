#ifndef FILLING_H
#define FILLING_H
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include "LastFill.h"
#include <string>
#include <QLabel>
class Filling : public QWidget
{
    Q_OBJECT

public:
    explicit Filling(QWidget *parent = nullptr);
    QLineEdit *xLineEdit1;
    QLineEdit *xLineEdit2;
    QLineEdit *xLineEdit3;
    QLineEdit *xLineEdit4;
    QLineEdit *xLineEdit5;
    QLineEdit *xLineEdit6;
    QLineEdit *xLineEdit7;
    QLineEdit *xLineEdit8;
    QLineEdit *xLineEdit9;
    QLineEdit *xLineEdit10;
    QLineEdit *yLineEdit1;
    QLineEdit *yLineEdit2;
    QLineEdit *yLineEdit3;
    QLineEdit *yLineEdit4;
    QLineEdit *yLineEdit5;
    QLineEdit *yLineEdit6;
    QLineEdit *yLineEdit7;
    QLineEdit *yLineEdit8;
    QLineEdit *yLineEdit9;
    QLineEdit *yLineEdit10;
    QLineEdit *yLineEdit11;
    QLineEdit *yLineEdit12;
    QString string1;
    QString string2;
    QString string3;
private:
    QPushButton *nextButton;
    QLabel *label1;
    QLabel *label2;
    QVector<QString>vector1;
    QVector<QString>vector2;
    void openNext();
    void fillX();
    void fillY();
};

#endif // FILLING_H
