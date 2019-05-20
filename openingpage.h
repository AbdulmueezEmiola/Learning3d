#ifndef OPENINGPAGE_H
#define OPENINGPAGE_H
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "fillingaxis.h"
#include <QDialog>
class OpeningPage:public QDialog
{
    Q_OBJECT
public:
    OpeningPage();
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

#endif // OPENINGPAGE_H
