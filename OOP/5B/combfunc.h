#pragma once

#include "func.h"

class CombFunc : public Func{
private:
    Func *_func_1, *_func_2;
    double _coe_1, _coe_2;
public:
    CombFunc(Func *fun_1, Func *fun_2, double coe_1, double coe_2) : _func_1(fun_1), _func_2(fun_2), _coe_1(coe_1), _coe_2(coe_2) {}
    double getPoint(double point) override {
        return _coe_1 * _func_1->getPoint(point) + _coe_2 * _func_2->getPoint(point);
    }
    ~CombFunc() {
        delete _func_1;
        delete _func_2;
    }
    // compute a * f(x) + b * g(x)
    // Todo
    // 请参照指数函数类(ExpFunc)实现一个组合函数类
    // 并且要求，传入的参数的析构在该类被析构时同时析构
};