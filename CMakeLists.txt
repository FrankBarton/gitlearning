set(CMAKE_BUILD_TYPE "Debug")

cmake_minimum_required(VERSION 2.8)

#project(learnSophus)

add_executable(learnSophus learnSophus.cpp)

include_directories("/usr/include/eigen3")

find_package(Sophus REQUIRED)
include_directories(${Sophus_INCLUDE_DIRS})

target_link_libraries(learnSophus ${Sophus_LIBRARIES})

