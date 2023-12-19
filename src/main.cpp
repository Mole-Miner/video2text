#include <fstream>
#include <filesystem>
#include "video/video.hpp"
#include "image/image.hpp"
#include "ocr/ocr.hpp"

int main(int argc, char** argv)
{
  const auto onFrame = [](const cv::Mat& frame)
  {
    const cv::Mat frameClone = frame.clone();
    const std::vector<cv::Rect> contours = image::findContours(frameClone);
    image::renderContours(frameClone, contours);
    cv::imshow("Frame", frameClone);
  };
  const cv::Mat frame = video::live(onFrame);
  const std::vector<cv::Rect> contours = image::findContours(frame);
  const std::string outputName = "found_text.txt";
  const std::string outputPath = std::filesystem::current_path().generic_string() + outputName;
  std::filesystem::remove(outputPath);
  std::ofstream output(outputName);
  for (const auto& contour : contours)
  {
    const cv::Mat roi = frame(contour);
    const std::string text = ocr::findText(roi);
    output << text << std::endl;
  }
}
