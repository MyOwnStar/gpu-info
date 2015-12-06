cmake_minimum_required(VERSION 2.8)
project(qt_test_project)

include(FindCUDA)
include_directories(/usr/local/cuda-6.5/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

find_package(Qt5Widgets)
find_package(CUDA)

#add_executable(qt_test_project ${SOURCE_FILES})
cuda_add_executable(qt_test_project ${SOURCE_FILES})

target_link_libraries(qt_test_project Qt5::Widgets)

list(APPEND CUDA_NVCC_FLAGS --compiler-options -fno-strict-aliasing
                             -lineinfo -use_fast_math -Xptxas -dlcm=cg)
list(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_11,code=sm_11)
