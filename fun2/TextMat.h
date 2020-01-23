//
// Created by Oleksiy Grechnyev on 5/24/18.
//

#pragma once

#include <string>

#include <opencv2/core.hpp>

namespace algorithms {
    /// Print cv-mat as txt (with no size tags)
    void PrintToTxt_uchar(std::string name, cv::Mat mat);

    /// Read cv-mat from txt (for a given size)
    cv::Mat ReadMatFromTxt_uchar(std::string filename, int rows, int cols);

    /// Write opencv matrix to a binary file
    void writeMat(const cv::Mat & m, const std::string & fileName);

    /// Read opencv matrix from a binary file
    cv::Mat readMat(const std::string & fileName);

    /// A simple hash function
    uint32_t hashDJB2(const void * buf, size_t bufSize);

    /// Hash OpenCV matrix data
    uint32_t hashMat(const cv::Mat & m);

    /// Matrix info string (size + depth +  type + hash)
    std::string infoStringMat(const cv::Mat & m);
}