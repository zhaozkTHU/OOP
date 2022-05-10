#pragma once

#include <string>

#include "Hash.h"

template <typename T1, typename T2>
class HashTable
{
    Hash<T1> hash;
    T2** value;
public:
    HashTable(int n) : hash(n), value(new T2*[n]) {
        for(int i = 0; i < n; i++)
            value[i] = nullptr;
    }
    HashTable() {
        value = nullptr;
    }
    void addItem(const T1 &key, const T2 &Value) {
        value[hash(key)] = new T2(Value);
    }
    void removeItem(const T1 &key) {
        delete value[hash(key)];
        value[hash(key)] = nullptr;
    }
    T2 *findByKey(const T1 &key) {
        if(value[hash(key)] == nullptr)
            return nullptr;
        return value[hash(key)];
    }
};