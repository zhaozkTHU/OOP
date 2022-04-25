#include"Vector.h"
using std::move;

Vector::Vector(int n) {
    array = new Node[n];
    capacity = n;
    len = 0;
}

Vector::~Vector() {
    delete[] array;
    capacity = 0;
    len = 0;
}

Vector::Vector(const Vector & other) {
    capacity = other.capacity;
    len = other.len;
    array = new Node[len];//why not capacity?
    for(int i = 0; i < len; i++)
        array[i] = other.array[i];
}

Vector::Vector(Vector && other) {
    array = other.array;
    other.array = nullptr;
    capacity = other.capacity;
    len = other.len;
    other.capacity = 0; other.len = 0;
}

Vector& Vector::operator=(const Vector & other) {
    if(this != &other) {
        delete[] array;
        array = new Node[other.len];
        capacity = other.capacity;
        len = other.len;
        for(int i = 0; i < len; i++)
            array[i] = other.array[i];
    }
    return *this;
}

Vector& Vector::operator=(Vector && other) {
    if(this != &other) {
        delete[] array;
        array = other.array;
        other.array = nullptr;
        capacity = other.capacity;
        len = other.len;
        other.capacity = 0;
        other.len = 0;
    }
    return *this;
}

Node& Vector::operator[](int pos) {
    return array[pos];
}

void Vector::append(int value) {
    array[len++] = value;
}

void Vector::insert(int pos, int value) {
    for(int i = len; i > pos; i--) {
        array[i] = move(array[i-1]);
    }
    array[pos] = value;
    len++;
}

void Vector::swap(int pos1, int pos2) {
    Node tmp = move(array[pos1]);
    array[pos1] = move(array[pos2]);
    array[pos2] = move(tmp);
}

void Vector::dilatation() {
    Node* tmp = new Node[2 * capacity];
    for(int i = 0; i < len; i++) {
        tmp[i] = move(array[i]);
    }
    delete[] array;
    array = tmp;
    tmp = nullptr;
    capacity *= 2;
}

int Vector::getlen() {
    return len;
}