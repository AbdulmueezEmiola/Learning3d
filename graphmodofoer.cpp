#include "graphmodofoer.h"
#include <QtDataVisualization/qcategory3daxis.h>
#include <QtDataVisualization/qvalue3daxis.h>
#include <QtDataVisualization/qbardataproxy.h>
#include <QtDataVisualization/q3dscene.h>
#include <QtDataVisualization/q3dcamera.h>
#include <QtDataVisualization/qbar3dseries.h>
#include <QtDataVisualization/q3dtheme.h>
#include <QtCore/QTime>
#include <QtWidgets/QComboBox>
#include <QtCore/qmath.h>
using namespace QtDataVisualization;
GraphModofoer::GraphModofoer(Q3DBars *bargraph, double min, double max, QVector<QString>vectX, QVector<QString>vectZ,
                             QString yName, QString xName, QString zName, double**array):
    m_graph(bargraph),
    m_xRotation(0.0f),
    m_yRotation(0.0f),
    m_fontSize(30),
    m_segments(5),
    m_subSegments(3),
    m_minval(min),
    m_maxval(max),
    m_yAxis(new QValue3DAxis),
    m_xAxis(new QCategory3DAxis),
    m_zAxis(new QCategory3DAxis),
    m_primarySeries(new QBar3DSeries),
    m_barMesh(QAbstract3DSeries::MeshBevelBar),
    m_smooth(false)
{
    m_graph->setShadowQuality(QAbstract3DGraph::ShadowQualitySoftMedium);
    m_graph->activeTheme()->setBackgroundEnabled(false);
    m_graph->activeTheme()->setFont(QFont("Times New Roman", m_fontSize));
    m_graph->activeTheme()->setLabelBackgroundEnabled(true);
    m_graph->setMultiSeriesUniform(true);
    for(int i =0;i<vectX.size();i++){
        m_xString<<vectX.at(i);
    }
    for(int i=0;i<vectZ.size();i++){
        m_zString<<vectZ.at(i);
    }
    m_yAxis->setTitle(yName);
    m_yAxis->setSegmentCount(m_segments);
    m_yAxis->setSubSegmentCount(m_subSegments);
    m_yAxis->setRange(m_minval, m_maxval);
    m_yAxis->setLabelAutoRotation(30.0f);
    m_yAxis->setTitleVisible(true);
    m_xAxis->setTitle(xName);
    m_xAxis->setLabelAutoRotation(30.0f);
    m_zAxis->setTitleVisible(true);
    m_zAxis->setTitle(zName);
    m_zAxis->setLabelAutoRotation(30.0f);
    m_zAxis->setTitleVisible(true);
    m_graph->setValueAxis(m_yAxis);
    m_graph->setRowAxis(m_xAxis);
    m_graph->setColumnAxis(m_zAxis);
    m_primarySeries->setItemLabelFormat(QStringLiteral("Value - @colLabel @rowLabel: @valueLabel"));
    m_primarySeries->setMesh(QAbstract3DSeries::MeshBevelBar);
    m_primarySeries->setMeshSmooth(false);
    m_graph->addSeries(m_primarySeries);
    changePresetCamera();
    resetData(array);
    Q3DCamera *camera = m_graph->scene()->activeCamera();
    m_defaultAngleX = camera->xRotation();
    m_defaultAngleY = camera->yRotation();
    m_defaultZoom = camera->zoomLevel();
    m_defaultTarget = camera->target();

    m_animationCameraX.setTargetObject(camera);
    m_animationCameraY.setTargetObject(camera);
    m_animationCameraZoom.setTargetObject(camera);
    m_animationCameraTarget.setTargetObject(camera);

    m_animationCameraX.setPropertyName("xRotation");
    m_animationCameraY.setPropertyName("yRotation");
    m_animationCameraZoom.setPropertyName("zoomLevel");
    m_animationCameraTarget.setPropertyName("target");

    int duration = 1700;
    m_animationCameraX.setDuration(duration);
    m_animationCameraY.setDuration(duration);
    m_animationCameraZoom.setDuration(duration);
    m_animationCameraTarget.setDuration(duration);
    qreal zoomOutFraction = 0.3;
    m_animationCameraX.setKeyValueAt(zoomOutFraction, QVariant::fromValue(0.0f));
    m_animationCameraY.setKeyValueAt(zoomOutFraction, QVariant::fromValue(90.0f));
    m_animationCameraZoom.setKeyValueAt(zoomOutFraction, QVariant::fromValue(50.0f));
    m_animationCameraTarget.setKeyValueAt(zoomOutFraction,
                                   QVariant::fromValue(QVector3D(0.0f, 0.0f, 0.0f)));
    double **arr ;
    *arr = new double[vectX.size()];
    arr = new double*[vectZ.size()];
    for(int i =0;i<vectX.size();i++){
        for(int j =0;j<vectZ.size();j++){
            arr[i][j]=array[i][j];
        }
    }
    resetData(arr);
}
void GraphModofoer::resetData(double ** arr){

    QBarDataArray *dataSet = new QBarDataArray;
    QBarDataArray *dataSet2 = new QBarDataArray;
    QBarDataRow *dataRow;
    QBarDataRow *dataRow2;

    dataSet->reserve(m_xString.size());
    for (int year = 0; year < m_xString.size(); year++) {
        // Create a data row
        dataRow = new QBarDataRow(m_zString.size());
        dataRow2 = new QBarDataRow(m_zString.size());
        for (int month = 0; month < m_zString.size(); month++) {
            // Add data to the row
            (*dataRow)[month].setValue(arr[year][month]);
        }
        // Add the row to the set
        dataSet->append(dataRow);
        dataSet2->append(dataRow2);
    }
    m_primarySeries->dataProxy()->resetArray(dataSet, m_xString, m_zString);
}
void GraphModofoer::changeRange(int range)
 {
     if (range >= m_xString.count())
         m_xAxis->setRange(0, m_xString.count() - 1);
     else
         m_xAxis->setRange(range, range);
 }
void GraphModofoer::changeStyle(int style)
 {
     QComboBox *comboBox = qobject_cast<QComboBox *>(sender());
     if (comboBox) {
         m_barMesh = QAbstract3DSeries::Mesh(comboBox->itemData(style).toInt());
         m_primarySeries->setMesh(m_barMesh);
     }
 }

void GraphModofoer::changePresetCamera()
{
    m_animationCameraX.stop();
    m_animationCameraY.stop();
    m_animationCameraZoom.stop();
    m_animationCameraTarget.stop();

    // Restore camera target in case animation has changed it
    m_graph->scene()->activeCamera()->setTarget(QVector3D(0.0f, 0.0f, 0.0f));

    static int preset = Q3DCamera::CameraPresetFront;

    m_graph->scene()->activeCamera()->setCameraPreset((Q3DCamera::CameraPreset)preset);

    if (++preset > Q3DCamera::CameraPresetDirectlyBelow)
        preset = Q3DCamera::CameraPresetFrontLow;
}

void GraphModofoer::changeTheme(int theme)
{
    Q3DTheme *currentTheme = m_graph->activeTheme();
    currentTheme->setType(Q3DTheme::Theme(theme));
    emit backgroundEnabledChanged(currentTheme->isBackgroundEnabled());
    emit gridEnabledChanged(currentTheme->isGridEnabled());
    emit fontChanged(currentTheme->font());
    emit fontSizeChanged(currentTheme->font().pointSize());
}

void GraphModofoer::changeLabelBackground()
{
    m_graph->activeTheme()->setLabelBackgroundEnabled(!m_graph->activeTheme()->isLabelBackgroundEnabled());
}

void GraphModofoer::changeSelectionMode(int selectionMode)
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(sender());
    if (comboBox) {
        int flags = comboBox->itemData(selectionMode).toInt();
        m_graph->setSelectionMode(QAbstract3DGraph::SelectionFlags(flags));
    }
}

void GraphModofoer::changeFont(const QFont &font)
{
    QFont newFont = font;
    m_graph->activeTheme()->setFont(newFont);
}

void GraphModofoer::changeFontSize(int fontsize)
{
    m_fontSize = fontsize;
    QFont font = m_graph->activeTheme()->font();
    font.setPointSize(m_fontSize);
    m_graph->activeTheme()->setFont(font);
}

void GraphModofoer::shadowQualityUpdatedByVisual(QAbstract3DGraph::ShadowQuality sq)
{
    int quality = int(sq);
    // Updates the UI component to show correct shadow quality
    emit shadowQualityChanged(quality);
}

void GraphModofoer::changeLabelRotation(int rotation)
{
    m_yAxis->setLabelAutoRotation(float(rotation));
    m_zAxis->setLabelAutoRotation(float(rotation));
    m_xAxis->setLabelAutoRotation(float(rotation));
}

void GraphModofoer::setAxisTitleVisibility(bool enabled)
{
    m_yAxis->setTitleVisible(enabled);
    m_zAxis->setTitleVisible(enabled);
    m_xAxis->setTitleVisible(enabled);
}
void GraphModofoer::setAxisTitleFixed(bool enabled)
{
  m_yAxis->setTitleFixed(enabled);
  m_zAxis->setTitleFixed(enabled);
  m_xAxis->setTitleFixed(enabled);
}

void GraphModofoer::zoomToSelectedBar()
{
    m_animationCameraX.stop();
    m_animationCameraY.stop();
    m_animationCameraZoom.stop();
    m_animationCameraTarget.stop();

    Q3DCamera *camera = m_graph->scene()->activeCamera();
    float currentX = camera->xRotation();
    float currentY = camera->yRotation();
    float currentZoom = camera->zoomLevel();
    QVector3D currentTarget = camera->target();

    m_animationCameraX.setStartValue(QVariant::fromValue(currentX));
    m_animationCameraY.setStartValue(QVariant::fromValue(currentY));
    m_animationCameraZoom.setStartValue(QVariant::fromValue(currentZoom));
    m_animationCameraTarget.setStartValue(QVariant::fromValue(currentTarget));

    QPoint selectedBar = m_graph->selectedSeries()
            ? m_graph->selectedSeries()->selectedBar()
            : QBar3DSeries::invalidSelectionPosition();

    if (selectedBar != QBar3DSeries::invalidSelectionPosition()) {
        // Normalize selected bar position within axis range to determine target coordinates
        QVector3D endTarget;
        float xMin = m_graph->columnAxis()->min();
        float xRange = m_graph->columnAxis()->max() - xMin;
        float zMin = m_graph->rowAxis()->min();
        float zRange = m_graph->rowAxis()->max() - zMin;
        endTarget.setX((selectedBar.y() - xMin) / xRange * 2.0f - 1.0f);
        endTarget.setZ((selectedBar.x() - zMin) / zRange * 2.0f - 1.0f);

        // Rotate the camera so that it always points approximately to the graph center
        qreal endAngleX = 90.0 - qRadiansToDegrees(qAtan(qreal(endTarget.z() / endTarget.x())));
        if (endTarget.x() > 0.0f)
            endAngleX -= 180.0f;
        float barValue = m_graph->selectedSeries()->dataProxy()->itemAt(selectedBar.x(),
                                                                        selectedBar.y())->value();
        float endAngleY = barValue >= 0.0f ? 30.0f : -30.0f;
        if (m_graph->valueAxis()->reversed())
            endAngleY *= -1.0f;

        m_animationCameraX.setEndValue(QVariant::fromValue(float(endAngleX)));
        m_animationCameraY.setEndValue(QVariant::fromValue(endAngleY));
        m_animationCameraZoom.setEndValue(QVariant::fromValue(250));
        m_animationCameraTarget.setEndValue(QVariant::fromValue(endTarget));
    } else {
        // No selected bar, so return to the default view
        m_animationCameraX.setEndValue(QVariant::fromValue(m_defaultAngleX));
        m_animationCameraY.setEndValue(QVariant::fromValue(m_defaultAngleY));
        m_animationCameraZoom.setEndValue(QVariant::fromValue(m_defaultZoom));
        m_animationCameraTarget.setEndValue(QVariant::fromValue(m_defaultTarget));
    }

    m_animationCameraX.start();
    m_animationCameraY.start();
    m_animationCameraZoom.start();
    m_animationCameraTarget.start();
}

void GraphModofoer::changeShadowQuality(int quality)
{
    QAbstract3DGraph::ShadowQuality sq = QAbstract3DGraph::ShadowQuality(quality);
    m_graph->setShadowQuality(sq);
    emit shadowQualityChanged(quality);
}

void GraphModofoer::rotateX(int rotation)
{
    m_xRotation = rotation;
    m_graph->scene()->activeCamera()->setCameraPosition(m_xRotation, m_yRotation);
}

void GraphModofoer::rotateY(int rotation)
{
    m_yRotation = rotation;
    m_graph->scene()->activeCamera()->setCameraPosition(m_xRotation, m_yRotation);
}

void GraphModofoer::setBackgroundEnabled(int enabled)
{
    m_graph->activeTheme()->setBackgroundEnabled(bool(enabled));
}
void GraphModofoer::setGridEnabled(int enabled)
{
  m_graph->activeTheme()->setGridEnabled(bool(enabled));
}

void GraphModofoer::setSmoothBars(int smooth)
{
  m_smooth = bool(smooth);
  m_primarySeries->setMeshSmooth(m_smooth);
}


void GraphModofoer::setReverseValueAxis(int enabled)
{
  m_graph->valueAxis()->setReversed(enabled);
}

void GraphModofoer::setReflection(bool enabled)
{
  m_graph->setReflection(enabled);
}

GraphModofoer::~GraphModofoer()
{
    delete m_graph;
}
