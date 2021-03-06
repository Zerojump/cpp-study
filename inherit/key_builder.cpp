//
// Created by edge on 2020/5/19.
//

#include "key_builder.h"

key_builder::key_builder(const string &prefix) : prefix(prefix) {}

const string &key_builder::getPrefix() const {
    return prefix;
}

void key_builder::setPrefix(const string &prefix) {
    key_builder::prefix = prefix;
}

template<class T>
string key_builder::convertToString(const T val)
{
    string s;
    std::strstream ss;
    ss << val;
    ss >> s;
    return s;
}


key_builder::key_builder() {}
