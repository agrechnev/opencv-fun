#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv){
    using namespace std;
    using namespace cv;
    
    if (argc != 2) {
        cout << "Usge : fun <image_file> \n";
        return -1;
    }
    
    const char * fileName = argv[1];
    
    // Read Image
    
    Mat image;
    image = imread(fileName, 1);
    
    if (!image.data) {
        cout << "Read failed \n";
        return -1;
    }
    
    // Show image
    namedWindow(fileName, CV_WINDOW_AUTOSIZE);
    imshow(fileName, image);
    
    // Create, save and show the grayscale image
    Mat grayImage;
    
    Mat im2(image, Rect(200, 200, 100, 100));
    
    // cvtColor(image, grayImage, CV_BGR2GRAY);
    // imwrite("gray.png", grayImage);
    
    namedWindow("Goblin", CV_WINDOW_AUTOSIZE);
    imshow("Goblin", im2);
    
    waitKey(0);
    
    return 0;
}