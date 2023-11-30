#include "opencv2/opencv.hpp"
#include "filesystem"
#include "string"
#include "iostream"

int main()
{
  const std::string currentDir = std::filesystem::current_path().generic_string();
  const std::string imgPath = currentDir + "/images/small.jpg";
  if (!cv::haveImageReader(imgPath))
  {
    std::cout << "Cannot read image" << std::endl;
  }
  cv::Mat img = cv::imread(imgPath);
  cv::Mat grayImg;
  cv::cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);
  cv::Mat sobelImg;
  cv::Sobel(grayImg, sobelImg, CV_8U, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT);
  cv::Mat thresholdImg;
  cv::threshold(sobelImg, thresholdImg, 0, 255, cv::THRESH_OTSU + cv::THRESH_BINARY);
  cv::Mat rectKernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(10, 5));
  cv::morphologyEx(thresholdImg, thresholdImg, cv::MORPH_CLOSE, rectKernel);
  std::vector<std::vector<cv::Point>> contours;
  cv::findContours(thresholdImg, contours, 0, 1);
  std::vector<std::vector<cv::Point>> contoursPoly(contours.size());
  std::vector<cv::Rect> boundRect;
  for (int i = 0; i < contours.size(); i++)
  {
    if (contours[i].size() > 100)
    {
      cv::approxPolyDP(cv::Mat(contours[i]), contoursPoly[i], 3, true);
      cv::Rect appRect(cv::boundingRect(cv::Mat(contoursPoly[i])));
      if (appRect.width > appRect.height)
      {
        boundRect.push_back(appRect);
      }
    }
  }
  for (int i = 0; i < boundRect.size(); i++)
  {
    cv::rectangle(img, boundRect[i], cv::Scalar(0, 255, 0), 3, 8, 0);
  }
  cv::imwrite(currentDir + "/images/small_output.jpg", img);
}
