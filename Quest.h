#pragma once
#include <string>
#include "Player.h"

using namespace std;

class quest {
    friend class NPC;
protected:
    unsigned short number_q;
    string name_q, description_q;
public:
    quest(unsigned short number, string name, string description) {
        number_q = number;
        name_q = name;
        description_q = description;
    }

    void Quest_get_info() {
        cout << "Name = " << name_q << "; Number = " << number_q << endl << "Description: " << description_q << endl;
    }
};

class NPC {
    friend class player;
protected:
    string name_n, name_giving_quest, descript_giving_quest, begining_talk;
    unsigned short age_n, number_giving_quest;
public:
    NPC(string name, unsigned short age, string begining_talk, quest& q) {
        name_n = name;
        age_n = age;
        this->begining_talk = begining_talk;
        number_giving_quest = q.number_q;
        name_giving_quest = q.name_q;
        descript_giving_quest = q.description_q;
    }
};
