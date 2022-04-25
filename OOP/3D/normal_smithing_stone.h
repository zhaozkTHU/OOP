#pragma once
#include"smithing_stone.h"
#include<iostream>
using namespace std;

class NormalSmithingStone : public SmithingStone {
public:
    NormalSmithingStone(int level) : SmithingStone(level) {
        cout << "Normal smithing stone " << normal_get_level() << " was created." << endl;
    }
    ~NormalSmithingStone() {
        cout << "Normal smithing stone " << normal_get_level() << " was destroyed." << endl;
    }
    void normal_add_amount(int amount) {
        add_amount(amount);
        if(amount > 0)
            cout << "Normal smithing stone " << normal_get_level() << " was added with " << amount << "." << endl;
        if(amount < 0)
            cout << "Normal smithing stone " << normal_get_level() << " was substracted with " << -amount << "." <<endl;
    }
    bool normal_greater_equal(int need) const {
        return greater_equal(need);
    }
    int normal_get_level() const {
        return get_level();
    }
};