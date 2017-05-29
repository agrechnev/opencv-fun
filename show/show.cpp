// Send the webcam data to raw

#include <iostream>
#include <cstdio>

#include "opencv2/opencv.hpp"

//--------------------------------------------

// Process the frame, put calls to any algorithms here (preferably in separate cpp files)
static void processFrame(const cv::Mat & in, cv::Mat & out)
{
    using namespace cv;
    using namespace std;

    out = in.clone(); // Copy

    // We Work on out here
    int tx = in.cols / 3;  // Size of the central 1/3
    int ty = in.rows / 3;
    Mat r(out, Rect(tx, ty, tx, ty)); // Central 1/3
    bitwise_not(r, r); // Photo negative
}
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
    
    // Print the data
    cerr << "width = " << cap.get(CAP_PROP_FRAME_WIDTH) << endl;
    cerr << "height = " << cap.get(CAP_PROP_FRAME_HEIGHT) << endl;
    cerr << "framerate = " << cap.get(CAP_PROP_FPS) << endl; // Often gives 0

    namedWindow("frameIn",1);
    namedWindow("frameOut",1);

    Mat frameIn, frameOut;

    for(;;)
    {
        cap >> frameIn; // get a new frame from the camera

        // Process the frame
        processFrame(frameIn, frameOut);

        // Show 2 frames
        imshow("frameIn", frameIn);
        imshow("frameOut", frameOut);

        int key = waitKey(1);
        
        if (key >= 0 && key < 255) break;
    }
    
    return 0;
}

