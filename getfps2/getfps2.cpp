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
    VideoCapture cap(CV_CAP_ANY); // open the default camera
    
    // check if we succeeded
    if(!cap.isOpened())  {
        cerr << "Cannot open camera ! \n";
        return -1;
    }
//    cap.set(CV_CAP_PROP_FPS, 90);
    
    // Print the data
    cerr << "width = " << cap.get(CV_CAP_PROP_FRAME_WIDTH) << endl;
    cerr << "height = " << cap.get(CV_CAP_PROP_FRAME_HEIGHT) << endl;
    cerr << "framerate = " << cap.get(CV_CAP_PROP_FPS) << endl;

    Mat frame;

    constexpr bool SHOW = false;
    constexpr int NUM_FRAMES = 100; // Number of frames to read

    if (SHOW)
        namedWindow("frame", 1);

    int64 t1 = cv::getTickCount(); // Start timer
    for(int i=0; i<NUM_FRAMES; i++) // Run 100 frames
    {
        bool ret;

        // get next frame from the camera
        //        ret = cap.read(frame); // get a new frame from the camera

        //        if (!ret)
        //            throw runtime_error("Cannot read frame !");

        ret = cap.grab();
        if (!ret)
            throw runtime_error("Cannot grab frame !");
        ret = cap.retrieve(frame);
        if (!ret)
            throw runtime_error("Cannot retrieve frame !");

        if (SHOW) {
            imshow("frame", frame);
            int key = waitKey(1);

            if (key >= 0 && key < 255) break;
        }
    }
    int64 t2 = cv::getTickCount(); // Stop timer
    
    double ti = (t2-t1) / getTickFrequency();
    double fps = NUM_FRAMES / ti;
    
    cerr << "fps = " << fps << endl;
    
    return 0;
}

