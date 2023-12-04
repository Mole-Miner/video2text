#include "filesystem"
#include "video/video.hpp"
#include "image/image.hpp"

int main(void)
{
  video::liveCapture();
  // const std::string currentDir = std::filesystem::current_path().generic_string();
  // const std::string imgPath = currentDir + "/../images/small.jpg";
  //
  // std::cout << imgPath << std::endl;
  //
  // test();
  //
  // IOD iod;
  // const auto contours = iod.getContours(imgPath);
  //
  // for (auto& contour : contours)
  // {
  //   std::cout << contour.area() << std::endl;
  // }
}
