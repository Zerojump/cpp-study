// 
//  Created by edge on 2020/5/28.
// 
#include <gtest/gtest.h>
#include <iostream>
#include "acl_cpp/lib_acl.hpp"

using namespace std;

TEST(RedisTest, Cmd_STR) {
    acl::redis_string cmd_string;  // redis中的string类型

    acl::redis_client_cluster cluster;
    const char *redis_addr = "127.0.0.1:6379";  // 设置连接的数据库地址

    int conn_timeout = 10;  // 连接redis-server的超时时间（秒）
    int rw_timeout = 10;  // 与redis-server进行通信IO的超时时间（秒）
    int max_threads = 100;  // 最大线程线程数
    cluster.set(redis_addr, max_threads, conn_timeout, rw_timeout);
    acl::redis_client conn(redis_addr, conn_timeout, rw_timeout);  // 设置连接的客户端

    cmd_string.set_client(&conn);  // 设置该string类型是连接那个客户端
    acl::redis_string string_cmd(&conn);  // 使用初始化一个string

    const char *key = "name";
    if (string_cmd.set(key, "Shayne") == false)  // 设置一个string 类型的key value
    {
        const acl::redis_result *res = string_cmd.get_result();
        cout << "name " << res << endl;
    } else {
        cout << "connected" << endl;
        printf("set key: %s ok\r\n", key);
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);    //  初始化gtest
    return RUN_ALL_TESTS();                    //  运行所有测试用例
}