message("Starting build...")
cmake_minimum_required(VERSION 3.0)
project(Pomodoro)
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
add_subdirectory(src) 

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -W -Werror -pedantic")
