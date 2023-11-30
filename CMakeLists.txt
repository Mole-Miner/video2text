cmake_minimum_required(VERSION 3.15)
project(Video2Text)

add_executable(video2text src/main.cpp)

find_package(OpenCV REQUIRED)
MESSAGE(STATUS "OpenCV included dirs ${OpenCV_INCLUDE_DIRS}")
MESSAGE(STATUS "OpenCV linked libraries ${OpenCV_LIBS}")
target_link_libraries(video2text ${OpenCV_LIBS})
