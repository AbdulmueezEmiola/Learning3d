#include "LastFill.h"
#include "ui_form.h"
#include <QBoxLayout>
#include <QVariant>
#include "string.h"
#include "finaldisplay.h"
LastFill::LastFill(QWidget *parent) :
    QWidget(parent)
{
    minLabel = new QLabel("Minimum Value");
    maxLabel = new QLabel("Maximum Value");
    minLineEdit = new QLineEdit;
    maxLineEdit = new QLineEdit;
    QHBoxLayout *layoutRange = new QHBoxLayout;
    layoutRange->addWidget(minLabel);
    layoutRange->addWidget(minLineEdit);
    layoutRange->addStretch();
    layoutRange->addWidget(maxLabel);
    layoutRange->addWidget(maxLineEdit);
    QGridLayout *layout;
    label1 = new QLabel("Values X1");
    label2 = new QLabel("Values X2");
    label3 = new QLabel("Values X3");
    label4 = new QLabel("Values X4");
    label5 = new QLabel("Values X5");
    label6 = new QLabel("Values X6");
    label7 = new QLabel("Values X7");
    label8 = new QLabel("Values X8");
    label9 = new QLabel("Values X9");
    label10 = new QLabel("Values X10");
    lineEdit1 = new QLineEdit;
    lineEdit1->showMaximized();
    lineEdit2 = new QLineEdit;
    lineEdit2->showMaximized();
    lineEdit3 = new QLineEdit;
    lineEdit3->showMaximized();
    lineEdit4 = new QLineEdit;
    lineEdit4->showMaximized();
    lineEdit5 = new QLineEdit;
    lineEdit5->showMaximized();
    lineEdit6 = new QLineEdit;
    lineEdit6->showMaximized();
    lineEdit7 = new QLineEdit;
    lineEdit7->showMaximized();
    lineEdit8 = new QLineEdit;
    lineEdit8->showMaximized();
    lineEdit9 = new QLineEdit;
    lineEdit9->showMaximized();
    lineEdit10 = new QLineEdit;
    lineEdit10->showMaximized();
    layout = new QGridLayout;
    layout->addWidget(label1,0,0);
    layout->addWidget(lineEdit1,0,1);
    layout->addWidget(label2,1,0);
    layout->addWidget(lineEdit2,1,1);
    layout->addWidget(label3,2,0);
    layout->addWidget(lineEdit3,2,1);
    layout->addWidget(label4,3,0);
    layout->addWidget(lineEdit4,3,1);
    layout->addWidget(label5,4,0);
    layout->addWidget(lineEdit5,4,1);
    layout->addWidget(label6,5,0);
    layout->addWidget(lineEdit6,5,1);
    layout->addWidget(label7,6,0);
    layout->addWidget(lineEdit7,6,1);
    layout->addWidget(label8,7,0);
    layout->addWidget(lineEdit8,7,1);
    layout->addWidget(label9,8,0);
    layout->addWidget(lineEdit9,8,1);
    layout->addWidget(label10,9,0);
    layout->addWidget(lineEdit10,9,1);
    nextButton = new QPushButton("Next");
    connect(nextButton, &QPushButton::clicked, this, &LastFill::openNext);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutRange);
    mainLayout->addLayout(layout);
    mainLayout->addWidget(nextButton);
    setLayout(mainLayout);
}
QVector<double> LastFill::getVector(QLineEdit* lineEdit){
    QString str1 = lineEdit->text();
    QVector<double> vector;
    string str = str1.toStdString();
    int n = str.length();
    char *chars;
    chars = new char[n];
    strcpy(chars,str.c_str());
    char *pch;
    pch = strtok(chars,",; ");
    while(pch!=nullptr){
        double ent = atof(pch);
        vector.push_back(ent);
        pch = strtok(nullptr,",;");
    }
    return vector;
}
void LastFill::fillVector(){
    vectorX1 = getVector(lineEdit1);
    vectorX2 = getVector(lineEdit2);
    vectorX3 = getVector(lineEdit3);
    vectorX4 = getVector(lineEdit4);
    vectorX5 = getVector(lineEdit5);
    vectorX6 = getVector(lineEdit6);
    vectorX7 = getVector(lineEdit7);
    vectorX8 = getVector(lineEdit8);
    vectorX9 = getVector(lineEdit9);
    vectorX10 = getVector(lineEdit10);
}
double** LastFill::getArray(){
    vector<double> stdVector1 = vectorX1.toStdVector();
    vector<double> stdVector2 = vectorX1.toStdVector();
    vector<double> stdVector3 = vectorX1.toStdVector();
    vector<double> stdVector4 = vectorX1.toStdVector();
    vector<double> stdVector5 = vectorX1.toStdVector();
    vector<double> stdVector6 = vectorX1.toStdVector();
    vector<double> stdVector7 = vectorX1.toStdVector();
    vector<double> stdVector8 = vectorX1.toStdVector();
    vector<double> stdVector9 = vectorX1.toStdVector();
    vector<double> stdVector10 = vectorX1.toStdVector();
    double arrays [10][12];
    for(int i =0;i<12;i++){
        if(!stdVector1.empty()){
            arrays[1][i]=stdVector1[i];
        }
    }
    for(int i =0;i<12;i++){
        if(!stdVector2.empty()){
            arrays[2][i]=stdVector2[i];
        }
    }
    for(int i =0;i<12;i++){
        if(!stdVector3.empty()){
            arrays[3][i]=stdVector3[i];
        }
    }
    for(int i =0;i<12;i++){
        if(!stdVector4.empty()){
            arrays[4][i]=stdVector4[i];
        }
    }
    for(int i =0;i<12;i++){
        if(!stdVector5.empty()){
            arrays[5][i]=stdVector5[i];
        }
    }
    for(int i =0;i<12;i++){
        if(!stdVector6.empty()){
            arrays[6][i]=stdVector6[i];
        }
    }
    for(int i =0;i<12;i++){
        if(!stdVector7.empty()){
            arrays[7][i]=stdVector7[i];
        }
    }
    for(int i =0;i<12;i++){
        if(!stdVector8.empty()){
            arrays[8][i]=stdVector8[i];
        }
    }
    for(int i =0;i<12;i++){
        if(!stdVector9.empty()){
            arrays[9][i]=stdVector1[9];
        }
    }
    for(int i =0;i<12;i++){
        if(!stdVector1.empty()){
            arrays[10][i]=stdVector1[10];
        }
    }
}
void LastFill::openNext(){
    FinalDisplay *mainWindow = new FinalDisplay;
    mainWindow->xName=string1;
    mainWindow->yName = string2;
    mainWindow->zName = string3;
    mainWindow->minValue = minLineEdit->text().toDouble();
    mainWindow->maxValue = maxLineEdit->text().toDouble();
    mainWindow->vectX = vector1;
    mainWindow->vectZ = vector2;
    mainWindow->array = getArray();
    deleteLater();
    mainWindow->show();
}
