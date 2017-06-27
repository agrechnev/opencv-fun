#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "opencv2/opencv.hpp"


//--------------------------------------------
static void process(cv::Mat & m, const std::vector<uchar> & tab){
    using namespace std;
    using namespace cv;

    CV_Assert(m.depth() == CV_8U);
    CV_Assert(tab.size() >= 256);

    int ch = m.channels();
    int ro = m.rows;
    int co = m.cols;

    for (int i = 0; i < ro; i++)
        for (int j = 0; j < co; j++)
            swap(m.at<Vec3b>(i, j)[1], m.at<Vec3b>(i, j)[2]);

}
//--------------------------------------------

int main(int arc, char** argv)
{
    using namespace std;
    using namespace cv;

    cout << "Handmaiden's Love" << endl;

    VideoCapture cap(CV_CAP_ANY); // open the default camera

    // Create the table

    constexpr int RUDE = 50;
    vector<uchar> table(256);
    for (int i = 0; i <= 255; ++i)
        table[i] = (uchar)((i/RUDE)*RUDE);

    cout << "Handmaiden's War" << endl;

    namedWindow("frameOut");
    Mat frameIn, frameOut;
    for(;;)
    {
        cap.read(frameIn); // get a new frame from camera

        frameOut = frameIn.clone();

        process(frameOut, table);

        imshow("frameOut", frameOut);

        if ('q' == waitKey(1))
            break;
    }

    return 0;
}

