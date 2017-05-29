// Send the webcam data as JPEG data

#include <iostream>
#include <cstdio>

#include "opencv2/opencv.hpp"

#ifdef _WIN32
  #include <io.h>
  #include <fcntl.h>
#endif

// JPEG quality
// If 50, gives 20-30 k per 640x480 frame
// I don't recommend higher quality
static constexpr int JPEG_QUALITY = 50;

//--------------------------------------------
// Write the frame to stdout (binary mode) as jpg with a size header at present
static void writeFrame(const cv::Mat & frame)
{
    using namespace cv;
    using namespace std;

    vector<uchar> buf; // JPEG buffer

    // Encode frame -> buf as jpeg
    // imwrite("test.jpg", frameOut, {IMWRITE_JPEG_QUALITY, JPEG_QUALITY});
    imencode(".jpg", frame, buf, {IMWRITE_JPEG_QUALITY, JPEG_QUALITY});

    int size = buf.size(); // Jpeg image size

    // Write jpeg size (header), disable later in the tcp version?
    fwrite(&size, 1, 4, stdout);
//    cerr << "size = " << size << endl;

    // Write jpg data to stdout
    fwrite(buf.data(), 1, size, stdout);
}
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

//    namedWindow("frameIn",1);
    namedWindow("frameOutJpg1",1);

    Mat frameIn, frameOut;
    
    // Binary stdin, stdout on windows
#ifdef _WIN32
    setmode(fileno(stdout),O_BINARY);
    setmode(fileno(stdin),O_BINARY);
#endif

    for(;;)
    {
        cap >> frameIn; // get a new frame from the camera

        // Process the frame
        processFrame(frameIn, frameOut);

        // Show 1 frame
//        imshow("frameIn", frameIn);
        imshow("frameOutJpg1", frameOut);
        
        // Encode and write to stdout the frame as jpeg
        writeFrame(frameOut);
        
        // Decode jpeg
        // Buffer as Mat
//        Mat rawMat = Mat(1, buf.size(), CV_8UC1, buf.data());
//        frame3 = imdecode(rawMat, -1); // Decode jpeg data
        
        int key = waitKey(1);
        
        if (key >= 0 && key < 255) break;
    }
    
    return 0;
}
