#include"Animal.h"
#include<iostream>

class Fish :public Animal {
public:
    Fish(int clor) { color = clor; }
    void swim() {
        if (color == 0) {
            std::cout << "Red fish is swimming." << std::endl;
        }
        else {
            std::cout << "Blue fish is swimming." << std::endl;
        }
    }
    void sing() {
        std::cout << "Fish can not sing." << std::endl;
    }
    ~Fish() {
        if (color == 0) {
            std::cout << "Red fish is gone." << std::endl;
        }
        else {
            std::cout << "Blue fish is gone." << std::endl;
        }
    }
};