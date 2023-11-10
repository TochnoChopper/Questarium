#pragma once
#include <string>
#include "Weapons.h"
#include "Enemy.h"

using namespace std;

class player {
public:
    unsigned int id;
    int health;
    string player_name, weapon_name;
};

class warrior : public player, public sword {
public:
    warrior(unsigned int id, string name, int health) {
        weapon_name = name_w;
        this->id = id;
        player_name = name;
        this->health = health;
    }
    void Warior_attack_RD(red_demon& d) { // *
        d.health_e -= final_damage;
    }
    void Warior_attack_GD(green_demon& d) {
        d.health_e -= final_damage;
    }
    void Warrior_get_info() {
        cout << "id: " << id << "; Name: " << player_name << "; Health: " << health << "; Damage: " << final_damage << "; Weapon name: " << name_w << endl;
    }
};

class ranger : public player, public bow {
public:
    ranger(unsigned int id, string name, int health) {
        weapon_name = name_w;
        this->id = id;
        player_name = name;
        this->health = health;
    }
    void Ranger_attack_RD(red_demon& d) {
        d.health_e -= final_damage;
    }
    void Ranger_attack_GD(green_demon& d) {
        d.health_e -= final_damage;
    }
    void Ranger_get_info() {
        cout << "id: " << id << "; Name: " << player_name << "; Health: " << health << "; Damage: " << final_damage << "; Weapon name: " << name_w << endl;
    }
};

class rogue : public player, public dagger {
public:
    rogue(unsigned int id, string name, int health) {
        weapon_name = name_w;
        this->id = id;
        player_name = name;
        this->health = health;
    }
    void Rogue_attack_RD(red_demon& d) {
        d.health_e -= final_damage;
    }
    void Rogue_attack_GD(green_demon& d) {
        d.health_e -= final_damage;
    }
    void Rogue_get_info() {
        cout << "id: " << id << "; Name: " << player_name << "; Health: " << health << "; Damage: " << final_damage << "; Weapon name: " << name_w << endl;
    }
};

class sniper : public player, public sniper_rifle {
public:
    sniper(unsigned int id, string name, int health) {
        weapon_name = name_w;
        this->id = id;
        player_name = name;
        this->health = health;
    }
    void Sniper_attack_RD(red_demon& d) {
        d.health_e -= final_damage;
    }
    void Sniper_attack_GD(green_demon& d) {
        d.health_e -= final_damage;
    }
    void Sniper_get_info() {
        cout << "id: " << id << "; Name: " << player_name << "; Health: " << health << "; Damage: " << final_damage << "; Weapon name: " << name_w << endl;
    }
};

class blood_mage : public player, protected blood_magic_staff {
public:
    blood_mage(unsigned int id, string name, int health) {
        weapon_name = name_w;
        this->id = id;
        player_name = name;
        this->health = health;
    }
    void lvl_up(int new_lvl) {
        lvl = new_lvl;
        if (lvl == 0) {
            extra_damage = 0;
            max_familiars = 0;
        }
        else if (lvl == 1) {
            extra_damage = 11;
            max_familiars = 1;
        }
        else if (lvl == 2) {
            extra_damage = 20;
            max_familiars = 2;
        }
        else if (lvl == 3) {
            extra_damage = 38;
            max_familiars = 3;
        }
        if (lvl == 0) final_damage = 0;
        else final_damage = 15 + extra_damage;
    }
    void Blood_mage_attack_RD(red_demon& d) {
        d.health_e -= final_damage;
    }
    void Blood_mage_attack_GD(green_demon& d) {
        d.health_e -= final_damage;
    }
    void Blood_mage_get_info() {
        cout << "id: " << id << "; Name: " << player_name << "; Health: " << health << "; Damage: " << final_damage << "; Weapon name: " << name_w << "; Magic lvl: " << lvl << endl;
    }
};

class arcane_mage : public player, public arcane_magic_staff {
public:
    arcane_mage(unsigned int id, string name, int health) {
        weapon_name = name_w;
        this->id = id;
        player_name = name;
        this->health = health;
    }
    void lvl_up(int new_lvl) {
        lvl = new_lvl;

        if (lvl == 0) {
            extra_damage = 0;
            shield_capacity = 0;
        }
        else if (lvl == 1) {
            extra_damage = 9;
            shield_capacity = 40;
        }
        else if (lvl == 2) {
            extra_damage = 23;
            shield_capacity = 65;
        }
        else if (lvl == 3) {
            extra_damage = 47;
            shield_capacity = 90;

        if (lvl == 0) final_damage = 0;
        else final_damage = 15 + extra_damage;
        }
    }
    void Arcane_mage_attack_RD(red_demon& d) {
        d.health_e -= final_damage;
    }
    void Arcane_mage_attack_GD(green_demon& d) {
        d.health_e -= final_damage;
    }
    void Arcane_mage_get_info() {
        cout << "id: " << id << "; Name: " << player_name << "; Health: " << health << "; Damage: " << final_damage << "; Weapon name: " << name_w << "; Magic lvl: " << lvl << endl;
    }
};

class ice_mage : public player, public ice_magic_staff {
public:
    ice_mage(unsigned int id, string name, int health) {
        weapon_name = name_w;
        this->id = id;
        player_name = name;
        this->health = health;
    }
    void lvl_up(int new_lvl) {
        lvl = new_lvl;

        if (lvl == 0) {
            extra_damage = 0;
            lump_duration = 0.0f;
        }
        else if (lvl == 1) {
            extra_damage = 12;
            lump_duration = 2.0f;
        }
        else if (lvl == 2) {
            extra_damage = 21;
            lump_duration = 3.5f;
        }
        else if (lvl == 3) {
            extra_damage = 39;
            lump_duration = 5.0f;
        }

        if (lvl == 0) final_damage = 0;
        else final_damage = 15 + extra_damage;
    }
    void Ice_mage_attack_RD(red_demon& d) {
        d.health_e -= final_damage;
    }
    void Ice_mage_attack_GD(green_demon& d) {
        d.health_e -= final_damage;
    }
    void Ice_mage_get_info() {
        cout << "id: " << id << "; Name: " << player_name << "; Health: " << health << "; Damage: " << final_damage << "; Weapon name: " << name_w << "; Magic lvl: " << lvl << endl;
    }
};