#include"tarnished.h"
#include<iostream>
using std::cout;
using std::endl;

Tarnished::Tarnished() {
    for(int i = 0; i < 1000; i++) {
        normal_weapons[i] = nullptr;
        somber_weapons[i] = nullptr;
    }
    for(int i = 0; i < 50; i++) {
        normal_smithing_stones[i] = nullptr;
        somber_smithing_stones[i] = nullptr;
    }
}

Tarnished::~Tarnished() {
    for(int i = 1; i <= 8; i++) {
        if(normal_smithing_stones[i] != nullptr) {
            delete normal_smithing_stones[i];
            normal_smithing_stones[i] = nullptr;
        }
    }
    for(int i = 1; i <= 8; i++) {
        if(somber_smithing_stones[i] != nullptr) {
            delete somber_smithing_stones[i];
            somber_smithing_stones[i] = nullptr;
        }
    }
    for(int i = 0; i < 50; i++) {
        if(normal_weapons[i] == nullptr) break;
        delete normal_weapons[i];
        normal_weapons[i] = nullptr;
    }
    for(int i = 0; i < 50; i++) {
        if(somber_weapons[i] == nullptr) break;
        delete somber_weapons[i];
        somber_weapons[i] = nullptr;
    }
}

void Tarnished::pick_up_stone(int type, int level, int number) {
    if(type == 0) {  //normal
        if(normal_smithing_stones[level] == nullptr)
            normal_smithing_stones[level] = new NormalSmithingStone(level);
        normal_smithing_stones[level]->normal_add_amount(number);
    }
    if(type == 1) {  //somber
        if(somber_smithing_stones[level] == nullptr)
            somber_smithing_stones[level] = new SomberSmithingStone(level);
        somber_smithing_stones[level]->somber_add_amount(number);
    }
}

void Tarnished::pick_up_weapon(int type, string name) {
    if(type == 0){
        for(int i = 0; i < 50; i++) {
            if(normal_weapons[i] == nullptr) {
                normal_weapons[i] = new NormalWeapon(name);
                break;
            }
        }
    }
    if(type == 1) {
        for(int i = 0; i < 50; i++) {
            if(somber_weapons[i] == nullptr) {
                somber_weapons[i] = new SomberWeapon(name);
                break;
            }
        }
    }
}

void Tarnished::upgrade_weapon(int target, string name) {
    
    int flag(0), type(0), location(0);
    for(int i = 0; i < 50; i++) {
        if(normal_weapons[i] == nullptr && somber_weapons[i] == nullptr) break;
        if(normal_weapons[i] != nullptr) {
            if(name == normal_weapons[i]->normal_get_name()) {
                flag = 1;
                type = 0;
                location = i;
                break;
            }
        }
        if(somber_weapons[i] != nullptr) {
            if(name == somber_weapons[i]->somber_get_name()) {
                flag = 1;
                type = 1;
                location = i;
                break;
            }
        }
    }
    if(flag == 0) {
        cout << "You don't have the right!" << endl;
        return;
    }
    if(type == 0) {
        int Level = normal_weapons[location]->normal_get_level();
        if(normal_weapons[location]->normal_get_level() >= target) {
            cout << "Stay calm!" << endl;
            return;
        }
        int need[9] = {0};
        for(int i = normal_weapons[location]->normal_get_level(); i < target; i++) {
            need[i / 3 + 1] += (i % 3) * 2 + 2;
        }
        for(int i = 1; i <= 8; i++) {
            if (need[i] != 0) {
                if (normal_smithing_stones[i] == nullptr) {
                    cout << "Upgrade failed for lacking normal smithing stone " << i << "." << endl;
                    return;
                }
                if (!normal_smithing_stones[i]->normal_greater_equal(need[i])) {
                    cout << "Upgrade failed for lacking normal smithing stone " << i << "." << endl;
                    return;
                }
            }
        }
        for(int i = normal_weapons[location]->normal_get_level(); i < target; i++) {
            normal_smithing_stones[i / 3 + 1]->normal_add_amount(-((i % 3) * 2 + 2));
            if(!normal_smithing_stones[i / 3 + 1]->normal_greater_equal(1)) {
                delete normal_smithing_stones[i / 3 + 1];
                normal_smithing_stones[i / 3 + 1] =nullptr;
            }
            normal_weapons[location]->normal_upgrade();
        }
        if(Level == 0) cout << "Upgrade " << normal_weapons[location]->normal_get_name() << " to " << normal_weapons[location]->normal_get_name() << "+" << target << " Successfully." <<endl;
        else cout << "Upgrade " << normal_weapons[location]->normal_get_name() << "+" << Level << " to " << normal_weapons[location]->normal_get_name() << "+" << target << " Successfully." <<endl;
    }
    if(type == 1) {
        int Level = somber_weapons[location]->somber_get_level();
        if(somber_weapons[location]->somber_get_level() >= target) {
            cout << "Stay calm!" << endl;
            return;
        }
        for(int i = somber_weapons[location]->somber_get_level() + 1; i <= target; i++) {
            if (somber_smithing_stones[i] == nullptr) {
                cout << "Upgrade failed for lacking somber smithing stone " << i << "." << endl;
                return;
            }
            if(!somber_smithing_stones[i]->somber_greater_equal(1)) {
                cout << "Upgrade failed for lacking somber smithing stone " << i << "." << endl; 
                return;
            }
        }
        for(int i = somber_weapons[location]->somber_get_level() + 1; i <= target; i++) {
            somber_smithing_stones[i]->somber_add_amount(-1);
            if(!somber_smithing_stones[i]->somber_greater_equal(1)) {
                delete somber_smithing_stones[i];
                somber_smithing_stones[i] = nullptr;
            }
            somber_weapons[location]->somber_upgrade();
        }
        if(Level == 0) cout << "Upgrade " << somber_weapons[location]->somber_get_name() << " to " << somber_weapons[location]->somber_get_name() << "+" << target << " Successfully." <<endl;
        else cout << "Upgrade " << somber_weapons[location]->somber_get_name() << "+" << Level << " to " << somber_weapons[location]->somber_get_name() << "+" << target << " Successfully." <<endl;
    }
}