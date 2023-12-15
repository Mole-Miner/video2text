#include "image.hpp"

void image::renderContoursExt(const cv::Mat& frame, const std::vector<std::vector<cv::Rect>>& contours)
{
  for (size_t i = 0; i < contours.size(); i++)
  {
    const cv::Rect rect = cv::boundingRect(contours[i]);
    cv::rectangle(frame, rect, cv::Scalar(0, 255, 0), 3, 8, 0);
  }
}

void image::renderContours(const cv::Mat& frame, const std::vector<cv::Rect>& bound)
{
  for (size_t i = 0; i < bound.size(); i++)
  {
    cv::rectangle(frame, bound[i], cv::Scalar(0, 255, 0), 3, 8, 0);
  }
}

std::vector<std::vector<cv::Rect>> image::detectContoursExt(const cv::Mat& frame)
{
  cv::Mat gray, threshold, kernel, dilation;
  std::vector<std::vector<cv::Rect>> contours;
  cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
  cv::threshold(gray, threshold, 0, 255, cv::THRESH_OTSU | cv::THRESH_BINARY_INV);
  kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(15, 3));
  cv::dilate(threshold, dilation, kernel);
  cv::findContours(dilation, contours, 0, 1);
  return contours;
}

std::vector<cv::Rect> image::detectContours(const cv::Mat& frame)
{
  cv::Mat gray, sobel, threshold, kernel;
  cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
  cv::Sobel(gray, sobel, CV_8U, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT);
  cv::threshold(sobel, threshold, 0, 255, cv::THRESH_OTSU + cv::THRESH_BINARY);
  kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(15, 3));
  cv::morphologyEx(threshold, threshold, cv::MORPH_CLOSE, kernel);
  std::vector<std::vector<cv::Point>> contours;
  cv::findContours(threshold, contours, 0, 1);
  std::vector<std::vector<cv::Point>> contoursPoly(contours.size());
  std::vector<cv::Rect> bound;
  for (size_t i = 0; i < contours.size(); i++)
  {
    if (contours[i].size() > 100)
    {
      cv::approxPolyDP(cv::Mat(contours[i]), contoursPoly[i], 3, true);
      cv::Rect approxy(cv::boundingRect(cv::Mat(contoursPoly[i])));
      if (approxy.width > approxy.height)
      {
        bound.push_back(approxy);
      }
    }
  }
  return bound;
}

