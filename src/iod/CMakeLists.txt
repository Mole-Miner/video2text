add_library(iod iod.cpp)

target_include_directories(iod INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

find_package(OpenCV REQUIRED)
MESSAGE(STATUS "OpenCV included dirs ${OpenCV_INCLUDE_DIRS}")
MESSAGE(STATUS "OpenCV linked libraries ${OpenCV_LIBS}")

target_link_libraries(iod PUBLIC ${OpenCV_LIBS} video2text_compiler_flags)
