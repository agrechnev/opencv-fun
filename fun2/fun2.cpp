#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(int argc, char **argv) {
    const string keys = "{help h usage ?||HELP MESSAGE}{name |Brianna|Your name}{@file|<none>|File name}";
    CommandLineParser parser(argc, argv, keys);
    parser.about("Brianna App !!!");
    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }
    string name = parser.get<string>("name");
    cout << "name = " << name << endl;
    string file = parser.get<string>(0);
    cout << "file = " << file << endl;

    if (!parser.check()) {
        parser.printErrors();
        return 0;
    }

    return 0;
}

