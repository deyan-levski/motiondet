cmake_minimum_required(VERSION 2.8)
project( primmotion )
find_package( OpenCV REQUIRED )
add_executable( primmotion primmotion.cpp )
target_link_libraries( primmotion ${OpenCV_LIBS} )

