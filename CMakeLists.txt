cmake_minimum_required(VERSION 3.20)
project(LearningV8)

set(CMAKE_CXX_STANDARD 14)

# need to replace /path-of-v8/ with your own real v8 path
include_directories(/path-of-v8/)
include_directories(/path-of-v8/include)

link_directories(libs)

link_libraries(
        libc++.dylib
        libchrome_zlib.dylib
        libv8.dylib
        libv8_libbase.dylib
        libv8_libplatform.dylib
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++14 -DV8_COMPRESS_POINTERS ")

add_executable(LearningV8 main.cpp main.cpp)
