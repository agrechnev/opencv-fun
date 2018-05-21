#include <iostream>
#include <opencv2/opencv.hpp>


//-----------------------------------------
int main(int argc, char **argv){
    using namespace std;
    using namespace cv;
    
    
    cout << "OpenCV Version = " << CV_MAJOR_VERSION << "."<< CV_MINOR_VERSION << endl;
    

    // Craete image
    Mat m(500,500, CV_8UC3, Scalar(0,0,0xff));
    Mat r(m, Rect(100, 100, 100, 100));
    r = Scalar(0xff,0,0);
    
    // Display the window
    
    namedWindow("image", WINDOW_AUTOSIZE);
    imshow("image", m);
    
    waitKey(0);
    
    return 0;
}