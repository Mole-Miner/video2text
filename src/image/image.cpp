#include "image.hpp"

IOD::IOD()
{
    std::cout << "Iod constructor" << std::endl;
}

IOD::~IOD()
{
    std::cout << "Iod deconstructor" << std::endl;
}

std::vector<cv::Rect> IOD::getContours(const std::string& imagePath)
{
    cv::Mat originalImage = cv::imread(imagePath);
    std::vector<cv::Rect> boundPoint;
    return boundPoint;
}
