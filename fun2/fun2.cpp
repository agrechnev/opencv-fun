#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "opencv2/opencv.hpp"


//--------------------------------------------
//--------------------------------------------

int main(int arc, char** argv)
{
    using namespace std;
    using namespace cv;

    cout << "Handmaiden's Love" << endl;

    Mat m(200, 600, CV_8UC3);
    randu(m, Scalar::all(0), Scalar::all(0xff));

    imshow("Goblin", m);

    waitKey(0);

    return 0;
}

