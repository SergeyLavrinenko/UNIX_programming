cmake_minimum_required(VERSION 3.10)

project(shm_writer
  LANGUAGES CXX
  VERSION 1.0
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(shm_writer main.cpp)

install(TARGETS shm_writer
    COMPONENT linapp
    RUNTIME DESTINATION "/home/"
    LIBRARY DESTINATION "/home/"
    DESTINATION "/home/"
)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "AM") #required
INCLUDE(CPack)

