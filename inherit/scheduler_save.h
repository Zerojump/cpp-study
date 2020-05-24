//
// Created by edge on 2020/5/18.
//

#ifndef INHERITPRAC_SCHEDULER_SAVE_H
#define INHERITPRAC_SCHEDULER_SAVE_H

#include <iostream>
#include <string>
#include "key_builder.h"

using namespace std;

class scheduler_save {
public:
    scheduler_save();
    ~scheduler_save();

protected:
    int get_id();
    void set_id(int id);

    virtual void plus_id(int id) = 0;

    int id;
    key_builder kb;
public:
    const key_builder &getKb() const;

    void setKb(const key_builder &kb);
};

class scheduler_exec{
public:
    scheduler_exec(const string &name);

    virtual ~scheduler_exec();

protected:
    string name;

public:
    const string &getName() const;

    void setName(const string &name);
};

#endif //INHERITPRAC_SCHEDULER_SAVE_H
