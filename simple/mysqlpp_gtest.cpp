//
// Created by edge on 2020/6/5.
// https://www.jianshu.com/p/efdafe4322b9
// https://tangentsoft.com/mysqlpp/home
//
#include <mysql++/mysql++.h>
#include <mysql++/ssqls.h>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <mysql.h>

using namespace std;

TEST(MySQLTest, SimpleQuery) {
    const char *db = 0, *server = 0, *user = 0, *password = "";
    db = "test";
    server = ""
             ""
             ""
             "";
    user = "root";
    password = "123456";

    mysqlpp::Connection conn(false);
    if (conn.connect(db, server, user, password)) {
        cout << "connect db succeed. " << endl;
        mysqlpp::Query query = conn.query("SELECT * FROM city where id = %1 and cname = %0q");
        query.parse();
        mysqlpp::StoreQueryResult res = query.store("sz", "1");

        // mysqlpp::Query query = conn.query("SELECT * FROM city");
        // mysqlpp::StoreQueryResult res = query.store();
        if (res) {
            cout.setf(ios::left);
            cout << setw(10) << "id" <<
                 setw(10) << "cname" << endl;

            mysqlpp::StoreQueryResult::const_iterator it;
            for (it = res.begin(); it != res.end(); ++it) {
                mysqlpp::Row row = *it;
                cout << setw(30) << row[0] << ' ' <<
                     setw(9) << row[1] << ' ' <<
                     endl;
            }
        }
    } else {
        cout << "connect db fail. " << endl;
    }
}

typedef struct __city {
    uint32_t id;
    string cname;
} city;

TEST(MySQLTest, STLQuery) {
    const char *db = 0, *server = 0, *user = 0, *password = "";
    db = "test";
    server = "172.17.0.1";
    user = "root";
    password = "123456";

    mysqlpp::Connection conn(false);
    if (conn.connect(db, server, user, password)) {
        cout << "connect db succeed. " << endl;
        mysqlpp::Query query = conn.query("SELECT * FROM city");
        vector<mysqlpp::Row> rows;
        query.storein(rows);
        int count(0);
        for (auto &citie : rows) {
            int id = (int) citie.at(0);
            string cname = (string) citie.at(1);
            printf("%d,%s\n", id, cname.c_str());
            count += id;
        }
        printf("count:%d\n", count);
    } else {
        cout << "connect db fail. " << endl;
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);    //  初始化gtest
    return RUN_ALL_TESTS();                    //  运行所有测试用例
}