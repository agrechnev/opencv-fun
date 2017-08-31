#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "opencv2/opencv.hpp"


using namespace std;
using namespace cv;

RNG rng(time(NULL));

//--------------------------------------------
static void fatal(string s){
    cerr << s << endl;
    exit(-1);
}
//--------------------------------------------
static void process1(Mat & m, const uchar * const table){
    int nCh = m.channels();
    int ny = m.rows;
    int nx = m.cols*nCh;

    if (m.isContinuous()) {
        nx *= ny;
        ny = 1;
    }

    uchar *p;
    for (int iy = 0; iy < ny; ++iy){
        p = m.ptr<uchar>(iy);
        for (int ix = 0; ix < nx; ++ix)
            p[ix] = table[p[ix]];
    }
}
//--------------------------------------------
static void process2(Mat & m, const uchar * const table){
    CV_Assert(m.channels() == 3);

    MatIterator_<Vec3b> it, end;
    for (it = m.begin<Vec3b>(), end = m.end<Vec3b>(); it != end; ++it)
        for (int c = 0; c<3; ++c)
            (*it)[c] = table[(*it)[c]];
}
//--------------------------------------------
static void process3(Mat & m, const uchar * const table){
    CV_Assert(m.channels() == 3);
    int ny = m.rows;
    int nx = m.cols;

    for (int iy = 0; iy < ny; ++iy)
        for (int ix = 0; ix < nx; ++ix)
            for (int c = 0; c<3; ++c)
                m.at<Vec3b>(iy, ix)[c] = table[m.at<Vec3b>(iy, ix)[c]];

}
//--------------------------------------------
int main(int argc, char** argv)
{

    cout << "Handmaiden's Love" << endl;

    constexpr int divideWith = 50;

    uchar table[256];
    Mat lut(1, 256, CV_8U);
    uchar * p =lut.ptr();

    for (int i=0; i<256; ++i)
        table[i] = p[i] = (uchar)(divideWith*(i/divideWith));

    Mat m1 = imread("img/lena512.png");
    CV_Assert(m1.depth() == CV_8U);
//    cout << "m1.channels() = " << m1.channels() << endl;

    Mat m2 = m1.clone();

    int64 t1 = getTickCount();
//    process3(m2, table);
    LUT(m1, lut, m2);
    int64 t2 = getTickCount();
    double d = 1000.0*(t2-t1)/getTickFrequency();
    cout << "d = " << d << endl;

    imshow("m1", m1);
    imshow("m2", m2);
    waitKey(0);

    return 0;
}

