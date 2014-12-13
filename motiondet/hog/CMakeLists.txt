cmake_minimum_required(VERSION 2.8)
project( HOGMotion )
find_package( OpenCV REQUIRED )
add_executable( HOGMotion main.cpp )
target_link_libraries( HOGMotion ${OpenCV_LIBS} )

