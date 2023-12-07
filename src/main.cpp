#include "filesystem"
#include "video/video.hpp"
#include "image/image.hpp"

int main(int argc, char** argv)
{
  const cv::String keys =
    "{help h usage ? || print this message   }"
    "{@video         || path to video for text detection}";
  cv::CommandLineParser parser(argc, argv, keys);
  parser.about("Video2text v1.0.0");

  if (parser.has("help"))
  {
    parser.printMessage();
    return 0;
  }

  cv::String videoPath = parser.get<cv::String>(0);

  if (!parser.check())
  {
    parser.printErrors();
    return 0;
  }

  printf("%s", videoPath.c_str());
  // cv::Mat frame;
  // video::liveCapture(frame);
  // image::detectContours(frame);
  // const std::string currentDir = std::filesystem::current_path().generic_string();
  // const std::string imgPath = currentDir + "/../images/small.jpg";
}
