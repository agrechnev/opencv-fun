//
// Created by Oleksiy Grechnyev on 5/24/18.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "TextMat.h"
namespace algorithms {
//======================================
    /// A simple hash function
    uint32_t hashDJB2(const void * buf, size_t bufSize){
        const uint8_t * bufU = (const uint8_t *) buf;
        uint32_t hash = 5381;
        for (size_t i = 0; i < bufSize; ++i) {
            hash = (hash << 5) + hash + bufU[i];
        }
        return hash;
    }
//======================================
//======================================
    void PrintToTxt_uchar(std::string name, cv::Mat mat) {
        std::ofstream fileStream(name);

        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j) {
                fileStream << std::setw(3) << static_cast<int>(mat.at<uchar>(i, j)) << "  ";
            }
            fileStream << "\n";
        }
    }
//======================================

    cv::Mat ReadMatFromTxt_uchar(std::string filename, int rows, int cols) {
        int m;
        cv::Mat out = cv::Mat::zeros(rows, cols, CV_8UC1);//Matrix to store values
        std::ifstream fileStream(filename);
        if (!fileStream)
            throw std::runtime_error("ReadMatFromTxt_uchar() : cannot open file " + filename);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                fileStream >> m;
                out.at<uchar>(i, j) = static_cast<uchar>(m);
            }
        }
        return out;
    }
//======================================

    void writeMat(const cv::Mat & m, const std::string & fileName){
        using namespace std;
        if (sizeof(int) != 4)
            throw runtime_error("writeMat() : sizeof(int) != 4 !");

        ofstream out(fileName, ios::binary);
        if (!out)
            throw runtime_error("writeMat() : Cannot create file " + fileName);

        if (m.empty()) {
            int i = 0;
            out.write((const char *)(&i), 4);
        } else {
            int type = m.type();
            // Header
            out.write((const char *)(&m.rows), 4);
            out.write((const char *)(&m.cols), 4);
            out.write((const char *)(&type), 4);
            // Data
            if (m.isContinuous())
                out.write((const char *)(m.data), m.elemSize()*m.total());
            else {
                const void * p;
                for (int i = 0; i < m.rows; ++i) {
                    p = m.ptr<uchar>(i); // Pointer to row i
                    out.write((const char *)p, m.elemSize()*m.cols);
                }
            }
        }

        if (!out)
            throw runtime_error("writeMat() : Cannot write file " + fileName);
    }
//======================================

    cv::Mat readMat(const std::string & fileName){
        using namespace std;
        if (sizeof(int) != 4)
            throw runtime_error("writeMat() : sizeof(int) != 4 !");

        ifstream in(fileName, ios::binary);
        if (!in)
            throw runtime_error("readMat() : Cannot open file " + fileName);

        int rows, cols, type;
        cv::Mat m; // Empty for now

        // Read header
        in.read((char *)(&rows), 4);
        if (0 == rows)
            return m;
        in.read((char *)(&cols), 4);
        in.read((char *)(&type), 4);

        m.create(rows, cols, type);
        // Read data
        in.read((char *)(m.data), m.elemSize()*m.total());

        if (!in)
            throw runtime_error("readMat() : Cannot read file " + fileName);

        return m;
    }
//======================================
    uint32_t hashMat(const cv::Mat & m) {
        size_t mSize = m.elemSize()*m.total();
        if (m.isContinuous())
            return  hashDJB2(m.data, mSize);
        else
            return  hashDJB2(m.clone().data, mSize);
    }
//======================================
    std::string infoStringMat(const cv::Mat & m){
        using namespace std;
        ostringstream oss;
        oss << m.cols << " " << m.rows << " " << m.channels() << " ";
        oss << m.depth() << " " << hashMat(m);

        return oss.str();
    }
//======================================

}