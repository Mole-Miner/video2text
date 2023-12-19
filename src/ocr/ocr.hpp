#include <string>
#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>
#include <opencv2/imgproc.hpp>

namespace ocr
{
    std::string findText(const cv::Mat&);
}
