// image_filter_app.cpp
// Application Qt + OpenCV pour appliquer Octree Quantization et Error Diffusion Dithering

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QImage>
#include <QPixmap>
#include <opencv2/opencv.hpp>
#include "octree_quantizer.h"


using namespace cv;

Mat originalImg, processedImg;
QLabel* originalLabel;
QLabel* processedLabel;

QImage matToQImage(const Mat& mat) {
    Mat rgb;
    if (mat.channels() == 1)
        cvtColor(mat, rgb, COLOR_GRAY2RGB);
    else
        cvtColor(mat, rgb, COLOR_BGR2RGB);
    return QImage((const uchar*)rgb.data, rgb.cols, rgb.rows, rgb.step, QImage::Format_RGB888).copy();
}

void showImage(const Mat& img, QLabel* label) {
    label->setPixmap(QPixmap::fromImage(matToQImage(img)).scaled(300, 300, Qt::KeepAspectRatio));
}

Mat convertToGray(const Mat& img) {
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    return gray;
}

Mat errorDiffusionDither(Mat img, int levels = 2) {
    img.convertTo(img, CV_32F, 1.0 / 255);
    Mat result = img.clone();
    int h = img.rows;
    int w = img.cols;
    
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            for (int c = 0; c < img.channels(); c++) {
                float oldPixel = result.at<Vec3f>(y, x)[c];
                float newPixel = round(oldPixel * (levels - 1)) / (levels - 1);
                float error = oldPixel - newPixel;
                result.at<Vec3f>(y, x)[c] = newPixel;

                if (x + 1 < w) result.at<Vec3f>(y, x + 1)[c] += error * 7 / 16.0f;
                if (y + 1 < h && x > 0) result.at<Vec3f>(y + 1, x - 1)[c] += error * 3 / 16.0f;
                if (y + 1 < h) result.at<Vec3f>(y + 1, x)[c] += error * 5 / 16.0f;
                if (y + 1 < h && x + 1 < w) result.at<Vec3f>(y + 1, x + 1)[c] += error * 1 / 16.0f;
            }
        }
    }
    result.convertTo(result, CV_8U, 255);
    return result;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow window;
    QWidget *central = new QWidget();

    QPushButton *loadBtn = new QPushButton("Charger Image");
    QPushButton *grayBtn = new QPushButton("Grayscale");
    QPushButton *ditherBtn = new QPushButton("Dithering");
    QPushButton *saveBtn = new QPushButton("Sauvegarder");
    QPushButton *quantizeBtn = new QPushButton("Quantification (Octree)");
    QPushButton *resetBtn = new QPushButton("Réinitialiser");





    originalLabel = new QLabel();
    processedLabel = new QLabel();

    QHBoxLayout *imageLayout = new QHBoxLayout();
    imageLayout->addWidget(originalLabel);
    imageLayout->addWidget(processedLabel);
    

    QVBoxLayout *btnLayout = new QVBoxLayout();
    btnLayout->addWidget(loadBtn);
    btnLayout->addWidget(grayBtn);
    btnLayout->addWidget(ditherBtn);
    btnLayout->addWidget(quantizeBtn);
    btnLayout->addWidget(resetBtn);
    btnLayout->addWidget(saveBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(imageLayout);
    mainLayout->addLayout(btnLayout);

    central->setLayout(mainLayout);
    window.setCentralWidget(central);
    window.setWindowTitle("Image Filter App");
    window.resize(800, 600);

    QObject::connect(resetBtn, &QPushButton::clicked, [&]() {

        processedImg = originalImg.clone();
        showImage(processedImg, processedLabel);

    });


    QObject::connect(loadBtn, &QPushButton::clicked, [&]() {
        QString file = QFileDialog::getOpenFileName(nullptr, "Open Image", "", "Images (*.png *.jpg *.bmp)");
        if (!file.isEmpty()) {
            originalImg = imread(file.toStdString());
            processedImg = originalImg.clone();
            showImage(originalImg, originalLabel);
            showImage(processedImg, processedLabel);
        }
    });

    QObject::connect(quantizeBtn, &QPushButton::clicked, [&]() {
        OctreeQuantizer quantizer(64); 
        processedImg = quantizer.quantizeImage(originalImg);
        showImage(processedImg, processedLabel);
    });
    

    QObject::connect(grayBtn, &QPushButton::clicked, [&]() {
        processedImg = convertToGray(originalImg);
        showImage(processedImg, processedLabel);
    });

    QObject::connect(ditherBtn, &QPushButton::clicked, [&]() {
        processedImg = errorDiffusionDither(originalImg);
        showImage(processedImg, processedLabel);
    });

    QObject::connect(saveBtn, &QPushButton::clicked, [&]() {
        QString filename = QFileDialog::getSaveFileName(nullptr, "Save Image", "", "Images (*.png *.jpg *.bmp)");
        if (!filename.isEmpty()) {
            imwrite(filename.toStdString(), processedImg);
        }
    });

    window.show();
    return app.exec();
}
