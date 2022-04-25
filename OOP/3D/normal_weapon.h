#pragma once
#include"weapon.h"
#include<iostream>
using namespace std;

class NormalWeapon : public Weapon {
public:
    NormalWeapon(string name) : Weapon(name) { cout << "Normal weapon " << normal_get_name() << " was created." << endl; }
    ~NormalWeapon() {
        if(normal_get_level() == 0)
            cout << "Normal weapon " << normal_get_name() << " was destroyed." << endl;
        else
            cout << "Normal weapon " << normal_get_name() << "+" << normal_get_level() << " was destroyed." << endl; 
    }
    string normal_get_name() const { return get_name(); }
    int normal_get_level() const { return get_level(); }
    void normal_upgrade() { 
        upgrade();
        if(normal_get_level() == 1)
            cout << "Normal weapon " << normal_get_name() << " was upgraded to " << normal_get_name() << "+1." << endl;
        else
            cout << "Normal weapon " << normal_get_name() << "+" << normal_get_level() - 1 <<" was upgraded to " << normal_get_name() << "+" << normal_get_level() << "." << endl;
    }
};