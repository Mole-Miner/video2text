#include <opencv2/opencv.hpp>
#include <string>
#include "iostream"

namespace image
{
  std::vector<cv::Rect> detectContours(const cv::Mat&);
  void renderContours(const cv::Mat&, const std::vector<cv::Rect>&);
}
