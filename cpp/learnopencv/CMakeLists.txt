cmake_minimum_required(VERSION 2.6)

project(learnopencv)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(learnopencv main.cpp)

install(TARGETS learnopencv RUNTIME DESTINATION bin)

target_link_libraries(learnopencv ${OpenCV_LIBS})
