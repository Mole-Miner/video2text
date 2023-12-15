#include <iostream>
#include <fstream>
#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>
#include "video/video.hpp"
#include "image/image.hpp"

int main(int argc, char** argv)
{
  // const cv::String keys =
  //   "{help h usage ? || print this message   }"
  //   "{@video         || path to video for text detection}";
  // cv::CommandLineParser parser(argc, argv, keys);
  // parser.about("Video2text v1.0.0");
  //
  // if (parser.has("help"))
  // {
  //   parser.printMessage();
  //   return 0;
  // }
  //
  // cv::String videoPath = parser.get<cv::String>(0);
  //
  // if (!parser.check())
  // {
  //   parser.printErrors();
  //   return 0;
  // }
  //
  // printf("%s", videoPath.c_str());
  cv::Mat frame;
  video::liveCapture(frame);
  std::vector<cv::Rect> contours = image::detectContours(frame);
  tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI;
  api->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
  std::ofstream vault("detected_text.txt");
  for (size_t i = 0; i < contours.size(); i++)
  {
    cv::Mat crop = frame(contours[i]);
    api->SetImage(crop.data, crop.cols, crop.rows, 3, crop.step);
    std::string outText = std::string(api->GetUTF8Text());
    vault << outText << std::endl;
  }
  api->End();
  delete api;
  vault.close();
}
