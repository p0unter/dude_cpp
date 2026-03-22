cmake_minimum_required(VERSION 3.10)
project(detect_vid VERSION 0.1.0)

find_package(OpenCV REQUIRED COMPONENTS core imgproc imgcodecs highgui dnn videoio)
find_package(Threads REQUIRED)

add_executable(detect_vid detect_vid.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_link_libraries(detect_vid
    ${OpenCV_LIBS}
    ${CMAKE_THREAD_LIBS_INIT}
)
