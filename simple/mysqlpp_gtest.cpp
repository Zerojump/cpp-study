//
// Created by edge on 2020/6/5.
//
#include <mysql++/mysql++.h>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
    const char *db = 0, *server = 0, *user = 0, *password = "";
    db = "test";
    server = "172.17.0.1";
    user = "root";
    password = "123456";

    mysqlpp::Connection conn(false);
    if (conn.connect(db, server, user, password)) {
        cout << "connect db succeed. " << endl;
        mysqlpp::Query query = conn.query("SELECT * FROM city");
        if (mysqlpp::StoreQueryResult res = query.store()) {
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
    return 0;
}
