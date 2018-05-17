#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

//--------------------------------------------
int main() {

    cout << "Handmaiden's War" << endl;

    cout << CV_MAJOR_VERSION << " " <<  CV_MINOR_VERSION << endl;

    RNG rng;

    Mat img = imread("img/harris.jpg");
    Mat final = img.clone();
    Mat imgGray;
    cvtColor(img, imgGray, COLOR_BGR2GRAY);

    // Pars
    int maxCorners = 500;
    double qualityLevel = 0.1;
    double minDistance = 20;
    int blockSize = 3, gradientSize = 3;

    vector<Point2f> corners; // The result: corners detected

    goodFeaturesToTrack(imgGray, corners, maxCorners, qualityLevel, minDistance, Mat(), blockSize, gradientSize, true, 0.04);

    cout << "corners.size() = " << corners.size() << endl;

    for (const Point2f & c : corners) {
        Scalar color(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        circle(final, c, 4, color, 2);
    }

    imshow("img", img);
    imshow("final", final);
    waitKey(0);

    return 0;
}

