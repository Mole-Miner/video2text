add_library(video video.cpp)

target_include_directories(video INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(video PUBLIC ${OpenCV_LIBS} video2text_compiler_flags)
