cmake_minimum_required(VERSION 3.16)
project(WebviewExample)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(WEBKIT2GTK REQUIRED webkit2gtk-4.0)

add_executable(webview_example main.cc)

target_include_directories(webview_example PRIVATE 
    ${GTK3_INCLUDE_DIRS} 
    ${WEBKIT2GTK_INCLUDE_DIRS}
)

target_link_libraries(webview_example 
    ${GTK3_LIBRARIES} 
    ${WEBKIT2GTK_LIBRARIES}
    pthread
)

target_compile_options(webview_example PRIVATE 
    ${GTK3_CFLAGS_OTHER} 
    ${WEBKIT2GTK_CFLAGS_OTHER}
)
