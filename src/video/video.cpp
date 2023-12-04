#include "video.hpp"

void video::liveCapture()
{
  cv::Mat frame;
  cv::Mat fgMask;
  cv::VideoCapture videoCapture;
  cv::Ptr<cv::BackgroundSubtractor> pBackSub = cv::createBackgroundSubtractorMOG2();
  const int deviceID = 0;
  const int apiID = cv::CAP_ANY;
  int counter = -1;

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
    counter++;

    cv::imshow("Live", frame);
    if (cv::waitKey(5) >= 0)
    {
      break;
    }
  }
}
