//
// Created by edge on 2020/5/18.
//

#include "scheduler_save.h"

scheduler_save::scheduler_save() : id(0) {

}

scheduler_save::~scheduler_save() {

}

int scheduler_save::get_id() {
    return this->id;
}

void scheduler_save::set_id(int id) {
    this->id = id;
}

const key_builder &scheduler_save::getKb() const {
    return kb;
}

void scheduler_save::setKb(const key_builder &kb) {
    scheduler_save::kb = kb;
}

const string &scheduler_exec::getName() const {
    return name;
}

void scheduler_exec::setName(const string &name) {
    scheduler_exec::name = name;
}

scheduler_exec::scheduler_exec(const string &name) : name(name) {}

scheduler_exec::~scheduler_exec() {

}
