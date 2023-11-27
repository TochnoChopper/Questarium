#pragma once
#include <string>
#include <iostream>
#include "Weapons.h"
#include "Player.h"

using namespace std;

class enemy {
    friend class player;
    friend class rogue;
protected:
    string enemy_type, weapon_name_e = "Have no weapon!";
    int health_e;
    unsigned int damage_e, attack_speed, drop_money_count;
    unsigned short ability_count_e;
public:
    void Enemy_get_info() {
        cout << "\nType: " << enemy_type << " \nHealth: " << health_e << "\nDrop money: " << drop_money_count << " \nWeapon name: " << weapon_name_e << "\nDamage: " << damage_e << "\nAttack speed: " << attack_speed;
    }
};

class demon : public enemy {
public:
    demon() {
        enemy_type = "demon";
        health_e = 170;
        damage_e = 38;
        attack_speed = 15;
        drop_money_count = 40;
        ability_count_e = 2;
    }

    void Filth_healing() {
        if (ability_count_e != 0) {
            health_e += 50;
            ability_count_e -= 1;
        }
        else cout << "Cant use ability\n";
    }
};

class goblin : public enemy {
public:
    goblin() {
        enemy_type = "goblin";
        health_e = 130;
        damage_e = 38;
        attack_speed = 15;
        drop_money_count = 15;
        ability_count_e = 1;
    }

    void Increased_damage() {
        if (ability_count_e != 0) {
            damage_e += 20;
            ability_count_e -= 1;
        }
        else cout << "Cant use ability\n";
    }
}; 
