#pragma once
#include <string>

using namespace std;

class magic {
protected:
    string name_m, special_ability, energy_type;
    unsigned int extra_damage;
};

class blood_magic : public magic {
protected:
    unsigned short max_familiars;
    unsigned short lvl = 0;
public:
    blood_magic() {
        name_m = "Blood";
        special_ability = "Necromancy";
        energy_type = "Blood of the fallen";
    }
};

class arcane_magic : public magic {
protected:
    unsigned short shield_capacity;
    unsigned short lvl = 0;
public:
    arcane_magic() {
        name_m = "Arcane";
        special_ability = "Mana Shield";
        energy_type = "Mana";
    }

};

class ice_magic : public magic {
protected:
    float lump_duration;
    unsigned short lvl = 0;
public:
    ice_magic() {
        name_m = "Ice";
        special_ability = "Ice Lump";
        energy_type = "Water";
    }

};
