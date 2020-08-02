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
#include <unistd.h>

using namespace std;

TEST(MySQLTest, SimpleQuery) {
    const char *db = 0, *server = 0, *user = 0, *password = "";
    db = "test";
    server = "172.17.0.1";
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

    mysqlpp::Connection conn(true);
    if (conn.connect(db, server, user, password)) {

        try {
            // conn.disconnect();
            printf("sleep %d\n", time(NULL));
            sleep(5);
            printf("%d\n", time(NULL));

            cout << "connect db succeed. " << endl;
            mysqlpp::Query query = conn.query("SELECT a FROM city1");
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
        } catch (mysqlpp::BadQuery &e) {
            printf("catch mysqlpp::BadQuery(%d) %s %s\n", e.errnum(), e.what(), typeid(e).name());

        } catch (mysqlpp::Exception &e) {
            printf("catch mysqlpp::Exception(%s) %s\n", e.what(), typeid(e).name());
        } catch (std::exception &e) {
            printf("catch exception\n");
            cout << e.what() << endl;
        }


    } else {
        cout << "connect db fail. " << endl;
    }
}

TEST(MySQLTest, Update) {
    const char *db = 0, *server = 0, *user = 0, *password = "";
    db = "test";
    server = "172.17.0.1";
    user = "root";
    password = "123456";

    mysqlpp::Connection conn(false);
    if (conn.connect(db, server, user, password)) {
        cout << "connect db succeed. " << endl;
        mysqlpp::Query query = conn.query("update city set cname = %2q where id = %1 and cname = %0q;"
                                          "insert into city(cname) values ('ck);");
        query.parse();
        mysqlpp::SimpleResult res = query.execute("sz", "1", "sad");

        // mysqlpp::Query query = conn.query("SELECT * FROM city");
        // mysqlpp::StoreQueryResult res = query.store();
        printf("rows affected:%lu\n", res.rows());
    } else {
        cout << "connect db fail. " << endl;
    }
}

TEST(MySQLTest, Insert) {
    const char *db = 0, *server = 0, *user = 0, *password = "";
    db = "test";
    server = "172.17.0.1";
    user = "root";
    password = "123456";

    mysqlpp::Connection conn(false);
    if (conn.connect(db, server, user, password)) {
        cout << "connect db succeed. " << endl;
        mysqlpp::Query query = conn.query("insert into city(cname) values ('ck')");
        // query.parse();
        mysqlpp::SimpleResult res = query.execute();

        // mysqlpp::Query query = conn.query("SELECT * FROM city");
        // mysqlpp::StoreQueryResult res = query.store();
        printf("rows affected:%lu\n", res.rows());
    } else {
        cout << "connect db fail. " << endl;
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);    //  初始化gtest
    return RUN_ALL_TESTS();                    //  运行所有测试用例
}