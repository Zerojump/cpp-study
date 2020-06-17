//
// Created by edgechen on 2020/6/17.
//
#include <string>
#include "key_builder.h"
int main() {
    key_builder k;
    long l = 4;
    string lstr = k.convertToString(l);
    printf("l:%s", lstr.c_str());
}