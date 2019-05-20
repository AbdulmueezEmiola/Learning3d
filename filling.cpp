#include "filling.h"
#include "ui_filling.h"
#include <QBoxLayout>
#include <vector>
Filling::Filling(QWidget *parent) :
    QWidget(parent)
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
    yLineEdit11 = new QLineEdit;
    yLineEdit12 = new QLineEdit;
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
    layout->addWidget(xLineEdit10,10,0);
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
    layout->addWidget(yLineEdit11,11,1);
    layout->addWidget(yLineEdit12,12,1);
    nextButton = new QPushButton("Next");
    layout->addWidget(nextButton,13,1);
    connect(nextButton,&QPushButton::clicked,this,&Filling::openNext);
    setLayout(layout);

}
void Filling::openNext(){
    LastFill *fill;
    fill = new LastFill;
    fill->vector1 = vector1;
    fill->vector2 = vector2;
    fill->string1 = string1;
    fill->string2 = string2;
    fill->string3 = string3;
    deleteLater();
    fill->show();
}
void Filling::fillX(){
    if(!xLineEdit1->text().isEmpty()){
        vector1.push_back(xLineEdit1->text());
    }
    if(!xLineEdit2->text().isEmpty()){
        vector1.push_back(xLineEdit2->text());
    }
    if(!xLineEdit3->text().isEmpty()){
        vector1.push_back(xLineEdit3->text());
    }
    if(!xLineEdit4->text().isEmpty()){
        vector1.push_back(xLineEdit4->text());
    }
    if(!xLineEdit4->text().isEmpty()){
        vector1.push_back(xLineEdit4->text());
    }
    if(!xLineEdit5->text().isEmpty()){
        vector1.push_back(xLineEdit5->text());
    }
    if(!xLineEdit6->text().isEmpty()){
        vector1.push_back(xLineEdit6->text());
    }
    if(!xLineEdit7->text().isEmpty()){
        vector1.push_back(xLineEdit7->text());
    }
    if(!xLineEdit8->text().isEmpty()){
        vector1.push_back(xLineEdit8->text());
    }
    if(!xLineEdit9->text().isEmpty()){
        vector1.push_back(xLineEdit9->text());
    }
    if(!xLineEdit10->text().isEmpty()){
        vector1.push_back(xLineEdit10->text());
    }
}
void Filling::fillY(){
    if(!yLineEdit1->text().isEmpty()){
        vector2.push_back(yLineEdit1->text());
    }
    if(!yLineEdit2->text().isEmpty()){
        vector2.push_back(yLineEdit2->text());
    }
    if(!yLineEdit3->text().isEmpty()){
        vector2.push_back(yLineEdit3->text());
    }
    if(!yLineEdit4->text().isEmpty()){
        vector2.push_back(yLineEdit4->text());
    }
    if(!yLineEdit5->text().isEmpty()){
        vector2.push_back(yLineEdit5->text());
    }
    if(!yLineEdit6->text().isEmpty()){
        vector2.push_back(yLineEdit6->text());
    }
    if(!yLineEdit7->text().isEmpty()){
        vector2.push_back(yLineEdit7->text());
    }
    if(!yLineEdit8->text().isEmpty()){
        vector2.push_back(yLineEdit8->text());
    }
    if(!yLineEdit9->text().isEmpty()){
        vector2.push_back(yLineEdit9->text());
    }
    if(!yLineEdit10->text().isEmpty()){
        vector2.push_back(yLineEdit10->text());
    }
    if(!yLineEdit11->text().isEmpty()){
        vector2.push_back(yLineEdit11->text());
    }
    if(!yLineEdit12->text().isEmpty()){
       vector2.push_back(yLineEdit12->text());
    }
}
