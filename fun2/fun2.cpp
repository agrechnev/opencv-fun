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

    Mat img = imread("img/wolf500.jpg");

    while (1) {
        imshow("Goblin Window", img);
        int key = waitKey(0);
        if (27 == key)
            break;
        else if ('i' == key)
            pyrUp(img, img);
        else if ('o' == key)
            pyrDown(img, img);
    }

    return 0;
}

