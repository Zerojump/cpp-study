cmake_minimum_required(VERSION 3.9)
SET(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})
message("-- install dir " ${CMAKE_INSTALL_PREFIX})
#将它作为命令行参数传递：
#cmake -DCMAKE_INSTALL_PREFIX=< install_path > ..
#为其分配值CMakeLists.txt：
#SET(CMAKE_INSTALL_PREFIX < install_path >)
#但要记得在 PROJECT(< project_name>)命令前放置它，否则它将无法工作！

PROJECT(CPP_STUDY)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(simple)
add_subdirectory(inherit)

# 指定可执行文件的生成位置
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")