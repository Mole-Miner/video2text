add_library(image image.cpp)

target_include_directories(image INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(image PUBLIC ${OpenCV_LIBS} video2text_compiler_flags)
