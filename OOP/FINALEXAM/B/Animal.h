#pragma once

class Animal {
public:
    Animal() {}
    int color;
    virtual void swim() {}
    virtual void sing() {}
    virtual ~Animal() {}
};