#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

#include <string>

#include <boost/filesystem.hpp>
#include <boost/regex.hpp>


#include <math.h>



#include "NormalizationLib.h"
#include "DispLib.h"
#include "histograms.h"
#include "gradient.h"
#include "RegionU16Lib.h"
#include "StringFcLib.h"

#include "mazdaroi.h"
#include "mazdaroiio.h"

#include <tiffio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

typedef MazdaRoi<unsigned int, 2> MR2DType;

using namespace boost;
using namespace std;
using namespace boost::filesystem;
using namespace cv;

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//           Out of Calss functions
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
int CheckIfMask1IsIncludedInMask2(cv::Mat Mask1, cv::Mat Mask2)
{
    if(Mask1.empty() || Mask2.empty())
        return -1;
    if(Mask1.type() != CV_16U || Mask2.type() != CV_16U)
        return -2;
    if(Mask1.channels() != 1 || Mask2.channels() != 1)
        return -3;
    if(Mask1.cols != Mask2.cols || Mask1.rows != Mask2.rows )
        return -4;

    int maxX = Mask1.cols;
    int maxY = Mask1.rows;
    int maxXY = maxX * maxY;

    uint16_t * wMask1 = (uint16_t *)Mask1.data;
    uint16_t * wMask2 = (uint16_t *)Mask2.data;
    for(int i = 0; i < maxXY; i++)
    {
        if(*wMask1 && !(*wMask2))
            return 0;
        wMask1++;
        wMask2++;
    }
    return 1;
}
//------------------------------------------------------------------------------------------------------------------------------
int MaxIntensity(Mat ImOut, Mat ImIn)
{
    if(ImOut.empty())
        return -1;
    if(ImIn.empty())
        return -2;
    if(ImIn.rows != ImOut.rows || ImIn.cols != ImOut.cols)
        return  -3;
    if(ImIn.type() != ImOut.type())
        return -4;
    if(ImIn.type() != CV_16U)
        return -5;

    int maxX = ImOut.cols;
    int maxY = ImOut.rows;
    int maxXY = maxX * maxY;
    uint16_t * wImOut = (uint16_t *)ImOut.data;
    uint16_t * wImIn = (uint16_t *)ImIn.data;
    for(int i = 0; i < maxXY; i++)
    {
        if(*wImOut < *wImIn)
        {
            *wImOut = *wImIn;
        }
        wImOut++;
        wImIn++;
    }
    return 1;
}
//------------------------------------------------------------------------------------------------------------------------------
cv::Mat BackgroundCorrection(cv::Mat ImIn,  cv::Mat ImBackg)
{
    Mat ImOut;
    if(ImIn.empty())
        return ImOut;
    if(ImBackg.empty())
        return ImOut;
    if(ImIn.rows != ImBackg.rows || ImIn.cols != ImBackg.cols)
        return  ImOut;
    if(ImIn.type() != ImBackg.type())
        return ImOut;
    if(ImIn.type() != CV_16U)
        return ImOut;


    int maxX = ImIn.cols;
    int maxY = ImIn.rows;
    int maxXY = maxX * maxY;

    ImOut = Mat::zeros(maxY, maxX, CV_16U);

    uint16_t * wImOut = (uint16_t *)ImOut.data;
    uint16_t * wImIn = (uint16_t *)ImIn.data;
    uint16_t * wImBackg = (uint16_t *)ImBackg.data;
    for(int i = 0; i < maxXY; i++)
    {
        int val = (int)*wImIn + 65535 - (int)*wImBackg;

        if(val < 0)
            val = 0;
        if(val > 65535)
            val = 65535;
        *wImOut = (uint16_t)val;

        wImOut++;
        wImIn++;
        wImBackg++;
    }
    return ImOut;
}
//---------------------------------------------------------------------------
Mat Normalise16Gray(Mat Im16, double minVal, double maxVal)
{
    int maxX = Im16.cols;
    int maxY = Im16.rows;
    int maxXY = maxX * maxY;

    Mat ImOut;

    if(!maxXY)
        return ImOut;

    ImOut = Mat::zeros(maxY, maxX, CV_8U);

    double difference = maxVal - minVal;
    if(difference == 0.0)
        difference = 1.0;
    double gain = 255.00/difference;
    double offset = gain * minVal;

    double value;
    unsigned char index;

    uint16_t *wIm16 = (uint16_t *)Im16.data;
    uint8_t *wImOut = (uint8_t *)ImOut.data;

    for (int i = 0; i < maxXY; i++)
    {

        value = (double)(*wIm16) * gain - offset;
        if (value > 255.0)
            value = 255.0;
        if (value < 0.0)
            value = 0.0;
        index = (unsigned char)floor(value);

        *wImOut = index;

        wImOut++;
        wIm16++;
    }
    return ImOut;
}
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//          constructor Destructor
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBoxNormalization->addItem("None");
    ui->comboBoxNormalization->addItem("MinMax");
    ui->comboBoxNormalization->addItem("+/-3 sigma");
    blockShowingImages = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//          CLASS FUNCTIONS
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void MainWindow::OpenImageFolder()
{
    path ImageFolder( ui->lineEditImageFolder->text().toStdWString());
    ui->listWidgetImageFiles->clear();
    for (directory_entry& FileToProcess : directory_iterator(ImageFolder))
    {
        wregex FilePattern1(ui->lineEditRegexImageFile->text().toStdWString());
        if (!regex_match(FileToProcess.path().filename().wstring(), FilePattern1 ))
            continue;
        path PathLocal = FileToProcess.path();
        if (!exists(PathLocal))
        {
            ui->textEditOut->append(QString::fromStdWString(PathLocal.filename().wstring()) + " File not exists" );
            break;
        }
        ui->listWidgetImageFiles->addItem(QString::fromStdWString(PathLocal.filename().wstring()));
    }
}
//------------------------------------------------------------------------------------------------------------------------------
void MainWindow::ShowsScaledImage(Mat Im, string ImWindowName)
{
    if(Im.empty())
    {
        ui->textEditOut->append("Empty Image to show");
        return;
    }

    Mat ImToShow;

    ImToShow = Im.clone();

    double displayScale = 1/ui->doubleSpinBoxImageScale->value();

    if (displayScale != 1.0)
        cv::resize(ImToShow,ImToShow,Size(), displayScale, displayScale, INTER_AREA);

    imshow(ImWindowName, ImToShow);
}
//------------------------------------------------------------------------------------------------------------------------------
cv::Mat MainWindow::OpenImage(boost::filesystem::path FileToOpen)
{
    //QString ImageFolderQStr = ui->lineEditImageFolder->text();
    //path imageFilePath = ImageFolderQStr.toStdWString();
    //imageFilePath.append(FileName.toStdWString());

    if(ui->checkBoxAutocleanOut->checkState())
        ui->textEditOut->clear();

    Mat ImOut;

    if(!exists(FileToOpen))
    {
        ui->textEditOut->append("file " + QString::fromStdWString(FileToOpen.wstring()) + "not exists");
        return ImOut;
    }

    //int flags = IMREAD_COLOR;;
    int flags = IMREAD_ANYDEPTH;
    ImOut = imread(FileToOpen.string(), flags);

    if(ImOut.empty())
    {
        ui->textEditOut->append("improper file");
        return ImOut;
    }



    return ImOut;
}
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void MainWindow::ShowImages()
{
    if(ui->checkBoxShowInput->checkState())
    {
        Mat ImToShow;
        ImIn.copyTo(ImToShow);
        ShowsScaledImage(ImToShow, "Input Image");
    }
    else
    {
        destroyWindow("Input Image");
    }

    if(ui->checkBoxShowMask->checkState())
    {
        /*
        int pastePosX = 0;
        Mat ImToShow = Mat::zeros(combinedMaxY,combinedMaxX, CV_8UC3);

        Mat ImToShowLocal;

        double minNorm = ui->doubleSpinBoxMinNorm->value();
        double maxNorm = ui->doubleSpinBoxMaxNorm->value();

        ImToShowLocal = ShowImageF32Gray(ImIn2,minNorm,maxNorm);
        if(ui->checkBoxShowMaskAsContour->checkState())
            ImToShowLocal = ShowTransparentRegionOnImage(GetContour5(Mask2), ImToShowLocal);
        else
            ImToShowLocal = ShowTransparentRegionOnImage(Mask2, ImToShowLocal);
        ImToShowLocal.copyTo(ImToShow(Rect(pastePosX, 0, ImIn2.cols, ImIn2.rows)));
        pastePosX += ImIn2.cols;

        ImToShowLocal = ShowImageF32Gray(ImIn3,minNorm,maxNorm);
        if(ui->checkBoxShowMaskAsContour->checkState())
            ImToShowLocal = ShowTransparentRegionOnImage(GetContour5(Mask3), ImToShowLocal);
        else
            ImToShowLocal = ShowTransparentRegionOnImage(Mask3, ImToShowLocal);
        ImToShowLocal.copyTo(ImToShow(Rect(pastePosX, 0, ImIn3.cols, ImIn3.rows)));
        pastePosX += ImIn3.cols;

        ImToShowLocal = ShowImageF32Gray(ImIn4,minNorm,maxNorm);
        if(ui->checkBoxShowMaskAsContour->checkState())
            ImToShowLocal = ShowTransparentRegionOnImage(GetContour5(Mask4), ImToShowLocal);
        else
            ImToShowLocal = ShowTransparentRegionOnImage(Mask4, ImToShowLocal);
        ImToShowLocal.copyTo(ImToShow(Rect(pastePosX, 0, ImIn4.cols, ImIn4.rows)));
        pastePosX += ImIn4.cols;

        ImToShowLocal = ShowImageF32Gray(ImIn5,minNorm,maxNorm);
        if(ui->checkBoxShowMaskAsContour->checkState())
            ImToShowLocal = ShowTransparentRegionOnImage(GetContour5(Mask5), ImToShowLocal);
        else
            ImToShowLocal = ShowTransparentRegionOnImage(Mask5, ImToShowLocal);
        ImToShowLocal.copyTo(ImToShow(Rect(pastePosX, 0, ImIn5.cols, ImIn5.rows)));
        pastePosX += ImIn5.cols;

        ImToShowLocal = ShowImageF32Gray(ImIn6,minNorm,maxNorm);
        if(ui->checkBoxShowMaskAsContour->checkState())
            ImToShowLocal = ShowTransparentRegionOnImage(GetContour5(Mask6), ImToShowLocal);
        else
            ImToShowLocal = ShowTransparentRegionOnImage(Mask6, ImToShowLocal);
        ImToShowLocal.copyTo(ImToShow(Rect(pastePosX, 0, ImIn6.cols, ImIn6.rows)));
        pastePosX += ImIn6.cols;

        ShowsScaledImage(ImToShow, "Mask On Image");
        */

    }

    Mat ImToShow;

    double minNorm = ui->doubleSpinBoxMinNorm->value();
    double maxNorm = ui->doubleSpinBoxMaxNorm->value();

    ImToShow = ShowImage16Gray(ImIn,minNorm,maxNorm);

    if(ui->checkBoxShowOut->checkState())
    {
        ShowsScaledImage(ImToShow, "Out");

    }else
    {
        destroyWindow("Out");
    }

    if(ui->checkBoxShowMask->checkState())
    {
        if(ui->checkBoxShowMaskAsContour->checkState())
            ShowsScaledImage(ShowTransparentRegionOnImage(GetContour5(MaskCombined), ImToShow), "Mask");
        else
            ShowsScaledImage(ShowTransparentRegionOnImage(MaskCombined, ImToShow), "Mask");
            ShowsScaledImage(ShowTransparentRegionOnImage(MaskFromImage, ImToShow), "MaskIm");
    }
    else
    {
        destroyWindow("Mask");
    }

    if(ui->checkBoxShowCombined->checkState() && (!ImCombined.empty()))
    {
        Mat ImToShow = ShowImage16Gray(ImCombined,minNorm,maxNorm);;

        ShowsScaledImage(ImToShow, "Combined Image");
    }
    if(ui->checkBoxBackgroundCorrection->checkState() && (!ImCombined.empty()))
    {
        Mat ImToShow = ShowImage16Gray(ImCorrected,minNorm,maxNorm);;

        ShowsScaledImage(ImToShow, "Corrected Image");
    }

}
//------------------------------------------------------------------------------------------------------------------------------
void MainWindow::ProcessImage()
{
    if(ImIn.empty())
        return;
    maxX = ImIn.cols;
    maxY = ImIn.rows;
    maxXY = maxX * maxY;

    ImCorrected.release();
    if(ui->checkBoxBackgroundCorrection->checkState())
    {
        if(!ImCombined.empty())
        {
            ImCorrected = BackgroundCorrection(ImIn,ImCombined);
        }
        else
        {
            ui->textEditOut->append("ImCombined does not exists");
            ImCorrected = ImIn;
        }
    }
    else
        ImCorrected = ImIn;

//--------------------------------------Get Mask from image
    MaskFromImage.release();
    if(ui->checkBoxThresholdImage->checkState())
    {
        MaskFromImage = Threshold16(ImIn,ui->spinBoxThreshold->value());
        if(ui->spinBoxErosionRadius->value() > 0)
        {
            RegionErosion5ZeroPad(MaskFromImage);
            ErosionCircleCV(MaskFromImage, ui->spinBoxErosionRadius->value() - 1);
        }
    }
    else
    {
        MaskFromImage = Mat::ones(maxY, maxX, CV_16U);
    }

//--------------------------------------Get Mask Tiles
    MaskCombined.release();
    MaskTile.release();
    MaskCombined = Mat::zeros(maxY, maxX, CV_16U);
    vector <MR2DType*> ROIVect;
    if(ui->checkBoxCreateTileROIs->checkState())
    {
        MaskTile = Mat::zeros(maxY, maxX, CV_16U);

        int diameter = ui->spinBoxDiameter->value();
        int offset = ui->spinBoxOffset->value();
        int radius = diameter/2;
        MultiRegionsParams RegParams;
        Point Centroid = GetRegionCentroid(MaskFromImage,1);

        //int xCircleCount = (Centroid.x - diameter)/offset;

        int begin[MR2DType::Dimensions];
        int end[MR2DType::Dimensions];
        begin[0] = 0;
        begin[1] = 0;
        end[0] = maxX-1;
        end[1] = maxY-1;

        MR2DType *ROI;
        uint16_t *wMaskTile;

        int roiNr = 1;
        if(Centroid.x >-1)
        {
            circle(MaskCombined,Centroid,radius,2);
            int xStart = Centroid.x - ((Centroid.x - radius)/offset) * offset;
            int yStart = Centroid.y - ((Centroid.y - radius)/offset) * offset;
            for(int y = yStart; y < maxY - radius; y += offset)
            {

                for(int x = xStart; x < maxX - radius; x += offset)
                {
                    MaskTile *=0;
                    Centroid.y = y;
                    Centroid.x = x;
                    circle(MaskTile,Centroid,radius,1,-1);
                    if(CheckIfMask1IsIncludedInMask2(MaskTile,MaskFromImage)>0)
                    {
                        circle(MaskCombined,Centroid,radius,1);
                        ROI = new MR2DType(begin, end);

                        MazdaRoiIterator<MR2DType> iteratorKL(ROI);
                        wMaskTile = (uint16_t *)MaskTile.data;
                        while(! iteratorKL.IsBehind())
                        {
                            if (*wMaskTile == 1)
                                iteratorKL.SetPixel();
                            ++iteratorKL;
                            wMaskTile++;
                        }

                        ROI->SetName(imageFilePath.stem().string() + "Y" + ItoStrLZ(y,4)+ "X" + ItoStrLZ(x,4));
                        ROI->SetColor(RegColorsRGB[(roiNr-1)%16]);

                        ROIVect.push_back(ROI);
                        roiNr++;
                    }

                }
            }

        }

    }
    else
    {
        int begin[MR2DType::Dimensions];
        int end[MR2DType::Dimensions];
        begin[0] = 0;
        begin[1] = 0;
        end[0] = maxX-1;
        end[1] = maxY-1;

        MR2DType *ROI;
        uint16_t *wMaskTile;

        ROI = new MR2DType(begin, end);
        int roiNr = 1;

        MazdaRoiIterator<MR2DType> iteratorKL(ROI);
        uint16_t *wMaskFromImage = (uint16_t *)MaskFromImage.data;
        while(! iteratorKL.IsBehind())
        {
            if (*wMaskFromImage == 1)
                iteratorKL.SetPixel();
            ++iteratorKL;
            wMaskFromImage++;
        }
        ROI->SetName(imageFilePath.stem().string() + "R" + ItoStrLZ(roiNr,3));
        ROI->SetColor(RegColorsRGB[(roiNr-1)%16]);

        ROIVect.push_back(ROI);
        roiNr++;
    }

//----------------------------------------------Save roi File
    if(ui->checkBoxSaveTileRoi->checkState())
    {
        path RoiFile = ui->lineEditOutFolder->text().toStdWString();
        if(exists(RoiFile))
        {
            if(is_directory(RoiFile))
            {
                RoiFile.append(imageFilePath.stem().string() + ".roi");
                MazdaRoiIO<MR2DType>::Write(RoiFile.string(), &ROIVect, NULL);
            }
        }

    }
    while(ROIVect.size() > 0)
    {
         delete ROIVect.back();
         ROIVect.pop_back();
    }
   // ui->textEditOut->append(QString::fromStdString( MatPropetiesAsText(ImIn)));
//--------------------------------------------GetNormalisation Params
    double maxNorm;
    double minNorm;

    switch(ui->comboBoxNormalization->currentIndex())
    {
    case 1:
        NormParamsMinMax16U(ImCorrected, MaskFromImage, 1, &maxNorm, &minNorm);
        break;
    default:
        maxNorm = 65535;
        minNorm = 0;
        break;
    }

    ui->doubleSpinBoxMaxNorm->setValue(maxNorm);
    ui->doubleSpinBoxMinNorm->setValue(minNorm);
    ui->textEditOut->append("maxNorm = " + QString::number(maxNorm) +
                            " minNorm = " + QString::number(minNorm));

//-------------------------------------------- Save Corrected image
    if(ui->checkBoxSaveCorrecteImage->checkState())
    {
        path ImageOutFile = ui->lineEditOutFolder->text().toStdWString();
        if(exists(ImageOutFile))
        {
            if(is_directory(ImageOutFile))
            {
                ImageOutFile.append(imageFilePath.stem().string() + ".tif");
                Mat ImTemp = Normalise16Gray(ImCorrected, ui->doubleSpinBoxMinNorm->value(),
                                             ui->doubleSpinBoxMaxNorm->value());
                imwrite(ImageOutFile.string(), ImTemp);
            }
        }
    }
    if(!blockShowingImages)
        ShowImages();
}
//------------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//          Slots
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_pushButtonOpenImageFolder_clicked()
{
    QFileDialog dialog(this, "Open Folder");
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setDirectory(ui->lineEditImageFolder->text());
    path ImageFolder;
    //wstring test;
    //path ImageFile;
    if(dialog.exec())
    {
        ImageFolder = dialog.directory().path().toStdWString();
    }
    else
        return;
    if (!exists(ImageFolder))
    {
        ui->textEditOut->append(" Image folder : " + QString::fromStdWString(ImageFolder.wstring())+ " not exists ");
        return;
    }
    if (!is_directory(ImageFolder))
    {
        ui->textEditOut->append(" Image folder : " + QString::fromStdWString(ImageFolder.wstring())+ " This is not a directory path ");
        return;
    }
    ui->lineEditImageFolder->setText(QString::fromStdWString(ImageFolder.wstring()));

    OpenImageFolder();
   // if(ui->listWidgetImageFiles->count()>0)
   //     ui->listWidgetImageFiles->setCurrentRow(0);
}

void MainWindow::on_listWidgetImageFiles_currentTextChanged(const QString &currentText)
{
    QString ImageFolderQStr = ui->lineEditImageFolder->text();

    imageFilePath = ImageFolderQStr.toStdWString();
    imageFilePath.append(currentText.toStdWString());
    ImIn.release();
    ImIn = OpenImage(imageFilePath);
    ProcessImage();

}

void MainWindow::on_doubleSpinBoxImageScale_valueChanged(double arg1)
{
    ShowImages();
}

void MainWindow::on_comboBoxNormalization_currentIndexChanged(int index)
{
    ImIn.release();
    ImIn = OpenImage(imageFilePath);
    ProcessImage();
}

void MainWindow::on_doubleSpinBoxMinNorm_valueChanged(double arg1)
{
    ShowImages();
}

void MainWindow::on_doubleSpinBoxMaxNorm_valueChanged(double arg1)
{
    ShowImages();
}

void MainWindow::on_checkBoxShowInput_toggled(bool checked)
{
    ShowImages();
}

void MainWindow::on_checkBoxShowMask_toggled(bool checked)
{
    ShowImages();
}

void MainWindow::on_checkBoxShowMaskAsContour_toggled(bool checked)
{
    ShowImages();
}

void MainWindow::on_checkBoxShowOut_toggled(bool checked)
{
    ShowImages();
}

void MainWindow::on_spinBoxThreshold_valueChanged(int arg1)
{
    ProcessImage();
}

void MainWindow::on_spinBoxErosionRadius_valueChanged(int arg1)
{
    ProcessImage();
}

void MainWindow::on_spinBoxDiameter_valueChanged(int arg1)
{
    ProcessImage();
}

void MainWindow::on_spinBoxOffset_valueChanged(int arg1)
{
    ProcessImage();
}

void MainWindow::on_pushButtonOpenMaskFile_clicked()
{

}

void MainWindow::on_pushButtonOpenOutFolder_clicked()
{
    QFileDialog dialog(this, "Open Folder");
    dialog.setFileMode(QFileDialog::Directory);
    //dialog.setDirectory(ui->lineEditOutFolder->text());
    path OutFolder;
    //wstring test;
    //path ImageFile;
    if(dialog.exec())
    {
        OutFolder = dialog.directory().path().toStdWString();
    }
    else
        return;
    if (!exists(OutFolder))
    {
        ui->textEditOut->append(" Image folder : " + QString::fromStdWString(OutFolder.wstring())+ " not exists ");
        return;
    }
    if (!is_directory(OutFolder))
    {
        ui->textEditOut->append(" Image folder : " + QString::fromStdWString(OutFolder.wstring())+ " This is not a directory path ");
        return;
    }
    ui->lineEditOutFolder->setText(QString::fromStdWString(OutFolder.wstring()));
}

void MainWindow::on_pushButtonProcessAllFiles_clicked()
{
    blockShowingImages = true;
    int filesCount = ui->listWidgetImageFiles->count();
    ui->textEditOut->clear();
    for(int fileNr = 0; fileNr< filesCount; fileNr++)
    {
        //time_t begin,end;
        //time (&begin);
        imageFilePath = ui->lineEditImageFolder->text().toStdWString();
        imageFilePath.append(ui->listWidgetImageFiles->item(fileNr)->text().toStdWString());
        ImIn.release();
        ImIn = OpenImage(imageFilePath);
        ProcessImage();

        //waitKey(20);

    }
    blockShowingImages = false;
}

void MainWindow::on_pushButtonGetImCombination_clicked()
{
    blockShowingImages = true;
    ImCombined.release();
    ImCombined = Mat::zeros(maxY, maxX, CV_16U);

    int filesCount = ui->listWidgetImageFiles->count();
    ui->textEditOut->clear();
    for(int fileNr = 0; fileNr< filesCount; fileNr++)
    {
        //time_t begin,end;
        //time (&begin);
        imageFilePath = ui->lineEditImageFolder->text().toStdWString();
        imageFilePath.append(ui->listWidgetImageFiles->item(fileNr)->text().toStdWString());
        ImIn.release();
        ImIn = OpenImage(imageFilePath);
        MaxIntensity(ImCombined, ImIn);

        //waitKey(20);

    }
    if(ui->checkBoxBlurFilter->checkState())
    {
        int kernelDiameter = ui->spinBoxBlurKernelSize->value();
        GaussianBlur(ImCombined,ImCombined,Size(kernelDiameter,kernelDiameter),0);
    }

    blockShowingImages = false;
    ShowImages();
    ui->textEditOut->append("Max Intensity done");
}
