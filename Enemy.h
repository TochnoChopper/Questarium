#pragma once
#include <string>
#include "Weapons.h"

using namespace std;

class enemy {
public:
    string enemy_type, weapon_name_e;
    int health_e, drop_money_count;
    unsigned int final_damage_e;

};

class demon : public enemy {
protected:
    string demon_type;
};

class red_demon : public demon, public sword {
public:
    red_demon() {
        enemy_type = "Demon";
        demon_type = "Red";
        weapon_name_e = name_w;
        health_e = 250;
        drop_money_count = 100;
    }

};

class green_demon : public demon, public bow {
public:
    green_demon() {
        enemy_type = "Demon";
        demon_type = "Green";
        weapon_name_e = name_w;
        health_e = 130;
        drop_money_count = 40;
    }

};
