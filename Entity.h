#pragma once
#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

class entity {
    friend class player;
protected:
    string name_e, type_e;
    bool is_alive;
public:
    entity(string name, string type, bool is_alive) {
        name_e = name;
        type_e = type;
        this->is_alive = is_alive;
    }

    void Get_info() { 
        cout << "Entity type: " << type_e << "\nName: " << name_e << "\nAlive: " << is_alive;
    }
};
