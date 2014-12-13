cmake_minimum_required(VERSION 2.8)
project( 2rowanamotion )
find_package( OpenCV REQUIRED )
add_executable( 2rowanamotion 2rowanamotion.cpp )
target_link_libraries( 2rowanamotion ${OpenCV_LIBS} )

