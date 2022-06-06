#include<iostream>
#pragma once

class Vehicle {
protected:
    int max_wheel_num;
    int max_wing_num;
    int wheel_num;
    int wing_num;
    void set_max_wheel_num(int a) { max_wheel_num = a; }
    void set_max_wing_num(int a) { max_wing_num = a; }
public:
    Vehicle() : max_wheel_num(0), max_wing_num(0), wheel_num(0), wing_num(0) {}
    virtual void run() {
        std::cout << "I am running" << std::endl;
    }
    void add_wing() { wing_num++; }
    void add_wheel() { wheel_num++; }
    bool finished() { return max_wheel_num == wheel_num && max_wing_num == wing_num; }
};