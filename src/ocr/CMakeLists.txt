add_library(ocr ocr.cpp)

target_include_directories(ocr INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ocr PUBLIC ${OpenCV_LIBS} tesseract lept video2text_compiler_flags)
