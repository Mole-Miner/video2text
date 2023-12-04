cmake_minimum_required(VERSION 3.15...3.28)
project(Video2Text VERSION 1.0)

add_library(video2text_compiler_flags INTERFACE)
target_compile_features(video2text_compiler_flags INTERFACE cxx_std_11)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(video2text_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
MESSAGE(STATUS "OpenCV included dirs ${OpenCV_INCLUDE_DIRS}")
MESSAGE(STATUS "OpenCV linked libraries ${OpenCV_LIBS}")

add_subdirectory(video)
add_subdirectory(image)

add_executable(video2text main.cpp)

target_link_libraries(video2text PUBLIC video image video2text_compiler_flags)

target_include_directories(video2text PUBLIC ${PROJECT_BINARY_DIR})
