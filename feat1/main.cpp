#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

//--------------------------------------------
static Mat readImg(const string & fileName) {
    Mat result = imread(fileName);
    if (!result.data)
        throw runtime_error("Cannot read file " + fileName);
    else
        return result;
}
//--------------------------------------------
int main() {
    cout << "Handmaiden's War SIFT !" << endl;
    cout << "OpenCV verssion = " << CV_VERSION << endl;

    Mat img1 = readImg("img/box.png");
    Mat img2 = readImg("img/box_in_scene.png");

    // Convert to GS just in case
    Mat gray1, gray2;
    cvtColor(img1, gray1, COLOR_BGR2GRAY);
    cvtColor(img2, gray2, COLOR_BGR2GRAY);

    // Detect features
    Ptr<SIFT> detr = SIFT::create();
    vector<KeyPoint> kp1, kp2;  // Keypoints
    Mat des1, des2; // Descriptors
    detr->detectAndCompute(gray1, noArray(), kp1, des1);
    detr->detectAndCompute(gray2, noArray(), kp2, des2);
    cout << "kp1.size() = " << kp1.size() << endl;
    cout << "kp2.size() = " << kp2.size() << endl;

    // Match, BF
    Ptr<BFMatcher> bf = BFMatcher::create(NORM_L2, true);
    vector<DMatch> matches;
    bf->match(des1, des2, matches);
    cout << "matches.size() = " << matches.size() << endl;

    // Select good matches
    sort(matches.begin(), matches.end(), [](const DMatch & d1, const DMatch & d2)->bool{
        return d1.distance < d2.distance;
    });
    vector<DMatch> good(matches.begin(), matches.begin() + 20);
    cout << "good.size() = " << good.size() << endl;

    // Find homography
    vector<Point2f> srcPts, dstPts;
    for (const DMatch & m : good) {
        srcPts.emplace_back(kp1[m.queryIdx].pt);
        dstPts.emplace_back(kp2[m.trainIdx].pt);
    }
    Mat homo = findHomography(srcPts, dstPts, RANSAC, 5);

    // Draw homography
    vector<Point2f> corners1{{0., 0.}, {(float)img1.cols-1, 0.}, {(float)img1.cols-1, (float)img1.rows-1}, {0., (float)img1.rows-1}};
    vector<Point2f> corners2(4);
    perspectiveTransform(corners1, corners2, homo);
    vector<Point2i> corners2i(corners2.begin(), corners2.end()); // To int
    polylines(img2, corners2i, true, {0xff, 0, 0}, 2, LINE_AA);

    // Draw features and matching
//    drawKeypoints(img1, kp1, img1);
//    drawKeypoints(img2, kp2, img2);
    Mat img3;
    drawMatches(img1, kp1, img2, kp2, good, img3, {0, 0xff, 0}, {0, 0, 0xff});

    // Show
    imshow("img3", img3);
    waitKey(0);

    return 0;
}

