#pragma once
#include <string>
#include "Projectiles.h"
#include "Magic.h"

using namespace std;

class weapon {
protected:
    string name_w;
    unsigned int final_damage, weight_w;
};

class sword : public weapon {
private:
    unsigned int atack_speed;
public:
    sword() {
        name_w = "Sword";
        final_damage = 30;
        weight_w = 5;
        atack_speed = 30;
    }
};

class dagger :public weapon {
private:
    unsigned int atack_speed;
public:
    dagger() {
        name_w = "Dagger";
        final_damage = 18;
        weight_w = 1;
        atack_speed = 60;
    }
};

class bow : public weapon, public arrow {
private:
    unsigned int atack_speed;
public:
    bow() {
        name_w = "Bow";
        final_damage = 40 + extra_damage;
        weight_w = 3;
        atack_speed = 25;
    }
};

class sniper_rifle : public weapon, public bullet {
private:
    unsigned int atack_speed;
public:
    sniper_rifle() {
        name_w = "Sniper rifle";
        final_damage = 65 + extra_damage;
        weight_w = 6;
        atack_speed = 10;
    }
};

// ??? ???? ??????? ???? ???????? ? ??????? ?????

class blood_magic_staff : public weapon, public blood_magic {
private:
    int energy_restoration;
    unsigned int atack_speed;
public:
    blood_magic_staff() {
        name_w = "Magic Staff of blood";
        weight_w = 2;
        energy_restoration = 10;
        atack_speed = 20;
    }
};

class arcane_magic_staff : public weapon, public arcane_magic {
private:
    int energy_restoration;
    unsigned int atack_speed;
public:
    arcane_magic_staff() {
        name_w = "Magic Staff of blood";
        weight_w = 2;
        energy_restoration = 25;
        atack_speed = 30;
    }
};

class ice_magic_staff : public weapon, public ice_magic {
private:
    int energy_restoration;
    unsigned int atack_speed;
public:
    ice_magic_staff() {
        name_w = "Magic Staff of blood";
        weight_w = 2;
        energy_restoration = 15;
        atack_speed = 25;
    }
};
