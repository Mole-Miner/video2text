#include "video.hpp"

cv::Mat video::live(const std::function<void(const cv::Mat&)> onFrame)
{
  cv::Mat frame;
  cv::VideoCapture videoCapture;
  const int deviceID = 0;
  const int apiID = cv::CAP_ANY;
  videoCapture.open(deviceID, apiID);
  if (!videoCapture.isOpened())
  {
    std::cerr << "Unable to open camera\n";
    std::exit(-1);
  }
  for (;;)
  {
    videoCapture.read(frame);
    if (frame.empty())
    {
      std::cerr << "Blank frame\n";
      break;
    }
    onFrame(frame);
    if (cv::waitKey(5) >= 0)
    {
      break;
    }
  }
  return frame;
}
