#ifndef FORM_H
#define FORM_H

#include <QWidget>

#include "graphmodofoer.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QSlider>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtGui/QScreen>
#include <QtGui/QFontDatabase>

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    double minValue;
    double maxValue;
    QVector<QString>vectZ;
    QVector<QString>vectX;
    QString yName;
    QString xName;
    QString zName;
    double**array;

private:
    Q3DBars *widgetGraph;
    QWidget *containers;
    QSize screenSize;
    QWidget *widget;
    QComboBox *themeList;
    QPushButton *labelButton;
    QCheckBox *smoothCheckBox;
    QComboBox *barStyleList;
    QPushButton *cameraButton;
    QPushButton *zoomToSelectedButton;
    QComboBox *selectionModeList;
    QCheckBox *backgroundCheckBox;
    QCheckBox *gridCheckBox;
    QCheckBox *seriesCheckBox;
    QCheckBox *reverseValueAxisCheckBox;
    QCheckBox *reflectionCheckBox;
    QSlider *rotationSliderX;
    QSlider *fontSizeSlider;
    QFontComboBox *fontList;
    QComboBox *shadowQuality;
    QComboBox *rangeList;
    QCheckBox *axisTitlesVisibleCB;
    QCheckBox *axisTitlesFixedCB;
    QSlider *axisLabelRotationSlider ;};

#endif // FORM_H
