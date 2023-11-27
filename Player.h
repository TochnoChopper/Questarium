#pragma once
#include <string>
#include "Weapons.h"
#include "Enemy.h"
#include "Quest.h"
#include "Entity.h"

using namespace std;

class player {
    friend class enemy;
protected:
    unsigned int id, damage_p = 0, attack_speed_p = 0;
    unsigned short magic_lvl, ability_limit;
    int health_p;
    string player_name, weapon_name = "No weapon!\n", available_weapon;
public:
    void Swap_weapon(weapon w) {
        if (available_weapon == w.type_w) {
            damage_p = w.damage_w;
            attack_speed_p = w.attack_speed;
            weapon_name = w.name_w;
        }

        else cout << "Player cant use this weapon\n";
    }

    void Player_get_info() {
        cout << "\nid: " << id << "\nName: " << player_name << "\nHealth: " << health_p << "\nWeapon name: " << weapon_name << "\nDamage: " << damage_p << "\nAttack speed:" << attack_speed_p << endl;
    }

    void Player_attack(enemy &d) {
        d.health_e -= damage_p;
    }

    void Talk_NPC(NPC np) {
        cout << "Quest " << np.number_giving_quest << "... " << np.name_giving_quest << endl;
        cout << np.begining_talk << endl << np.descript_giving_quest << endl;
    }

    void Cut_tree(entity e) {
        if ((e.type_e == "tree") || (e.is_alive = true)) {
            cout << player_name << " is cutting " << e.name_e << endl;
            e.is_alive = false;
        }
        else cout << "This is not tree or it was already cut\n";
    }
};

class warrior : public player{
public:
    warrior(unsigned int id, string name, int health) {
        this->id = id;
        player_name = name;
        this->health_p = health;
        available_weapon = "sword";
        magic_lvl = 0;
        ability_limit = 1;
    }

    void Warrior_furios() {
        if (ability_limit != 0) {
            damage_p += 30;
            health_p -= 30;
            ability_limit -= 1;
        }
        else cout << "Impossible to use ability!";;
    }
};

class ranger : public player{
public:
    ranger(unsigned int id, string name, int health) {
        this->id = id;
        player_name = name;
        this->health_p = health;
        available_weapon = "bow";
        magic_lvl = 0;
        ability_limit = 2;
    }

    void Ranger_potion() {
        if (ability_limit != 0) {
            health_p += 15;
            ability_limit -= 1;
        }
        else cout << "Impossible to use ability!";;
    }
};

class rogue : public player{
public:
    rogue(unsigned int id, string name, int health) {
        this->id = id;
        player_name = name;
        this->health_p = health;
        available_weapon = "dagger";
        magic_lvl = 0;
        ability_limit = 2;
    }
    void Throw_dagger(enemy &e) {
        if (ability_limit != 0) {
            e.health_e -= 12;
            ability_limit -= 1;
        }
        else cout << "Impossible to use ability!";;
    }
}; 

class sniper : public player{
public:
    sniper(unsigned int id, string name, int health) {
        this->id = id;
        player_name = name;
        this->health_p = health;
        available_weapon = "sniper_rifle";
        ability_limit = 3;
    }
};

/* Mages */

class blood_mage : public player{
public:
    blood_mage(unsigned int id, string name, int health) {
        this->id = id;
        player_name = name;
        this->health_p = health;
        available_weapon = "staff";
        magic_lvl = 0;
        ability_limit = 1;
    }

    void lvl_up(int new_lvl) {
        if (new_lvl <= magic_lvl) cout << "Player cant reduce his lvl or lvl is same!\n";
        else {
            magic_lvl = new_lvl;

            if (magic_lvl == 0) {
                damage_p += 0;
            }
            else if (magic_lvl == 1) {
                damage_p += 13;
            }
            else if (magic_lvl == 2) {
                damage_p += 18;
            }
            else if (magic_lvl == 3) {
                damage_p += 35;
            }
        }
    }

    void Ancient_knowledges() {
        if (ability_limit != 0) {
            damage_p += 30;
            ability_limit -= 1;
        }
        else cout << "Impossible to use ability!";;
    }
};

class arcane_mage : public player{
public:
    arcane_mage(unsigned int id, string name, int health) {
        this->id = id;
        player_name = name;
        this->health_p = health;
        available_weapon = "staff";
        magic_lvl = 0;
        ability_limit = 1;
    }
    void lvl_up(int new_lvl) {
        if (new_lvl <= magic_lvl) cout << "Player cant reduce his lvl or lvl is same!\n";
        else {
            magic_lvl = new_lvl;

            if (magic_lvl == 0) {
                damage_p += 0;
            }
            else if (magic_lvl == 1) {
                damage_p += 10;
            }
            else if (magic_lvl == 2) {
                damage_p += 15;
            }
            else if (magic_lvl == 3) {
                damage_p += 27;
            }
        }
    }

    void Arcane_shield() {
        if (ability_limit != 0) {
            health_p += 100;
            ability_limit -= 1;
        }
        else cout << "Impossible to use ability!";;
    }
};

class ice_mage : public player{
protected:
    unsigned int saved_damage;
public:
    ice_mage(unsigned int id, string name, int health) {
        this->id = id;
        player_name = name;
        this->health_p = health;
        available_weapon = "staff";
        magic_lvl = 0;
        ability_limit = 1;
    }
    void lvl_up(int new_lvl) {
        if (new_lvl <= magic_lvl) cout << "Player cant reduce his lvl!\n";
        else {
            magic_lvl = new_lvl;

            if (magic_lvl == 0) {
                damage_p += 0;
            }
            else if (magic_lvl == 1) {
                damage_p += 9;
            }
            else if (magic_lvl == 2) {
                damage_p += 19;
            }
            else if (magic_lvl == 3) {
                damage_p += 30;
            }
        }
    }

    void Water_lung_on() {
        saved_damage = damage_p;
        damage_p = 0;
        health_p += 5000;
    }
    void Water_lung_off() {
        damage_p = saved_damage;
        health_p -= 5000;
    }
};
