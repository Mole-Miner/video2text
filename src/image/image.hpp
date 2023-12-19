#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

namespace image
{
  std::vector<cv::Rect> findContours(const cv::Mat&);
  void renderContours(const cv::Mat&, const std::vector<cv::Rect>&);
}
