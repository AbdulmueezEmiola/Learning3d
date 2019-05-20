#include "Opening.h"
#include "filling.h"
#include "ui_form.h"
#include <QBoxLayout>
Opening::Opening(QWidget *parent) :
    QWidget(parent)
{
    label1 = new QLabel("xAxis");
    label2 = new QLabel("zAxis");
    label3 = new QLabel("yAxis");
    label4 = new QLabel("Name");
    lineEdit1 = new QLineEdit;
    lineEdit1->setText("XAxis");
    lineEdit2 = new QLineEdit;
    lineEdit2->setText("YAxis");
    lineEdit3 = new QLineEdit;
    lineEdit3->setText("ZAxis");
    QGridLayout *layout1 = new QGridLayout;
    layout1->addWidget(label4,0,1);
    layout1->addWidget(label1,1,0);
    layout1->addWidget(label3,2,0);
    layout1->addWidget(label2,3,0);
    layout1->addWidget(lineEdit1,1,1);
    layout1->addWidget(lineEdit2,2,1);
    layout1->addWidget(lineEdit3,3,1);
    button1 = new QPushButton("Next");
    layout1->addWidget(button1,4,2);
    connect(button1,&QPushButton::clicked,this,&Opening::onButtonClick);
    setLayout(layout1);
}
void Opening::onButtonClick(){
    Filling *filler;
    filler = new Filling();
    filler->string1 = lineEdit1->text();
    filler->string2 = lineEdit2->text();
    filler->string3 = lineEdit3->text();
    deleteLater();
    filler->show();
}
