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
  std::vector<cv::Rect> contours = image::findContours(frame);
  const std::string outputPath = std::filesystem::current_path().generic_string() + "/found_text.txt";
  std::filesystem::remove(outputPath);
  std::ofstream output(outputPath);
  for (std::vector<cv::Rect>::reverse_iterator i = contours.rbegin(); i != contours.rend(); ++i)
  {
    const cv::Mat roi = frame(*i);
    const std::string text = ocr::findText(roi);
    output << text << std::endl;
  }
  output.close();
}
