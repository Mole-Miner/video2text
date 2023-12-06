#include "video.hpp"

void video::liveCapture(cv::Mat& frame)
{
  cv::Mat fgMask;
  cv::VideoCapture videoCapture;
  cv::Ptr<cv::BackgroundSubtractor> pBackSub = cv::createBackgroundSubtractorMOG2();
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
    // pBackSub->apply(frame, fgMask);
    // cv::rectangle(frame, cv::Point(10, 2), cv::Point(100, 20), cv::Scalar(255, 255, 255), -1);
    // std::stringstream ss;
    // ss << videoCapture.get(cv::CAP_PROP_POS_FRAMES);
    // std::string frameNumber = ss.str();
    // cv::putText(frame, frameNumber.c_str(), cv::Point(15, 15), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
    // cv::imshow("Frame", frame);
    const std::vector<cv::Rect> bound = image::detectContours(frame);
    image::renderContours(frame, bound);
    cv::imshow("Frame", frame);
    // cv::imshow("FG Mask", fgMask);
    if (cv::waitKey(5) >= 0)
    {
      break;
    }
  }
}
