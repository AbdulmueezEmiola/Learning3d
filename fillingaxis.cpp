#include "fillingaxis.h"
#include <QBoxLayout>
FillingAxis::FillingAxis():
    QMainWindow ()
{
    QGridLayout *layout =new QGridLayout;
    label1 = new QLabel("XAxis");
    label2 = new QLabel("YAxis");
    xLineEdit1 = new QLineEdit;
    xLineEdit2 = new QLineEdit;
    xLineEdit3 = new QLineEdit;
    xLineEdit4 = new QLineEdit;
    xLineEdit5 = new QLineEdit;
    xLineEdit6 = new QLineEdit;
    xLineEdit7 = new QLineEdit;
    xLineEdit8 = new QLineEdit;
    xLineEdit9 = new QLineEdit;
    xLineEdit9 = new QLineEdit;
    xLineEdit10 = new QLineEdit;
    yLineEdit1 = new QLineEdit;
    yLineEdit2 = new QLineEdit;
    yLineEdit3 = new QLineEdit;
    yLineEdit4 = new QLineEdit;
    yLineEdit5 = new QLineEdit;
    yLineEdit6 = new QLineEdit;
    yLineEdit7 = new QLineEdit;
    yLineEdit8 = new QLineEdit;
    yLineEdit9 = new QLineEdit;
    yLineEdit9 = new QLineEdit;
    yLineEdit10 = new QLineEdit;
    layout->addWidget(label1,0,0);
    layout->addWidget(label2,0,1);
    layout->addWidget(xLineEdit1,1,0);
    layout->addWidget(xLineEdit2,2,0);
    layout->addWidget(xLineEdit3,3,0);
    layout->addWidget(xLineEdit4,4,0);
    layout->addWidget(xLineEdit5,5,0);
    layout->addWidget(xLineEdit6,6,0);
    layout->addWidget(xLineEdit7,7,0);
    layout->addWidget(xLineEdit8,8,0);
    layout->addWidget(xLineEdit9,9,0);
    layout->addWidget(yLineEdit10,10,1);
    layout->addWidget(yLineEdit1,1,1);
    layout->addWidget(yLineEdit2,2,1);
    layout->addWidget(yLineEdit3,3,1);
    layout->addWidget(yLineEdit4,4,1);
    layout->addWidget(yLineEdit5,5,1);
    layout->addWidget(yLineEdit6,6,1);
    layout->addWidget(yLineEdit7,7,1);
    layout->addWidget(yLineEdit8,8,1);
    layout->addWidget(yLineEdit9,9,1);
    layout->addWidget(yLineEdit10,10,1);
}
