cmake_minimum_required(VERSION 2.8)
project( Motion )
find_package( OpenCV REQUIRED )
add_executable( Motion motion.cpp )
target_link_libraries( Motion ${OpenCV_LIBS} )

