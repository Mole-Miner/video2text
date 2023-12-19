#include "ocr.hpp"

std::string ocr::findText(const cv::Mat& img)
{
  tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI;
  api->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
  api->SetImage(img.data, img.cols, img.rows, 3, img.step);
  std::string text = std::string(api->GetUTF8Text());
  api->End();
  delete api;
  return text;
}
