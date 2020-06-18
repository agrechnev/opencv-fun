#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

#include <opencv2/opencv.hpp>

#include "TextMat.h"

//======================================================================================================================
// Visualize the two e-values
cv::Mat visEVV(const cv::Mat &in) {
    using namespace std;
    using namespace cv;
    cout << "EVV : size = " << in.size() << " , channels=" << in.channels() << " , type=" << in.type() << "="
         << CV_32FC(6) << endl;

    Mat res = Mat::zeros(in.size(), CV_32FC3);
    for (int iy = 0; iy < in.rows; ++iy) {
        for (int ix = 0; ix < in.cols; ++ix) {
            double l1 = in.at<Vec6f>(iy, ix)[0];
            double l2 = in.at<Vec6f>(iy, ix)[1];
            if (l1 > l2)
                swap(l1, l2);
            res.at<Vec3f>(iy, ix)[0] = l1 * 10; // B
            res.at<Vec3f>(iy, ix)[2] = l2 * 2; // R
        }
    }

    double valMin, valMax;
    minMaxLoc(res, &valMin, &valMax);
    cout << "EVV : min = " << valMin << ", max = " << valMax << endl;

    return res;
}

//======================================================================================================================
/// Convert EVV to harris corners
cv::Mat evv2cor(const cv::Mat &in, float k) {
    using namespace std;
    using namespace cv;

    Mat res = Mat::zeros(in.size(), CV_32F);
    for (int iy = 0; iy < in.rows; ++iy) {
        for (int ix = 0; ix < in.cols; ++ix) {
            double l1 = in.at<Vec6f>(iy, ix)[0];
            double l2 = in.at<Vec6f>(iy, ix)[1];
            res.at<float>(iy, ix) = l1 * l2 - k * (l1 + l2) * (l1 + l2);
        }
    }
    return res;
}

//======================================================================================================================
/// Now I am trying to reproduce  cornerEigenValsAndVecs(), EV only
cv::Mat myEV(const cv::Mat &in, int blockSize, int ksize, int borderType = cv::BORDER_DEFAULT) {
    using namespace std;
    using namespace cv;
    Size2i sz = in.size();

    // gradient
    Mat gx, gy;
    double scale = (double) (1 << (ksize - 1)) * blockSize;
    if( in.depth() == CV_8U )
        scale *= 255.0;
    scale = 1 / scale;
//    cout << "scale = " << scale << endl;
    Sobel(in, gx, CV_32F, 1, 0, ksize, scale, 0, borderType);
    Sobel(in, gy, CV_32F, 0, 1, ksize, scale, 0, borderType);
    // Grad matrix
    Mat cov(sz, CV_32FC3);
    for (int iy = 0; iy < sz.height; ++iy) {
        for (int ix = 0; ix < sz.width; ++ix) {
            float ggx = gx.at<float>(iy, ix);
            float ggy = gy.at<float>(iy, ix);
            cov.at<Vec3f>(iy, ix)[0] = ggx * ggx;
            cov.at<Vec3f>(iy, ix)[1] = ggx * ggy;
            cov.at<Vec3f>(iy, ix)[2] = ggy * ggy;
        }
    }

    // Filter it !
    boxFilter(cov, cov, CV_32FC3, Size2i(blockSize, blockSize), Point2i(-1, -1), false, borderType);

    // Get the result !
    Mat res = Mat::zeros(sz, CV_32FC(6));
    for (int iy = 0; iy < sz.height; ++iy) {
        for (int ix = 0; ix < sz.width; ++ix) {
            float a = cov.at<Vec3f>(iy, ix)[0];
            float b = cov.at<Vec3f>(iy, ix)[1];
            float c = cov.at<Vec3f>(iy, ix)[2];
            float t = (a + c) / 2;
            float u = sqrtf(t * t - a * c + b * b);
            float l1 = t - u;
            float l2 = t + u;
            res.at<Vec6f>(iy, ix)[0] = l1;
            res.at<Vec6f>(iy, ix)[1] = l2;
        }
    }
    return res;
}

//======================================================================================================================
int main(int argc, char **argv) {
    using namespace std;
    using namespace cv;

    cout << "OpenCV version = " << CV_VERSION << endl;

    Mat img = imread("img/harris.jpg");
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    // Calc the corners
    Mat outCorners, resCorners;
    cornerHarris(gray, resCorners, 2, 3, 0.04);
    {
        double valMin, valMax;
        minMaxLoc(resCorners, &valMin, &valMax);
        cout << "corners : min = " << valMin << ", max = " << valMax << endl;
    }
    normalize(resCorners, outCorners, 0, 255, NORM_MINMAX, CV_8U);

    int thresh = 150;
    for (int iy = 0; iy < outCorners.rows; ++iy) {
        for (int ix = 0; ix < outCorners.cols; ++ix) {
            if (outCorners.at<uchar>(iy, ix) > thresh) {
                circle(outCorners, Point2i(ix, iy), 5, Scalar(0), 2);
            }
        }
    }

    // Calc e-values, e-vectors
    Mat resEVV;
    cornerEigenValsAndVecs(gray, resEVV, 2, 3);
    Mat outEVV = visEVV(resEVV);

    // EVV to corners
//    Mat resCorners2 = evv2cor(resEVV, 0.04);
//    {
//        double valMin, valMax;
//        minMaxLoc(resCorners2, &valMin, &valMax);
//        cout << "corners2 : min = " << valMin << ", max = " << valMax << endl;
//    }
//    Mat outCorners2;
//    normalize(resCorners2, outCorners2, 0, 255, NORM_MINMAX, CV_8U);

    // TRy my own EVV
    Mat resEVV2 = myEV(gray, 2, 3);
    Mat outEVV2 = visEVV(resEVV2);

    imshow("img", img);
    imshow("outCorners", outCorners);
    imshow("outEVV", outEVV);
    imshow("outEVV2", outEVV2);
    waitKey(0);

    return 0;
}

