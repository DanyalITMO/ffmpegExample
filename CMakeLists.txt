cmake_minimum_required(VERSION 3.9)
project(ffmpegExamples)
set(CMAKE_CXX_STANDARD 17)


#find_package(FFmpeg COMPONENTS AVCODEC AVFORMAT AVUTIL AVDEVICE REQUIRED)
add_executable(ffmpegExamples main.cpp)
#target_link_libraries(ffmpegExamples ${FFMPEG_LIBRARIES})
target_link_libraries(ffmpegExamples avcodec avformat)

#target_compile_definitions(-lavformat -lavcodec -lavutil -lavfilter -lswscale)