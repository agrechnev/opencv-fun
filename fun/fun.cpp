#include <string>
#include <iostream>
#include <cstdio>

#include "opencv2/opencv.hpp"

constexpr int winWidth = 800;
constexpr int winHeight = 600;

constexpr int x_1 = -winWidth/2;
constexpr int x_2 = winWidth*3/2;
constexpr int y_1 = -winHeight/2;
constexpr int y_2 = winHeight*3/2;

//--------------------------------------------
static cv::Scalar randomColor(cv::RNG rng) {
    unsigned ucolor = (unsigned) rng;

    return cv::Scalar(ucolor & 0xff, (ucolor >> 8) & 0xff, (ucolor >> 16) & 0xff);
}
//--------------------------------------------
// Returns true to quit
static int randLines(cv::Mat &image, const char *winName, cv::RNG & rng)
{
    using namespace cv;
    const int lineType = 8;
    Point p1, p2;



    for (;;)
    {
        p1.x = rng.uniform(x_1, x_2);
        p1.y = rng.uniform(y_1, y_2);
        p2.x = rng.uniform(x_1, x_2);
        p2.y = rng.uniform(y_1, y_2);


        line(image, p1, p2, randomColor(rng), rng.uniform(1, 10), lineType);

        imshow(winName, image);

        int key = waitKey(1);
        if (key>-1 && key<255)
        {
            return (char)key == 'q';
        }
    }
}
//--------------------------------------------
//--------------------------------------------
//--------------------------------------------
//--------------------------------------------

int main(int arc, char** argv)
{
    using namespace std;
    using namespace cv;

    /*
    // Read image from file
    Mat in = imread(argv[1]);
    if (!in.data)
        throw runtime_error("Cannot read input file");
    */

    const char * winName = "Goblin Window";


    // Random number generator
    RNG rng( 0xFFFFFFFF);


    // Atom
    Mat image = Mat::zeros(winHeight, winWidth, CV_8UC3);


    namedWindow(winName, 1);


    for (;;)
    {
        if (randLines(image, winName, rng))
            return 0;
    }
}

