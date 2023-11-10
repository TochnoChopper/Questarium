#include <string>
#include <iostream>
#include "Player.h"
#include "Projectiles.h"
#include "Enemy.h"
#include "Magic.h"
#include "Weapons.h"

using namespace std;

class entity {
protected:
    string name_e, type_e;
    bool is_alive;
public:
    entity(string name, string type, bool is_alive) {
        name_e = name;
        type_e = type;
        this->is_alive = is_alive;
    }
    friend void Cut_tree(player&, entity&);
    friend void Earning_coin(player&, entity&);

};

class quest {
protected:
    unsigned short number;
    string name, description;
public:
    quest(unsigned short number, string name, string description) {
        this->number = number;
        this->name = name;
        this->description = description;
    }

    void Quest_get_info() {
        cout << "Name = " << name << "; Number = " << number << endl << "Description: " << description << endl;
    }
};

void Cut_tree(player& d, entity& x) {
    if (x.type_e == "Tree") {
        cout << d.player_name << " is cutting " << x.name_e << endl;
    }
}

void Earning_coin(player& d, entity& x) {
    if (x.type_e == "Coin") {
        cout << d.player_name << " earned " << x.name_e << endl;
    }
}


int main()
{
    // Все далее лишь демонстрирует возможности взаимодействия классов

    quest FirstQuest = quest(1, "Begining", "You need to kill 2 red demons");
    FirstQuest.Quest_get_info();

    warrior Sasha = warrior(212, "Sasha", 120);
    red_demon Grisha;
    Sasha.Warrior_get_info();

    sniper Hopper = sniper(192102, "Hopper", 110);
    Hopper.Sniper_get_info();

    Sasha.Warior_attack_RD(Grisha);
    cout << Grisha.health_e << endl;

    blood_mage Nomad = blood_mage(432, "Pavel", 120);
    Nomad.lvl_up(2); // Уровень не повышается (Fixed)
    Nomad.Blood_mage_attack_RD(Grisha);
    cout << Grisha.health_e << endl;
    Nomad.Blood_mage_get_info();

    entity Tree = entity("Grand Tree", "Tree", true);
    entity Money = entity("coin", "Coin", false);
    Cut_tree(Nomad, Tree);
    Earning_coin(Nomad, Money);

    
    return 1;
}
