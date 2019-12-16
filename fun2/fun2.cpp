#include <iostream>
#include <sstream>
#include <string>

#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
    using namespace std;
    using namespace cv;

    cout << "OpenCV version = " << CV_VERSION << endl;

    parallel_for_(Range(0, 10), [](const Range &r) -> void {
        ostringstream oss;
        oss << "r = " << r.start << " : " << r.end << "\n";
        cout << oss.str();
    }, -1);

    cout << endl;

    return 0;
}

