/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QLineEdit *lineEditOutFolder;
    QLineEdit *lineEditImageFolder;
    QPushButton *pushButtonOpenImageFolder;
    QPushButton *pushButtonOpenOutFolder;
    QPushButton *pushButtonOpenMaskFile;
    QLineEdit *lineEditMaskFile;
    QFrame *frame_2;
    QLineEdit *lineEditRegexImageFile;
    QListWidget *listWidgetImageFiles;
    QTextEdit *textEditOut;
    QLineEdit *lineEditFileToProcess;
    QFrame *frameMode;
    QCheckBox *checkBoxShowInput;
    QLabel *labelScaleBase;
    QCheckBox *checkBoxShowTiffInfo;
    QCheckBox *checkBoxShowMatInfo;
    QCheckBox *checkBoxAutocleanOut;
    QCheckBox *checkBoxSaveOutput;
    QCheckBox *checkBoxShowMask;
    QCheckBox *checkBoxShowMaskAsContour;
    QDoubleSpinBox *doubleSpinBoxImageScale;
    QCheckBox *checkBoxImRotate;
    QDoubleSpinBox *doubleSpinBoxMinNorm;
    QDoubleSpinBox *doubleSpinBoxMaxNorm;
    QLabel *labelMinNorm;
    QLabel *labelMaxNorm;
    QCheckBox *checkBoxShowOut;
    QComboBox *comboBoxNormalization;
    QCheckBox *checkBoxShowCombined;
    QFrame *frame_3;
    QSpinBox *spinBoxThreshold;
    QLabel *label;
    QSpinBox *spinBoxErosionRadius;
    QLabel *label_2;
    QCheckBox *checkBoxThresholdImage;
    QFrame *frame_4;
    QLabel *label_3;
    QSpinBox *spinBoxOffset;
    QLabel *label_4;
    QSpinBox *spinBoxDiameter;
    QCheckBox *checkBoxCreateTileROIs;
    QFrame *frame_5;
    QPushButton *pushButtonProcessAllFiles;
    QCheckBox *checkBoxSaveTileRoi;
    QPushButton *pushButtonGetImCombination;
    QCheckBox *checkBoxSaveCorrecteImage;
    QPushButton *pushButtonGetGlobalNorm;
    QFrame *frame_6;
    QCheckBox *checkBoxBackgroundCorrection;
    QCheckBox *checkBoxBlurFilter;
    QSpinBox *spinBoxBlurKernelSize;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(958, 708);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 901, 141));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        lineEditOutFolder = new QLineEdit(frame);
        lineEditOutFolder->setObjectName(QString::fromUtf8("lineEditOutFolder"));
        lineEditOutFolder->setGeometry(QRect(170, 110, 721, 21));
        lineEditImageFolder = new QLineEdit(frame);
        lineEditImageFolder->setObjectName(QString::fromUtf8("lineEditImageFolder"));
        lineEditImageFolder->setGeometry(QRect(170, 10, 721, 21));
        pushButtonOpenImageFolder = new QPushButton(frame);
        pushButtonOpenImageFolder->setObjectName(QString::fromUtf8("pushButtonOpenImageFolder"));
        pushButtonOpenImageFolder->setGeometry(QRect(10, 10, 151, 22));
        pushButtonOpenOutFolder = new QPushButton(frame);
        pushButtonOpenOutFolder->setObjectName(QString::fromUtf8("pushButtonOpenOutFolder"));
        pushButtonOpenOutFolder->setGeometry(QRect(10, 110, 151, 22));
        pushButtonOpenMaskFile = new QPushButton(frame);
        pushButtonOpenMaskFile->setObjectName(QString::fromUtf8("pushButtonOpenMaskFile"));
        pushButtonOpenMaskFile->setGeometry(QRect(10, 40, 151, 22));
        lineEditMaskFile = new QLineEdit(frame);
        lineEditMaskFile->setObjectName(QString::fromUtf8("lineEditMaskFile"));
        lineEditMaskFile->setGeometry(QRect(170, 40, 721, 21));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 140, 591, 331));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        lineEditRegexImageFile = new QLineEdit(frame_2);
        lineEditRegexImageFile->setObjectName(QString::fromUtf8("lineEditRegexImageFile"));
        lineEditRegexImageFile->setGeometry(QRect(10, 170, 113, 21));
        listWidgetImageFiles = new QListWidget(frame_2);
        listWidgetImageFiles->setObjectName(QString::fromUtf8("listWidgetImageFiles"));
        listWidgetImageFiles->setGeometry(QRect(10, 10, 571, 151));
        textEditOut = new QTextEdit(frame_2);
        textEditOut->setObjectName(QString::fromUtf8("textEditOut"));
        textEditOut->setGeometry(QRect(10, 200, 571, 121));
        lineEditFileToProcess = new QLineEdit(frame_2);
        lineEditFileToProcess->setObjectName(QString::fromUtf8("lineEditFileToProcess"));
        lineEditFileToProcess->setGeometry(QRect(130, 170, 301, 20));
        frameMode = new QFrame(centralWidget);
        frameMode->setObjectName(QString::fromUtf8("frameMode"));
        frameMode->setGeometry(QRect(590, 140, 161, 331));
        frameMode->setFrameShape(QFrame::Panel);
        frameMode->setFrameShadow(QFrame::Raised);
        checkBoxShowInput = new QCheckBox(frameMode);
        checkBoxShowInput->setObjectName(QString::fromUtf8("checkBoxShowInput"));
        checkBoxShowInput->setGeometry(QRect(10, 0, 141, 25));
        checkBoxShowInput->setChecked(false);
        labelScaleBase = new QLabel(frameMode);
        labelScaleBase->setObjectName(QString::fromUtf8("labelScaleBase"));
        labelScaleBase->setGeometry(QRect(10, 200, 61, 25));
        checkBoxShowTiffInfo = new QCheckBox(frameMode);
        checkBoxShowTiffInfo->setObjectName(QString::fromUtf8("checkBoxShowTiffInfo"));
        checkBoxShowTiffInfo->setGeometry(QRect(10, 20, 141, 25));
        checkBoxShowTiffInfo->setChecked(true);
        checkBoxShowMatInfo = new QCheckBox(frameMode);
        checkBoxShowMatInfo->setObjectName(QString::fromUtf8("checkBoxShowMatInfo"));
        checkBoxShowMatInfo->setGeometry(QRect(10, 40, 141, 25));
        checkBoxAutocleanOut = new QCheckBox(frameMode);
        checkBoxAutocleanOut->setObjectName(QString::fromUtf8("checkBoxAutocleanOut"));
        checkBoxAutocleanOut->setGeometry(QRect(10, 300, 141, 25));
        checkBoxAutocleanOut->setChecked(true);
        checkBoxSaveOutput = new QCheckBox(frameMode);
        checkBoxSaveOutput->setObjectName(QString::fromUtf8("checkBoxSaveOutput"));
        checkBoxSaveOutput->setGeometry(QRect(10, 280, 141, 25));
        checkBoxShowMask = new QCheckBox(frameMode);
        checkBoxShowMask->setObjectName(QString::fromUtf8("checkBoxShowMask"));
        checkBoxShowMask->setGeometry(QRect(10, 70, 141, 20));
        checkBoxShowMask->setChecked(true);
        checkBoxShowMaskAsContour = new QCheckBox(frameMode);
        checkBoxShowMaskAsContour->setObjectName(QString::fromUtf8("checkBoxShowMaskAsContour"));
        checkBoxShowMaskAsContour->setGeometry(QRect(10, 90, 141, 20));
        doubleSpinBoxImageScale = new QDoubleSpinBox(frameMode);
        doubleSpinBoxImageScale->setObjectName(QString::fromUtf8("doubleSpinBoxImageScale"));
        doubleSpinBoxImageScale->setGeometry(QRect(50, 200, 61, 22));
        doubleSpinBoxImageScale->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBoxImageScale->setDecimals(2);
        doubleSpinBoxImageScale->setMinimum(0.250000000000000);
        doubleSpinBoxImageScale->setMaximum(8.000000000000000);
        doubleSpinBoxImageScale->setSingleStep(0.250000000000000);
        doubleSpinBoxImageScale->setValue(0.250000000000000);
        checkBoxImRotate = new QCheckBox(frameMode);
        checkBoxImRotate->setObjectName(QString::fromUtf8("checkBoxImRotate"));
        checkBoxImRotate->setGeometry(QRect(10, 150, 72, 20));
        doubleSpinBoxMinNorm = new QDoubleSpinBox(frameMode);
        doubleSpinBoxMinNorm->setObjectName(QString::fromUtf8("doubleSpinBoxMinNorm"));
        doubleSpinBoxMinNorm->setGeometry(QRect(71, 230, 81, 22));
        doubleSpinBoxMinNorm->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBoxMinNorm->setMinimum(-65536.000000000000000);
        doubleSpinBoxMinNorm->setMaximum(65536.000000000000000);
        doubleSpinBoxMinNorm->setSingleStep(256.000000000000000);
        doubleSpinBoxMinNorm->setValue(0.000000000000000);
        doubleSpinBoxMaxNorm = new QDoubleSpinBox(frameMode);
        doubleSpinBoxMaxNorm->setObjectName(QString::fromUtf8("doubleSpinBoxMaxNorm"));
        doubleSpinBoxMaxNorm->setGeometry(QRect(71, 260, 81, 22));
        doubleSpinBoxMaxNorm->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBoxMaxNorm->setMinimum(-65536.000000000000000);
        doubleSpinBoxMaxNorm->setMaximum(65536.000000000000000);
        doubleSpinBoxMaxNorm->setSingleStep(256.000000000000000);
        doubleSpinBoxMaxNorm->setValue(1000.000000000000000);
        labelMinNorm = new QLabel(frameMode);
        labelMinNorm->setObjectName(QString::fromUtf8("labelMinNorm"));
        labelMinNorm->setGeometry(QRect(10, 230, 61, 22));
        labelMaxNorm = new QLabel(frameMode);
        labelMaxNorm->setObjectName(QString::fromUtf8("labelMaxNorm"));
        labelMaxNorm->setGeometry(QRect(10, 260, 61, 22));
        checkBoxShowOut = new QCheckBox(frameMode);
        checkBoxShowOut->setObjectName(QString::fromUtf8("checkBoxShowOut"));
        checkBoxShowOut->setGeometry(QRect(10, 110, 72, 20));
        checkBoxShowOut->setChecked(true);
        comboBoxNormalization = new QComboBox(frameMode);
        comboBoxNormalization->setObjectName(QString::fromUtf8("comboBoxNormalization"));
        comboBoxNormalization->setGeometry(QRect(20, 170, 65, 22));
        checkBoxShowCombined = new QCheckBox(frameMode);
        checkBoxShowCombined->setObjectName(QString::fromUtf8("checkBoxShowCombined"));
        checkBoxShowCombined->setGeometry(QRect(10, 130, 121, 20));
        checkBoxShowCombined->setChecked(true);
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(750, 140, 151, 101));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Raised);
        spinBoxThreshold = new QSpinBox(frame_3);
        spinBoxThreshold->setObjectName(QString::fromUtf8("spinBoxThreshold"));
        spinBoxThreshold->setGeometry(QRect(62, 40, 71, 22));
        spinBoxThreshold->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBoxThreshold->setMaximum(65535);
        spinBoxThreshold->setValue(50);
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 47, 22));
        spinBoxErosionRadius = new QSpinBox(frame_3);
        spinBoxErosionRadius->setObjectName(QString::fromUtf8("spinBoxErosionRadius"));
        spinBoxErosionRadius->setGeometry(QRect(92, 70, 41, 22));
        spinBoxErosionRadius->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBoxErosionRadius->setValue(7);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 81, 22));
        checkBoxThresholdImage = new QCheckBox(frame_3);
        checkBoxThresholdImage->setObjectName(QString::fromUtf8("checkBoxThresholdImage"));
        checkBoxThresholdImage->setGeometry(QRect(10, 10, 121, 20));
        checkBoxThresholdImage->setChecked(true);
        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(750, 240, 151, 91));
        frame_4->setFrameShape(QFrame::Panel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 30, 51, 22));
        spinBoxOffset = new QSpinBox(frame_4);
        spinBoxOffset->setObjectName(QString::fromUtf8("spinBoxOffset"));
        spinBoxOffset->setGeometry(QRect(90, 60, 43, 22));
        spinBoxOffset->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBoxOffset->setMinimum(10);
        spinBoxOffset->setMaximum(200);
        spinBoxOffset->setValue(51);
        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 71, 22));
        spinBoxDiameter = new QSpinBox(frame_4);
        spinBoxDiameter->setObjectName(QString::fromUtf8("spinBoxDiameter"));
        spinBoxDiameter->setGeometry(QRect(72, 30, 61, 22));
        spinBoxDiameter->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBoxDiameter->setMinimum(11);
        spinBoxDiameter->setMaximum(201);
        spinBoxDiameter->setSingleStep(2);
        spinBoxDiameter->setValue(51);
        checkBoxCreateTileROIs = new QCheckBox(frame_4);
        checkBoxCreateTileROIs->setObjectName(QString::fromUtf8("checkBoxCreateTileROIs"));
        checkBoxCreateTileROIs->setGeometry(QRect(10, 0, 121, 20));
        checkBoxCreateTileROIs->setChecked(true);
        frame_5 = new QFrame(centralWidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(750, 430, 151, 181));
        frame_5->setFrameShape(QFrame::Panel);
        frame_5->setFrameShadow(QFrame::Raised);
        pushButtonProcessAllFiles = new QPushButton(frame_5);
        pushButtonProcessAllFiles->setObjectName(QString::fromUtf8("pushButtonProcessAllFiles"));
        pushButtonProcessAllFiles->setGeometry(QRect(10, 110, 131, 22));
        checkBoxSaveTileRoi = new QCheckBox(frame_5);
        checkBoxSaveTileRoi->setObjectName(QString::fromUtf8("checkBoxSaveTileRoi"));
        checkBoxSaveTileRoi->setGeometry(QRect(10, 10, 121, 20));
        checkBoxSaveTileRoi->setChecked(true);
        pushButtonGetImCombination = new QPushButton(frame_5);
        pushButtonGetImCombination->setObjectName(QString::fromUtf8("pushButtonGetImCombination"));
        pushButtonGetImCombination->setGeometry(QRect(10, 50, 131, 22));
        checkBoxSaveCorrecteImage = new QCheckBox(frame_5);
        checkBoxSaveCorrecteImage->setObjectName(QString::fromUtf8("checkBoxSaveCorrecteImage"));
        checkBoxSaveCorrecteImage->setGeometry(QRect(10, 30, 121, 20));
        checkBoxSaveCorrecteImage->setChecked(true);
        pushButtonGetGlobalNorm = new QPushButton(frame_5);
        pushButtonGetGlobalNorm->setObjectName(QString::fromUtf8("pushButtonGetGlobalNorm"));
        pushButtonGetGlobalNorm->setGeometry(QRect(10, 80, 131, 23));
        frame_6 = new QFrame(centralWidget);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(750, 330, 151, 101));
        frame_6->setFrameShape(QFrame::Panel);
        frame_6->setFrameShadow(QFrame::Raised);
        checkBoxBackgroundCorrection = new QCheckBox(frame_6);
        checkBoxBackgroundCorrection->setObjectName(QString::fromUtf8("checkBoxBackgroundCorrection"));
        checkBoxBackgroundCorrection->setGeometry(QRect(10, 10, 131, 20));
        checkBoxBackgroundCorrection->setChecked(false);
        checkBoxBlurFilter = new QCheckBox(frame_6);
        checkBoxBlurFilter->setObjectName(QString::fromUtf8("checkBoxBlurFilter"));
        checkBoxBlurFilter->setGeometry(QRect(10, 30, 72, 20));
        spinBoxBlurKernelSize = new QSpinBox(frame_6);
        spinBoxBlurKernelSize->setObjectName(QString::fromUtf8("spinBoxBlurKernelSize"));
        spinBoxBlurKernelSize->setGeometry(QRect(30, 50, 43, 22));
        spinBoxBlurKernelSize->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBoxBlurKernelSize->setMinimum(3);
        spinBoxBlurKernelSize->setMaximum(100);
        spinBoxBlurKernelSize->setSingleStep(2);
        spinBoxBlurKernelSize->setValue(21);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 958, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEditOutFolder->setText(QCoreApplication::translate("MainWindow", "I:\\MSMRIBrain\\ROIPhantoms\\5_20250402_t2_tse_tra_3", nullptr));
        lineEditImageFolder->setText(QCoreApplication::translate("MainWindow", "I:\\MSMRIBrain\\TiifPhantoms\\5_20250402_t2_tse_tra_3", nullptr));
        pushButtonOpenImageFolder->setText(QCoreApplication::translate("MainWindow", "Open Image Folder", nullptr));
        pushButtonOpenOutFolder->setText(QCoreApplication::translate("MainWindow", "Open Out Folder", nullptr));
        pushButtonOpenMaskFile->setText(QCoreApplication::translate("MainWindow", "Open ROI File", nullptr));
        lineEditMaskFile->setText(QCoreApplication::translate("MainWindow", "D:\\AdditiveManufacturing\\ROIS2.tif", nullptr));
        lineEditRegexImageFile->setText(QCoreApplication::translate("MainWindow", ".+.tif+", nullptr));
        checkBoxShowInput->setText(QCoreApplication::translate("MainWindow", "Show input", nullptr));
        labelScaleBase->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        checkBoxShowTiffInfo->setText(QCoreApplication::translate("MainWindow", "Show Tiff Info", nullptr));
        checkBoxShowMatInfo->setText(QCoreApplication::translate("MainWindow", "Show Mat Info", nullptr));
        checkBoxAutocleanOut->setText(QCoreApplication::translate("MainWindow", "Auto clean output text", nullptr));
        checkBoxSaveOutput->setText(QCoreApplication::translate("MainWindow", "Save Output", nullptr));
        checkBoxShowMask->setText(QCoreApplication::translate("MainWindow", "Show mask", nullptr));
        checkBoxShowMaskAsContour->setText(QCoreApplication::translate("MainWindow", "Show contours only", nullptr));
        doubleSpinBoxImageScale->setPrefix(QCoreApplication::translate("MainWindow", "1 : ", nullptr));
        doubleSpinBoxImageScale->setSuffix(QString());
        checkBoxImRotate->setText(QCoreApplication::translate("MainWindow", "ImRotate", nullptr));
        labelMinNorm->setText(QCoreApplication::translate("MainWindow", "Min Norm", nullptr));
        labelMaxNorm->setText(QCoreApplication::translate("MainWindow", "Max Norm", nullptr));
        checkBoxShowOut->setText(QCoreApplication::translate("MainWindow", "Show out", nullptr));
        checkBoxShowCombined->setText(QCoreApplication::translate("MainWindow", "Show Combined", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Threshold", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Erosion Radius", nullptr));
        checkBoxThresholdImage->setText(QCoreApplication::translate("MainWindow", "Threshold Image", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Diameter", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Offset", nullptr));
        checkBoxCreateTileROIs->setText(QCoreApplication::translate("MainWindow", "Create Tile ROIs", nullptr));
        pushButtonProcessAllFiles->setText(QCoreApplication::translate("MainWindow", "Process all files", nullptr));
        checkBoxSaveTileRoi->setText(QCoreApplication::translate("MainWindow", "Save Tile Roi", nullptr));
        pushButtonGetImCombination->setText(QCoreApplication::translate("MainWindow", "Get Im Combination", nullptr));
        checkBoxSaveCorrecteImage->setText(QCoreApplication::translate("MainWindow", "Save Correcte Image", nullptr));
        pushButtonGetGlobalNorm->setText(QCoreApplication::translate("MainWindow", "Get Global Normalisatiom", nullptr));
        checkBoxBackgroundCorrection->setText(QCoreApplication::translate("MainWindow", "Background Correction", nullptr));
        checkBoxBlurFilter->setText(QCoreApplication::translate("MainWindow", "Blur Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
