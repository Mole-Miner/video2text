#include <iostream>
#include <functional>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui.hpp>
#include "../image/image.hpp"

namespace video
{
  cv::Mat live(std::function<void(const cv::Mat&)>);
}
