#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QObject (parent)
{
    widgetGraph = new Q3DBars();
    containers = QWidget::createWindowContainer(widgetGraph);
    if(!widgetGraph->hasContext()){
        QMessageBox msgBox;
        msgBox.setText("Couldn't initialize the OpenGL context.");
        msgBox.exec();
    }
    screenSize = widgetGraph->screen()->size();
    containers->setMinimumSize(QSize(screenSize.width()/2,screenSize.height()/2));
    containers->setMaximumSize(screenSize);
    containers->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    containers->setFocusPolicy(Qt::StrongFocus);
    widget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    hLayout->addWidget(containers, 1);
    hLayout->addLayout(vLayout);

    widget->setWindowTitle(QStringLiteral("Average temperatures in Oulu and Helsinki, Finland (2006-2013)"));

    themeList = new QComboBox(widget);
    themeList->addItem(QStringLiteral("Qt"));
    themeList->addItem(QStringLiteral("Primary Colors"));
    themeList->addItem(QStringLiteral("Digia"));
    themeList->addItem(QStringLiteral("Stone Moss"));
    themeList->addItem(QStringLiteral("Army Blue"));
    themeList->addItem(QStringLiteral("Retro"));
    themeList->addItem(QStringLiteral("Ebony"));
    themeList->addItem(QStringLiteral("Isabelle"));
    themeList->setCurrentIndex(0);

    labelButton = new QPushButton(widget);
    labelButton->setText(QStringLiteral("Change label style"));

    smoothCheckBox = new QCheckBox(widget);
    smoothCheckBox->setText(QStringLiteral("Smooth bars"));
    smoothCheckBox->setChecked(false);

    barStyleList = new QComboBox(widget);
    barStyleList->addItem(QStringLiteral("Bar"), int(QAbstract3DSeries::MeshBar));
    barStyleList->addItem(QStringLiteral("Pyramid"), int(QAbstract3DSeries::MeshPyramid));
    barStyleList->addItem(QStringLiteral("Cone"), int(QAbstract3DSeries::MeshCone));
    barStyleList->addItem(QStringLiteral("Cylinder"), int(QAbstract3DSeries::MeshCylinder));
    barStyleList->addItem(QStringLiteral("Bevel bar"), int(QAbstract3DSeries::MeshBevelBar));
    barStyleList->addItem(QStringLiteral("Sphere"), int(QAbstract3DSeries::MeshSphere));
    barStyleList->setCurrentIndex(4);

    cameraButton = new QPushButton(widget);
    cameraButton->setText(QStringLiteral("Change camera preset"));

    zoomToSelectedButton = new QPushButton(widget);
    zoomToSelectedButton->setText(QStringLiteral("Zoom to selected bar"));

    selectionModeList = new QComboBox(widget);
    selectionModeList->addItem(QStringLiteral("None"),
                               int(QAbstract3DGraph::SelectionNone));
    selectionModeList->addItem(QStringLiteral("Bar"),
                               int(QAbstract3DGraph::SelectionItem));
    selectionModeList->addItem(QStringLiteral("Row"),
                               int(QAbstract3DGraph::SelectionRow));
    selectionModeList->addItem(QStringLiteral("Bar and Row"),
                               int(QAbstract3DGraph::SelectionItemAndRow));
    selectionModeList->addItem(QStringLiteral("Column"),
                               int(QAbstract3DGraph::SelectionColumn));
    selectionModeList->addItem(QStringLiteral("Bar and Column"),
                               int(QAbstract3DGraph::SelectionItemAndColumn));
    selectionModeList->addItem(QStringLiteral("Row and Column"),
                               int(QAbstract3DGraph::SelectionRowAndColumn));
    selectionModeList->addItem(QStringLiteral("Bar, Row and Column"),
                               int(QAbstract3DGraph::SelectionItemRowAndColumn));
    selectionModeList->addItem(QStringLiteral("Slice into Row"),
                               int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionRow));
    selectionModeList->addItem(QStringLiteral("Slice into Row and Item"),
                               int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionItemAndRow));
    selectionModeList->addItem(QStringLiteral("Slice into Column"),
                               int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionColumn));
    selectionModeList->addItem(QStringLiteral("Slice into Column and Item"),
                               int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionItemAndColumn));
    selectionModeList->addItem(QStringLiteral("Multi: Bar, Row, Col"),
                               int(QAbstract3DGraph::SelectionItemRowAndColumn
                                   | QAbstract3DGraph::SelectionMultiSeries));
    selectionModeList->addItem(QStringLiteral("Multi, Slice: Row, Item"),
                               int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionItemAndRow
                                   | QAbstract3DGraph::SelectionMultiSeries));
    selectionModeList->addItem(QStringLiteral("Multi, Slice: Col, Item"),
                               int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionItemAndColumn
                                   | QAbstract3DGraph::SelectionMultiSeries));
    selectionModeList->setCurrentIndex(1);

    backgroundCheckBox = new QCheckBox(widget);
    backgroundCheckBox->setText(QStringLiteral("Show background"));
    backgroundCheckBox->setChecked(false);

    gridCheckBox = new QCheckBox(widget);
    gridCheckBox->setText(QStringLiteral("Show grid"));
    gridCheckBox->setChecked(true);

    seriesCheckBox = new QCheckBox(widget);
    seriesCheckBox->setText(QStringLiteral("Show second series"));
    seriesCheckBox->setChecked(false);

    reverseValueAxisCheckBox = new QCheckBox(widget);
    reverseValueAxisCheckBox->setText(QStringLiteral("Reverse value axis"));
    reverseValueAxisCheckBox->setChecked(false);

    reflectionCheckBox = new QCheckBox(widget);
    reflectionCheckBox->setText(QStringLiteral("Show reflections"));
    reflectionCheckBox->setChecked(false);

    rotationSliderX = new QSlider(Qt::Horizontal, widget);
    rotationSliderX->setTickInterval(30);
    rotationSliderX->setTickPosition(QSlider::TicksBelow);
    rotationSliderX->setMinimum(-180);
    rotationSliderX->setValue(0);
    rotationSliderX->setMaximum(180);
    QSlider *rotationSliderY = new QSlider(Qt::Horizontal, widget);
    rotationSliderY->setTickInterval(15);
    rotationSliderY->setTickPosition(QSlider::TicksAbove);
    rotationSliderY->setMinimum(-90);
    rotationSliderY->setValue(0);
    rotationSliderY->setMaximum(90);

    fontSizeSlider = new QSlider(Qt::Horizontal, widget);
    fontSizeSlider->setTickInterval(10);
    fontSizeSlider->setTickPosition(QSlider::TicksBelow);
    fontSizeSlider->setMinimum(1);
    fontSizeSlider->setValue(30);
    fontSizeSlider->setMaximum(100);

    fontList = new QFontComboBox(widget);
    fontList->setCurrentFont(QFont("Times New Roman"));

    shadowQuality = new QComboBox(widget);
    shadowQuality->addItem(QStringLiteral("None"));
    shadowQuality->addItem(QStringLiteral("Low"));
    shadowQuality->addItem(QStringLiteral("Medium"));
    shadowQuality->addItem(QStringLiteral("High"));
    shadowQuality->addItem(QStringLiteral("Low Soft"));
    shadowQuality->addItem(QStringLiteral("Medium Soft"));
    shadowQuality->addItem(QStringLiteral("High Soft"));
    shadowQuality->setCurrentIndex(5);

    rangeList = new QComboBox(widget);
    rangeList->addItem(QStringLiteral("2006"));
    rangeList->addItem(QStringLiteral("2007"));
    rangeList->addItem(QStringLiteral("2008"));
    rangeList->addItem(QStringLiteral("2009"));
    rangeList->addItem(QStringLiteral("2010"));
    rangeList->addItem(QStringLiteral("2011"));
    rangeList->addItem(QStringLiteral("2012"));
    rangeList->addItem(QStringLiteral("2013"));
    rangeList->addItem(QStringLiteral("All"));
    rangeList->setCurrentIndex(8);

    axisTitlesVisibleCB = new QCheckBox(widget);
    axisTitlesVisibleCB->setText(QStringLiteral("Axis titles visible"));
    axisTitlesVisibleCB->setChecked(true);

    axisTitlesFixedCB = new QCheckBox(widget);
    axisTitlesFixedCB->setText(QStringLiteral("Axis titles fixed"));
    axisTitlesFixedCB->setChecked(true);

    axisLabelRotationSlider = new QSlider(Qt::Horizontal, widget);
    axisLabelRotationSlider->setTickInterval(10);
    axisLabelRotationSlider->setTickPosition(QSlider::TicksBelow);
    axisLabelRotationSlider->setMinimum(0);
    axisLabelRotationSlider->setValue(30);
    axisLabelRotationSlider->setMaximum(90);

    vLayout->addWidget(new QLabel(QStringLiteral("Rotate horizontally")));
    vLayout->addWidget(rotationSliderX, 0, Qt::AlignTop);
    vLayout->addWidget(new QLabel(QStringLiteral("Rotate vertically")));
    vLayout->addWidget(rotationSliderY, 0, Qt::AlignTop);
    vLayout->addWidget(labelButton, 0, Qt::AlignTop);
    vLayout->addWidget(cameraButton, 0, Qt::AlignTop);
    vLayout->addWidget(zoomToSelectedButton, 0, Qt::AlignTop);
    vLayout->addWidget(backgroundCheckBox);
    vLayout->addWidget(gridCheckBox);
    vLayout->addWidget(smoothCheckBox);
    vLayout->addWidget(reflectionCheckBox);
    vLayout->addWidget(seriesCheckBox);
    vLayout->addWidget(reverseValueAxisCheckBox);
    vLayout->addWidget(axisTitlesVisibleCB);
    vLayout->addWidget(axisTitlesFixedCB);
    vLayout->addWidget(new QLabel(QStringLiteral("Show year")));
    vLayout->addWidget(rangeList);
    vLayout->addWidget(new QLabel(QStringLiteral("Change bar style")));
    vLayout->addWidget(barStyleList);
    vLayout->addWidget(new QLabel(QStringLiteral("Change selection mode")));
    vLayout->addWidget(selectionModeList);
    vLayout->addWidget(new QLabel(QStringLiteral("Change theme")));
    vLayout->addWidget(themeList);
    vLayout->addWidget(new QLabel(QStringLiteral("Adjust shadow quality")));
    vLayout->addWidget(shadowQuality);
    vLayout->addWidget(new QLabel(QStringLiteral("Change font")));
    vLayout->addWidget(fontList);
    vLayout->addWidget(new QLabel(QStringLiteral("Adjust font size")));
    vLayout->addWidget(fontSizeSlider);
    vLayout->addWidget(new QLabel(QStringLiteral("Axis label rotation")));
    vLayout->addWidget(axisLabelRotationSlider, 1, Qt::AlignTop);

    GraphModofoer *modifier = new GraphModofoer(widgetGraph, minValue, maxValue,vectZ, vectX,yName,xName,zName, array );

    QObject::connect(rotationSliderX, &QSlider::valueChanged, modifier, &GraphModofoer::rotateX);
    QObject::connect(rotationSliderY, &QSlider::valueChanged, modifier, &GraphModofoer::rotateY);

    QObject::connect(labelButton, &QPushButton::clicked, modifier,
               &GraphModofoer::changeLabelBackground);
    QObject::connect(cameraButton, &QPushButton::clicked, modifier,
               &GraphModofoer::changePresetCamera);
    QObject::connect(zoomToSelectedButton, &QPushButton::clicked, modifier,
               &GraphModofoer::zoomToSelectedBar);

    QObject::connect(backgroundCheckBox, &QCheckBox::stateChanged, modifier,
               &GraphModofoer::setBackgroundEnabled);
    QObject::connect(gridCheckBox, &QCheckBox::stateChanged, modifier,
               &GraphModofoer::setGridEnabled);
    QObject::connect(smoothCheckBox, &QCheckBox::stateChanged, modifier,
               &GraphModofoer::setSmoothBars);
    QObject::connect(reverseValueAxisCheckBox, &QCheckBox::stateChanged, modifier,
               &GraphModofoer::setReverseValueAxis);
    QObject::connect(reflectionCheckBox, &QCheckBox::stateChanged, modifier,
               &GraphModofoer::setReflection);

    QObject::connect(modifier, &GraphModofoer::backgroundEnabledChanged,
               backgroundCheckBox, &QCheckBox::setChecked);
    QObject::connect(modifier, &GraphModofoer::gridEnabledChanged,
               gridCheckBox, &QCheckBox::setChecked);

    QObject::connect(rangeList, SIGNAL(currentIndexChanged(int)), modifier,
               SLOT(changeRange(int)));

    QObject::connect(barStyleList, SIGNAL(currentIndexChanged(int)), modifier,
               SLOT(changeStyle(int)));

    QObject::connect(selectionModeList, SIGNAL(currentIndexChanged(int)), modifier,
               SLOT(changeSelectionMode(int)));

    QObject::connect(themeList, SIGNAL(currentIndexChanged(int)), modifier,
               SLOT(changeTheme(int)));

    QObject::connect(shadowQuality, SIGNAL(currentIndexChanged(int)), modifier,
               SLOT(changeShadowQuality(int)));

    QObject::connect(modifier, &GraphModofoer::shadowQualityChanged, shadowQuality,
               &QComboBox::setCurrentIndex);
    QObject::connect(widgetGraph, &Q3DBars::shadowQualityChanged, modifier,
               &GraphModofoer::shadowQualityUpdatedByVisual);

    QObject::connect(fontSizeSlider, &QSlider::valueChanged, modifier,
               &GraphModofoer::changeFontSize);
    QObject::connect(fontList, &QFontComboBox::currentFontChanged, modifier,
               &GraphModofoer::changeFont);

    QObject::connect(modifier, &GraphModofoer::fontSizeChanged, fontSizeSlider,
               &QSlider::setValue);
    QObject::connect(modifier, &GraphModofoer::fontChanged, fontList,
               &QFontComboBox::setCurrentFont);

    QObject::connect(axisTitlesVisibleCB, &QCheckBox::stateChanged, modifier,
               &GraphModofoer::setAxisTitleVisibility);
    QObject::connect(axisTitlesFixedCB, &QCheckBox::stateChanged, modifier,
               &GraphModofoer::setAxisTitleFixed);
    QObject::connect(axisLabelRotationSlider, &QSlider::valueChanged, modifier,
               &GraphModofoer::changeLabelRotation);
    widget->show();
}

