#pragma once
#include "Pair.h"

class Map{
    Pair * data;
    int sz;
public:
    Map(int n);
    ~Map();
    int& operator[] (const string);
    int operator[] (const string) const;
    int size();
    // TODO
};