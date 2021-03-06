//
// Created by edge on 2020/6/5.
//

#include "mysql_connection.h"
#include "mysql_driver.h"
#include "cppconn/statement.h"
#include "cppconn/resultset.h"
#include "cppconn/connection.h"
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <cstdio>

using namespace std;
using namespace sql;
using namespace sql::mysql;

void RunnConnectionMysql()
{
    mysql::MySQL_Driver *driver;
    Connection *conn;
    Statement *state;
    ResultSet *res;
    sql::PreparedStatement *prep_stmt;
    Savepoint *savept;

    driver = sql::mysql::get_driver_instance();
    conn = driver->connect("172.17.0.1:3306", "root", "123456");
    conn->setAutoCommit(0);
    state = conn->createStatement();
    // state->execute("use test");
    conn->setSchema("test");
    state->execute("create table if not exists tt (id int not null auto_increment, name varchar(20) not null, age int, primary key(id))");
    state->execute("delete from tt");
    state->execute("drop table tt");
    res = state->executeQuery("select * from user");

    ResultSetMetaData * metaData = res->getMetaData();
    int rows = (int)res->rowsCount();
    int cols = (int)metaData->getColumnCount();
    cout << "the cols num:" << cols << endl;
    cout << "the rows num:" << rows << endl;
    while(res->next())
    {
        string name = res->getString("name");
        int gender = res->getInt("gender");
        cout << name << " " <<gender <<endl;
    }

    //print column name and column type
    for(int i=0;i<cols; ++i)
    {
        cout << metaData->getColumnLabel(i+1) << " " << metaData->getColumnTypeName(i+1) << endl;

    }

    //print table name and database name
    cout << metaData->getTableName(1) << " : " << metaData->getSchemaName(1) << endl;

    //change the data of table
    prep_stmt = conn->prepareStatement("insert into user(name, sex, password) values(?, ?, ?)");
    prep_stmt->setString(1, "lala");
    prep_stmt->setInt(2, 24);
    prep_stmt->setString(3, "lala");
    int updatecount = prep_stmt->executeUpdate();

    //set save point
    savept = conn->setSavepoint("savept1");
    prep_stmt->setString(1, "hehe");
    prep_stmt->setInt(2, 2);
    prep_stmt->setString(3, "lala");
    updatecount = prep_stmt->executeUpdate();
    conn->rollback(savept);
    conn->releaseSavepoint(savept);
    conn->commit();

    delete res;
    delete state;
    delete prep_stmt;
    conn->close();
    delete conn;
}

int main(int argc, char *argv[])
{
    RunnConnectionMysql();
    getchar();
    return 0;
}