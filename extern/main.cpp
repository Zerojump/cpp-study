//
// Created by edgechen on 2020/5/28.
//
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream conf("/opt/f_/code.d/cpp/cpp-study/extern/ex.cpp", ios::in);
    if (!conf) {
        cerr << "Can't open config file: preupload.conf" << endl;
        return -1;
    } else {
        cout << "get" << endl;
    }
}
