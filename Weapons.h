#pragma once
#include <string>
#include "Player.h"
#include "Enemy.h"

using namespace std;

class weapon {
    friend class player;
    friend class enemy;
protected:
    string name_w, type_w;
    unsigned int damage_w, attack_speed;
public:
    weapon(string type, string name, unsigned int damage, unsigned int attack_speed) {
        type_w = type;
        name_w = name;
        damage_w = damage;
        this->attack_speed = attack_speed;
    }
};

