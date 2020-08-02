//
// Created by edge on 2020/5/24.
//

#include <gtest/gtest.h>
#include <iostream>
#include <bitset>

using namespace std;

// 单元测试
TEST(FunTest, HandlesZeroInput) {
    // bool值检查
    // 1>、 ASSERT_TRUE(参数)，期待结果是true
    // 2>、ASSERT_FALSE(参数)，期待结果是false
    // 数值型数据检查
    // 3>、ASSERT_EQ(参数1，参数2)，传入的是需要比较的两个数  equal
    // 4>、ASSERT_NE(参数1，参数2)，not equal，不等于才返回true
    // 5>、ASSERT_LT(参数1，参数2)，less than，小于才返回true
    // 6>、ASSERT_GT(参数1，参数2)，greater than，大于才返回true
    // 7>、ASSERT_LE(参数1，参数2)，less equal，小于等于才返回true
    // 8>、ASSERT_GE(参数1，参数2)，greater equal，大于等于才返回true
    // 字符串检查
    // 9>、ASSERT_STREQ(expected_str, actual_str)，两个C风格的字符串相等才正确返回
    // 10>、ASSERT_STRNE(str1, str2)，两个C风格的字符串不相等时才正确返回
    // 11>、ASSERT_STRCASEEQ(expected_str, actual_str)
    // 12>、ASSERT_STRCASENE(str1, str2)
    // 13>、EXPECT_系列，也是具有类似的宏结构的
    printf("hello gtest");
}

TEST(FunTest, Hex2Bin) {
    string binary = "08FDD3C9B2AC2E";
    bitset<8> bit(stoi(binary, nullptr, 16));
    cout << bit << endl;
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);    // 初始化gtest
    return RUN_ALL_TESTS();                    // 运行所有测试用例
}
