cmake_minimum_required(VERSION 2.8)
project(main)
find_package( OpenCV REQUIRED )

find_package(PkgConfig REQUIRED)


include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(main 
    "main.cpp")

target_link_libraries( main ${OpenCV_LIBS})