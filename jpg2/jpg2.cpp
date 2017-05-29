// Get the jpeg data and display

#include <iostream>
#include <cstdio>

#include "opencv2/opencv.hpp"

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif
//--------------------------------------------
// Get a jpeg frame (with size header at present) from stdin
static void readFrame(cv::Mat & frame)
{
    using namespace cv;
    using namespace std;

    // Read Size from the header
    int size;
    fread(&size, 1, 4, stdin);

    // Read JPEG data
    char * buf = (char *) malloc(size);
    fread(buf, 1, size, stdin);

    // Decode jpeg data from buf to frame
    Mat rawMat = Mat(1, size, CV_8UC1, buf);
    frame = imdecode(rawMat, IMREAD_COLOR); // Decode jpeg data

    free(buf);
}

//--------------------------------------------
int main(int, char**)
{
    using namespace cv;
    using namespace std;
    
    Mat frame;
    
    // Binary stdin, stdout
#ifdef _WIN32
    setmode(fileno(stdout), O_BINARY);
    setmode(fileno(stdin), O_BINARY);
#endif
    
    namedWindow("frameOutJpg2", 1);
    for(;;)
    {
        readFrame(frame); // Read frame as jpeg data from stdin

        imshow("frameOutJpg2", frame);
        int key = waitKey(1);
        
        if (key >= 0 && key < 255) break;
    }
    return 0;
}

