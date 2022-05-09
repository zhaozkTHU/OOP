#pragma once
#include"animal.h"

void action(Animal *buffer, std::vector<Dog> &dogzone, std::vector<Bird> &birdzone) {
    if(dynamic_cast<Dog*>(buffer) != nullptr) {
        dogzone.push_back(std::move(*dynamic_cast<Dog*>(buffer)));
    }
    else
        birdzone.push_back(std::move(*dynamic_cast<Bird*>(buffer)));
}