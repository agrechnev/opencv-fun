#include <iostream>
#include <sstream>
#include <string>

#include <opencv2/opencv.hpp>

#include "TextMat.h"

int main(int argc, char **argv) {
    using namespace std;
    using namespace cv;

    cout << "OpenCV version = " << CV_VERSION << endl;


    Mat img = algorithms::readMat("pi.mat");

    cout << "size = " << img.size() << endl;
    cout << "type = " << img.type() << " = " << CV_64F << endl;


    imshow("img", img);
    waitKey(0);


    return 0;
}

