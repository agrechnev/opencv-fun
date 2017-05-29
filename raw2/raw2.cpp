// Get the raw data and display

#include <iostream>
#include <cstdio>

#include "opencv2/opencv.hpp"

#ifdef _WIN32
  #include <io.h>
  #include <fcntl.h>
#endif
//--------------------------------------------

// Bytes per frame
static constexpr int FRAME_SIZE = 640*480*3;

//--------------------------------------------
int main(int, char**)
{
    using namespace cv;
    using namespace std;
    
    Mat frame(480, 640, CV_8UC3, Scalar(0,0,0));;
    
      // Binary stdin, stdout
#ifdef _WIN32
    setmode(fileno(stdout),O_BINARY);
    setmode(fileno(stdin),O_BINARY);
#endif
    
    namedWindow("frameOutRaw2", 1);
    for(;;)
    {
        // get a new frame from stdin, raw
        fread(frame.data, 1, FRAME_SIZE, stdin);
        
        imshow("frameOutRaw2", frame);
        int key = waitKey(1);
        
        if (key >= 0 && key < 255) break;
    }
    return 0;
}

