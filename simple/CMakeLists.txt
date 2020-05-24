set(CMAKE_CXX_STANDARD 11)

project(SIMPLE)
message("-- ${PROJECT_NAME} build in " ${CMAKE_CURRENT_BINARY_DIR})

set(GTEST_HOME /f_/import/cpp/googletest)
INCLUDE_DIRECTORIES(${GTEST_HOME}/include)
LINK_DIRECTORIES(${GTEST_HOME}/build/lib) # 如果不加这项配置,则TARGET_LINK_LIBRARIES里的库需使用绝对路径
#LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/lib)

ADD_EXECUTABLE(simple simple_gtest.cpp)
TARGET_LINK_LIBRARIES(simple gtest gtest_main pthread)
