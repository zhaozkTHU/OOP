#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>

template<class T>
class Data {
protected:
    int length;
    T value;
public:
    Data(int _length) : length(_length) {}
    virtual const T &get(int index) = 0;
};

template<class T>
class DataEmpty : public Data<T> {
public:
    DataEmpty<T>() : Data<T>(0) {};
    const T &get(int index) {
        assert(0); // No data in DataEmpty
    }
};

template<class T>
class DataPushBackDecorator : public Data<T> {
protected:
    shared_ptr<Data<T>> _data;
public:
    const T &get(int index) {
        if (length == index)
            return value;
        else return _data->get(index);
    }
    DataPushBackDecorator<T>(data, value) : _data(data), value(value) {
        length = _data.length + 1;
    }
};

template<class T>
class DataSetDecorator : public Data<T> {
protected:
    shared_ptr<Data<T>> _data;
    int _index;
public:
    const T &get(int index) {
        if (_index == index)
            return value;
        else return _data->get(index);
    }
    DataPushBackDecorator<T>(shared_ptr<Data<T>> data, int index, const T &value) : _data(data), _index(index), value(value) {}
};


template<class T>
class PVector {
public:
    shared_ptr<Data<T>> data;
    PVector<T>() {
        data = new DataEmpty<T>();
        // when to delete??
    }
    PVector<T>(Data<T> *_data) : data(_data) {}
    PVector<T> push_back(const T &value) const {
        return PVector<T>(new DataPushBackDecorator<T>(data, value));
    }
    PVector<T> set(int index, const T &value) const {
        return PVector<T>(new DataSetDecorator<T>(data, index, value));
    }

    const T &operator[](int index) {
        return data->get(index);
    }

    friend ostream &operator<<(ostream &out, const PVector &tmp) {

    }
};
