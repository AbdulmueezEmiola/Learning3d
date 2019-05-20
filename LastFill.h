#ifndef FORM_H
#define FORM_H
#include <QLabel>
#include <QWidget>
#include <vector>
#include "form.h"
#include <QLineEdit>
#include "mainwindow.h"
using namespace std;
class LastFill : public QWidget
{
    Q_OBJECT

public:
    explicit LastFill(QWidget *parent = nullptr);
    QVector<QString>vector1;
    QVector<QString>vector2;
    QString string1;
    QString string2;
    QString string3;
private:
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *label6;
    QLabel *label7;
    QLabel *label8;
    QLabel *label9;
    QLabel *label10;
    QLabel *minLabel;
    QLabel *maxLabel;
    QLineEdit *minLineEdit;
    QLineEdit *maxLineEdit;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QLineEdit *lineEdit4;
    QLineEdit *lineEdit5;
    QLineEdit *lineEdit6;
    QLineEdit *lineEdit7;
    QLineEdit *lineEdit8;
    QLineEdit *lineEdit9;
    QLineEdit *lineEdit10;
    QVector<double>vectorX1;
    QVector<double>vectorX2;
    QVector<double>vectorX3;
    QVector<double>vectorX4;
    QVector<double>vectorX5;
    QVector<double>vectorX6;
    QVector<double>vectorX7;
    QVector<double>vectorX8;
    QVector<double>vectorX9;
    QVector<double>vectorX10;
    QVector<double> getVector(QLineEdit *);
    QPushButton *nextButton;
    void fillVector();
    void openNext();
    double ** getArray();
};

#endif // FORM_H
