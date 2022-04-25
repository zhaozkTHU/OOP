#pragma once
#include"weapon.h"

class SomberWeapon : public Weapon {
public:
    SomberWeapon(string name) : Weapon(name) {
        cout << "Somber weapon " << somber_get_name() << " was created." << endl;
    };
    ~SomberWeapon() {
        if(somber_get_level() == 0)
            cout << "Somber weapon " << somber_get_name() << " was destroyed." << endl;
        else
            cout << "Somber weapon " << somber_get_name() << "+" << somber_get_level() << " was destroyed." << endl; 
    }
    string somber_get_name() const { return get_name(); }
    int somber_get_level() const { return get_level(); }
    void somber_upgrade() { 
        upgrade(); 
        if(somber_get_level() == 1)
            cout << "Somber weapon " << somber_get_name() << " was upgraded to " << somber_get_name() << "+1." << endl;
        else
            cout << "Somber weapon " << somber_get_name() << "+" << somber_get_level() - 1 <<" was upgraded to " << somber_get_name() << "+" << somber_get_level() << "." << endl;

    }
};