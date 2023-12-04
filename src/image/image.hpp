#include <opencv2/opencv.hpp>
#include <string>
#include "iostream"

class IOD
{
public:
    IOD();
    ~IOD();
    std::vector<cv::Rect> getContours(const std::string&);
};
