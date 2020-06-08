set(CMAKE_CXX_STANDARD 11)

project(SIMPLE)
message("-- ${PROJECT_NAME} build in " ${CMAKE_CURRENT_BINARY_DIR})

set(GTEST_HOME /opt/f_/import/cpp/googletest)
INCLUDE_DIRECTORIES(${GTEST_HOME}/include)
LINK_DIRECTORIES(${GTEST_HOME}/build/lib) # 如果不加这项配置,则TARGET_LINK_LIBRARIES里的库需使用绝对路径
#LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/lib)
ADD_EXECUTABLE(simple simple_gtest.cpp)
TARGET_LINK_LIBRARIES(simple gtest gtest_main pthread)

set(ACL_HOME /opt/f_/import/cpp/acl)
INCLUDE_DIRECTORIES(${ACL_HOME}/lib_acl_cpp/include ${ACL_HOME}/lib_acl/include ${ACL_HOME}/lib_protocol/include)
LINK_DIRECTORIES(${ACL_HOME})
ADD_EXECUTABLE(redis redis_gtest.cpp)
TARGET_LINK_LIBRARIES(redis gtest gtest_main pthread acl_all)

set(MYSQL_CONNECTOR_HOME /opt/f_/import/cpp/mysql-connector-c++)
INCLUDE_DIRECTORIES(${MYSQL_CONNECTOR_HOME}/include/jdbc)
LINK_DIRECTORIES(${MYSQL_CONNECTOR_HOME}/lib64)
ADD_EXECUTABLE(mysql mysql_gtest.cpp)
TARGET_LINK_LIBRARIES(mysql gtest gtest_main pthread dl resolv ssl crypto mysqlcppconn-static mysqlcppconn8-static mysqlcppconn8 mysqlcppconn)

ADD_EXECUTABLE(mysql_conn mysql_connector_cpp.cpp)
TARGET_LINK_LIBRARIES(mysql_conn gtest gtest_main pthread dl resolv ssl crypto mysqlcppconn-static mysqlcppconn8-static mysqlcppconn8 mysqlcppconn)

set(MYSQLPP_HOME /opt/f_/import/cpp/mysql++)
INCLUDE_DIRECTORIES(${MYSQLPP_HOME}/include /usr/include/mysql)
LINK_DIRECTORIES(${MYSQLPP_HOME}/lib)
ADD_EXECUTABLE(mysqlpp_test mysqlpp_gtest.cpp)
TARGET_LINK_LIBRARIES(mysqlpp_test gtest gtest_main pthread mysqlpp)
