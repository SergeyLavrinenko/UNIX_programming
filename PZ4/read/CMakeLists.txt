cmake_minimum_required(VERSION 3.10)

project(shm_reader
  LANGUAGES CXX
  VERSION 1.0
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(shm_reader main.cpp)

install(TARGETS shm_reader
    COMPONENT linapp
    RUNTIME DESTINATION "/home/"
    LIBRARY DESTINATION "/home/"
    DESTINATION "/home/"
)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "AM") #required
INCLUDE(CPack)

