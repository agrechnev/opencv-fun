#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//===============================
static void fatal(const string & mes){
    cerr << mes << endl;
    exit(-1);
}
//===============================
static void process(Mat & frame, CascadeClassifier & casFace, CascadeClassifier & casEyes){
    // To Gray
    Mat frameGray;
    cvtColor(frame, frameGray, COLOR_BGR2GRAY);
    equalizeHist(frameGray, frameGray);

    // Detect faces
    vector<Rect> faces;
    casFace.detectMultiScale(frameGray, faces, 1.1, 2, CASCADE_SCALE_IMAGE, Size(30, 30));
    for (const Rect & f : faces) {
        const int fw = f.width/2;
        const int fh = f.height/2;
        Point center(f.x+fw, f.y+fh);
        ellipse(frame, center, Size(fw, fh), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);

        // Detect eyes on the face
        Mat faceMat = frameGray(f);
        vector<Rect> eyes;
        casEyes.detectMultiScale(faceMat, eyes, 1.1, 2, CASCADE_SCALE_IMAGE, Size(30, 30));
        for (const Rect & e : eyes) {
            Point centerE(f.x+e.x+e.width/2, f.y+e.y+e.height/2);
            int rad = cvRound((e.width + e.height)/4);
            circle(frame, centerE, rad, Scalar(255, 0, 0), 4, 8, 0);
        }
    }
}
//===============================
int main(){
    // Open cam
    VideoCapture cam(CV_CAP_ANY);
    if (!cam.isOpened())
        fatal("Cannot open camera");

    // Load cascades
    CascadeClassifier casFace;
    CascadeClassifier casEyes;
    if (!casFace.load("haarcascade_frontalface_alt.xml") ||
            !casEyes.load("haarcascade_eye_tree_eyeglasses.xml"))
        fatal("Error loading cascades !");

    // Game loop
    Mat frame;
    for (;;){
        cam.read(frame);
        process(frame, casFace, casEyes);
        imshow("Goblin Window", frame);
        if ('q' == waitKey(1))
            break;
    }

    return 0;
}
