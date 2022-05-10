#pragma once
#include"smithing_stone.h"

class SomberSmithingStone : public SmithingStone {
public:
    SomberSmithingStone(int level) : SmithingStone(level) {
        cout << "Somber smithing stone " << level << " was created." <<endl;   
    }
    ~SomberSmithingStone() {
        cout << "Somber smithing stone " << somber_get_level() << " was destroyed." << endl;
    }
    void somber_add_amount(int amount) {
        add_amount(amount);
        if(amount > 0)
            cout << "Somber smithing stone " << somber_get_level() << " was added with " << amount << "." << endl;
        if(amount < 0)
            cout << "Somber smithing stone " << somber_get_level() << " was substracted with " << -amount << "." << endl;
    }
    bool somber_greater_equal(int need) const {
        return greater_equal(need);
    }
    int somber_get_level() const {
        return get_level();
    }
};