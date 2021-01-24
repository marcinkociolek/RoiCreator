#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <boost/filesystem.hpp>
#include <opencv2/core/core.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonOpenImageFolder_clicked();

    void on_listWidgetImageFiles_currentTextChanged(const QString &currentText);

    void on_doubleSpinBoxImageScale_valueChanged(double arg1);

    void on_comboBoxNormalization_currentIndexChanged(int index);

    void on_doubleSpinBoxMinNorm_valueChanged(double arg1);

    void on_doubleSpinBoxMaxNorm_valueChanged(double arg1);

    void on_checkBoxShowInput_toggled(bool checked);

    void on_checkBoxShowMask_toggled(bool checked);

    void on_checkBoxShowMaskAsContour_toggled(bool checked);

    void on_checkBoxShowOut_toggled(bool checked);

    void on_spinBoxThreshold_valueChanged(int arg1);

    void on_spinBoxErosionRadius_valueChanged(int arg1);

    void on_spinBoxDiameter_valueChanged(int arg1);

    void on_spinBoxOffset_valueChanged(int arg1);

    void on_pushButtonOpenMaskFile_clicked();

    void on_pushButtonOpenOutFolder_clicked();

    void on_pushButtonProcessAllFiles_clicked();

    void on_pushButtonGetImCombination_clicked();

private:
    Ui::MainWindow *ui;
    cv::Mat ImIn;
    cv::Mat ImCombined;
    cv::Mat ImCorrected;
    cv::Mat MaskFromImage;
    cv::Mat MaskTile;
    cv::Mat MaskCombined;

    int maxX;
    int maxY;
    int maxXY;

    boost::filesystem::path imageFilePath;

    bool blockShowingImages;
    //double minNorm;
    //double maxNorm;

    void OpenImageFolder();
    void ShowsScaledImage(cv::Mat Im, std::string ImWindowName);
    cv::Mat OpenImage(boost::filesystem::path FileToOpen);
    void ShowImages();
    void ProcessImage();

};

#endif // MAINWINDOW_H
