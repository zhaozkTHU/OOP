#pragma once

#include "func.h"

class CompFunc : public Func{
private:
    Func *_outer, *_inner;
public:
    CompFunc(Func *outer, Func* inner) : _outer(outer), _inner(inner) {}
    double getPoint(double point) override {
        return _outer->getPoint(_inner->getPoint(point));
    }
    ~CompFunc() {
        delete _outer;
        delete _inner;
    }
    // compute f(g(x))
    // Todo
    // 请参照指数函数类(ExpFunc)实现一个复合函数类
    // 并且要求，传入的参数的析构在该类被析构时同时析构
};