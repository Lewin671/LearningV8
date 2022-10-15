cmake_minimum_required(VERSION 3.20)
project(LearningV8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++14 -DV8_COMPRESS_POINTERS ")

# need to replace /path-of-v8/ with your own real v8 path
include_directories(/Volumes/EXCERIA-SATA-SSD/Code/v8/include)
include_directories(/Volumes/EXCERIA-SATA-SSD/Code/v8)
include_directories(/Volumes/EXCERIA-SATA-SSD/Code/v8/out/Default/gen)
include_directories(external-includes)
include_directories(src)

link_directories(libs)
link_libraries(
        libv8.dylib
        libv8_libbase.dylib
        libv8_libplatform.dylib
        libgmock.1.12.1.dylib
        libgmock_main.1.12.1.dylib
        libgtest.1.12.1.dylib
        libgtest_main.1.12.1.dylib
)


add_executable(LearningV8 src/main.cpp)
add_executable(test src/object_test.cpp)

