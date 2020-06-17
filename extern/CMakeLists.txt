project(EXTERN)
message("-- ${PROJECT_NAME} build in " ${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(extern ex.cpp in.cpp)
ADD_EXECUTABLE(ifstream main.cpp)
#TARGET_LINK_LIBRARIES(extern gtest gtest_main pthreadhread)