#ifndef FORM_H
#define FORM_H
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "fillingaxis.h"
#include <QWidget>
#include "mainwindow.h"
class Opening : public QWidget
{
    Q_OBJECT

public:
    explicit Opening(QWidget *parent = nullptr);
private:
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QPushButton *button1;
    void onButtonClick();

};

#endif // FORM_H
