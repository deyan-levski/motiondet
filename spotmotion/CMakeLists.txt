cmake_minimum_required(VERSION 2.8)
project( spotmotion )
find_package( OpenCV REQUIRED )
add_executable( spotmotion spotmotion.cpp )
target_link_libraries( spotmotion ${OpenCV_LIBS} )

