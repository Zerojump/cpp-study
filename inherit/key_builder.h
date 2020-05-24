//
// Created by edge on 2020/5/19.
//

#ifndef INHERITPRAC_KEY_BUILDER_H
#define INHERITPRAC_KEY_BUILDER_H

#include <string>
using namespace std;

class key_builder {
private:
    string prefix;
public:
    const string &getPrefix() const;

    void setPrefix(const string &prefix);

public:
    key_builder(const string &prefix);

    key_builder();
};


#endif //INHERITPRAC_KEY_BUILDER_H
