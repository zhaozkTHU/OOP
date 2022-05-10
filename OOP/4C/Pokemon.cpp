#include"Pokemon.h"
#include<iostream>
using std::string;

Pokemon::Pokemon(int _hp, int _atk, string _name) {
    hp = _hp; atk = _atk; name = _name; tot_hp = _hp;
}

Pokemon::Pokemon() {
    hp = 0; atk = 0; name = {0}; tot_hp = 0;
}

string Pokemon::get_name() {
    return name;
}

bool Pokemon::alive() {
    return hp > 0;
}

int Pokemon::get_hp() {
    return hp;
}

int Pokemon::get_atk() {
    return atk;
}

void Pokemon::hurt(int, Pokemon*) {}

void Pokemon::use_skill(int, Pokemon*) {}

Squirtle::Squirtle(int hp, int atk, string name) : Pokemon(hp, atk, name) {}

void Squirtle::use_skill(int idx, Pokemon* target) {
    if(idx == 0) {
        hp += tot_hp / 5;
        if(hp > tot_hp) hp = tot_hp;
        cout << name << " used Regen" << endl;
    }
    if(idx == 1) {
        cout << name << " used Splash to " << target->get_name() << endl;
        target->hurt(atk, this);
    }
}

void Squirtle::hurt(int dmg, Pokemon* from) {
    if(hp <= tot_hp / 5) {
        if(dmg / 2 == 0) {
            hp -= 1;
            cout << name << " received " << 1 << " damage from " << from->get_name() << endl;
        }
        else {
            hp -= dmg / 2;
            cout << name << " received " << dmg / 2 << " damage from " << from->get_name() << endl;
        }
    }
    else {
        hp -= dmg;
        cout << name << " received " << dmg << " damage from " << from->get_name() << endl;
    }
}

Charizard::Charizard(int hp, int atk, string name) : Pokemon(hp, atk, name), fire(1) {}

void Charizard::use_skill(int idx, Pokemon* target) {
    if(idx == 0) {
        fire++;
        atk *= 2;
        cout << name << " used Ignite" << endl;
        hurt(fire * 10, this);
    }
    if(idx == 1) {
        cout << name << " used Flame to " << target->get_name() << endl;
        target->hurt(atk, this);
    }
}

void Charizard::hurt(int dmg, Pokemon* from) {
    cout << name << " received " << dmg << " damage from " << from->get_name() << endl;
    hp -= dmg;
    if(from != this) {
        if(dmg > 10)
            from->hurt(dmg / 5, this);
    }
}