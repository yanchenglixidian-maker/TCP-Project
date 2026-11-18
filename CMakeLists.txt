cmake_minimum_required(VERSION 3.16)
project(net_server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(net_server src/main.cpp src/common/log.cpp src/server/server.cpp)

target_include_directories(net_server PRIVATE src)
