#pragma once
#include <string>

using namespace std;

class projectile {
protected:
    string name_p;
    unsigned int projectile_speed, extra_damage;
};

class arrow : public projectile {
public:
    arrow() {
        name_p = "arrow";
        projectile_speed = 25;
        extra_damage = 22;
    }
};

class bullet : public projectile {
public:
    bullet() {
        name_p = "bullet";
        projectile_speed = 150;
        extra_damage = 28;
    }
};
