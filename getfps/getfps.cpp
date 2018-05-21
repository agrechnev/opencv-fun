// Send the webcam data to raw

#include <iostream>
#include <cstdio>

#include "opencv2/opencv.hpp"

//--------------------------------------------

//--------------------------------------------
int main(int, char**)
{
    using namespace cv;
    using namespace std;
    VideoCapture cap(CAP_ANY); // open the default camera
    
    // check if we succeeded
    if(!cap.isOpened())  {
        cerr << "Cannot open camera ! \n";
        return -1;
    }    
    
    // Print the data
    cerr << "width = " << cap.get(CAP_PROP_FRAME_WIDTH) << endl;
    cerr << "height = " << cap.get(CAP_PROP_FRAME_HEIGHT) << endl;
    cerr << "framerate = " << cap.get(CAP_PROP_FPS) << endl;
        
    Mat edges;
    namedWindow("frame",1);
    
    constexpr int NUM_FRAMES = 100; // Number of frames to read
    int64 t1 = cv::getTickCount(); // Start timer
    for(int i=0; i<NUM_FRAMES; i++) // Run 100 frames
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        
        imshow("frame", frame);
        int key = waitKey(1);
        
        if (key >= 0 && key < 255) break;
    }
    int64 t2 = cv::getTickCount(); // Stop timer
    
    double ti = (t2-t1) / getTickFrequency();
    double fps = NUM_FRAMES / ti;
    
    cerr << "fps = " << fps << endl;
    
    return 0;
}

