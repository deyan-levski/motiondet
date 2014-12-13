cmake_minimum_required(VERSION 2.8)
project( Bkgsubt )
find_package( OpenCV REQUIRED )
add_executable( Bkgsubt bkgsubt.cpp )
target_link_libraries( Bkgsubt ${OpenCV_LIBS} )

