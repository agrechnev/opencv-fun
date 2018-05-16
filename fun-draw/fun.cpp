#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>

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
static int randLines(cv::Mat &image, const std::string & winName, cv::RNG & rng)
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
            return key == 'q';
        }
    }
}
//--------------------------------------------
static int randRectangles(cv::Mat &image, const std::string & winName, cv::RNG & rng)
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

        rectangle(image, p1, p2, randomColor(rng), rng.uniform(-1, 10), lineType);

        imshow(winName, image);

        int key = waitKey(1);
        if (key>-1 && key<255)
        {
            return key == 'q';
        }
    }

}
//--------------------------------------------
static int randEllipses(cv::Mat &image, const std::string & winName, cv::RNG & rng)
{
    using namespace cv;
    const int lineType = 8;

    for (;;)
    {
        Point cent(rng.uniform(x_1, x_2), rng.uniform(y_1, y_2));

        Size axes(rng.uniform(0, 200), rng.uniform(0, 200));

        double angle = rng.uniform(0, 180);

        ellipse(image, cent, axes, angle, angle-100, angle+200,
                randomColor(rng), rng.uniform(-1, 10), lineType);

        imshow(winName, image);

        int key = waitKey(1);
        if (key>-1 && key<255)
        {
            return key == 'q';
        }
    }

}
//--------------------------------------------
static int randPolyLines(cv::Mat &image, const std::string & winName, cv::RNG & rng)
{
    using namespace cv;
    const int lineType = 8;

    for (;;)
    {
        Point pt[2][3];
        for (int i=0; i<2; i++)
            for (int j=0; j<3; j++)
                pt[i][j] = Point(rng.uniform(x_1, x_2), rng.uniform(y_1, y_2));


        const Point * ppt[2] = {pt[0], pt[1]};
        int npt[] = {3, 3};

        polylines(image, ppt, npt, 2 , true, randomColor(rng), rng.uniform(1, 10), lineType);

        imshow(winName, image);

        int key = waitKey(1);
        if (key>-1 && key<255)
        {
            return key == 'q';
        }
    }

}
//--------------------------------------------
static int randFilledPoly(cv::Mat &image, const std::string & winName, cv::RNG & rng)
{
    using namespace cv;
    const int lineType = 8;

    for (;;)
    {
        Point pt[2][3];
        for (int i=0; i<2; i++)
            for (int j=0; j<3; j++)
                pt[i][j] = Point(rng.uniform(x_1, x_2), rng.uniform(y_1, y_2));


        const Point * ppt[2] = {pt[0], pt[1]};
        int npt[] = {3, 3};

        fillPoly(image, ppt, npt, 2 , randomColor(rng), lineType);

        imshow(winName, image);

        int key = waitKey(1);
        if (key>-1 && key<255)
        {
            return key == 'q';
        }
    }

}
//--------------------------------------------
static int randCircles(cv::Mat &image, const std::string & winName, cv::RNG & rng)
{
    using namespace cv;
    const int lineType = 8;

    for (;;)
    {
        Point cent(rng.uniform(x_1, x_2), rng.uniform(y_1, y_2));

        circle(image, cent, rng.uniform(0, 300), randomColor(rng), rng.uniform(-1, 10), lineType);

        imshow(winName, image);

        int key = waitKey(1);
        if (key>-1 && key<255)
        {
            return key == 'q';
        }
    }

}
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

    const string winName = "Goblin Window (q = quit)";

    // Random number generator
    RNG rng( time(NULL));

    // Atom
    Mat image = Mat::zeros(winHeight, winWidth, CV_8UC3);

    namedWindow(winName, 1);

    for (;;)
    {
        if (randLines(image, winName, rng))
            return 0;

        if (randRectangles(image, winName, rng))
            return 0;

        if (randEllipses(image, winName, rng))
            return 0;

        if (randPolyLines(image, winName, rng))
            return 0;

        if (randFilledPoly(image, winName, rng))
            return 0;

        if (randCircles(image, winName, rng))
            return 0;
    }
}

