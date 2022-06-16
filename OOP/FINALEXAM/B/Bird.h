#include"Animal.h"
#include<iostream>

class Bird :public Animal {
public:
    Bird(int clor) { color = clor; }
    void swim() {
        std::cout << "Bird can not swim." << std::endl;
    }
    void sing() {
        if (color == 0) {
            std::cout << "Red bird is singing." << std::endl;
        }
        else {
            std::cout << "Blue bird is singing." << std::endl;
        }
    }
    ~Bird() {
        if (color == 0) {
            std::cout << "Red bird is gone." << std::endl;
        }
        else {
            std::cout << "Blue bird is gone." << std::endl;
        }
    }
};