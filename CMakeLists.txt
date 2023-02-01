cmake_minimum_required(VERSION 3.24)
project(Study)

set(CMAKE_CXX_STANDARD 17)

set(EasyX_DIR F:/easyx4mingw) # 指定下载的easyx4mingw位置
include_directories(${EasyX_DIR}/include)
link_directories(${EasyX_DIR}/lib64) # 如果是32位系统，则使用lib32

link_libraries(libEasyX.a libgdi32.a libole32.a) # 链接EasyX库

add_executable(Study AirPlay.h mainT6.cpp List.h)
#add_executable(Study AirPlay.h main.cpp List.h)
