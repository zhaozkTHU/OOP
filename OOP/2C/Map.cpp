#include"Map.h"
#include<iostream>
using namespace std;

Map::Map(int n) {
    data = new Pair[n];
}

Map::~Map() {
    delete[] data;
    sz = 0;
}

int& Map::operator[] (const string name) {
    for(int i = 0; i < sz; i++) {
        if(data[i].hasKey(name))
            return data[i].getVal();
    }
    data[sz].reset(name, 0);
    return data[sz++].getVal();
}

int Map::operator[] (const string name) const {
    for(int i = 0; i < sz; i++) {
        if(data[i].hasKey(name)) {
            const int a = data[i].getVal();
            return a;
        }
    }
    return 0;
}

int Map::size() {
    return sz;
}