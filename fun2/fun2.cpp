#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(int argc, char **argv) {
    // 1-pixel matrix
    Mat m = Mat::zeros(Size(600, 200), CV_8U);
    m.at<uchar>(100, 300) = 1;
    
    // Sobel grad
    Mat sx, sy, s;
    Sobel(m, sx, CV_64F , 1, 0);
    Sobel(m, sy, CV_64F , 0, 1);
    sqrt(sx.mul(sx) + sy.mul(sy), s);
        
    imshow("sx", sx);
    imshow("sy", sy);
    imshow("s", s > 0.001);
    waitKey(0);
    return 0;
}

