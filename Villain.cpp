//
// Created by James  Bush on 9/13/23.
//

#include "Villain.h"
using namespace std;

Villain::Villain(std::string pName, std::string pType) : Character(){
    name = pName;
    type = pType;
    energy = 12;
    powerDamp = 1;
    if (type == "Fire Lord" || type == "fire lord"){
        superPowerName = "the power of Sozin's Comet";
        health = 100;
        primaryAttack = 30;
        secondaryAttack = 15;
    } else if (type == "Sith" || type == "sith"){
        superPowerName = "Force Choke";
        health = 120;
        primaryAttack = 40;
        secondaryAttack = 10;
    } else if (type == "Thanos" || type == "thanos"){
        superPowerName = "the Infinity Stones";
        health = 150;
        primaryAttack = 30;
        secondaryAttack = 15;
    } else if (type == "Agent" || type == "agent"){
        superPowerName = "their ability to absorb your powers";
        health = 90;
        primaryAttack = 60;
        secondaryAttack = 15;
    }
}

string Villain::superPower(Character* opponent) {
    if (!superPowerUsed){
        opponent->setPowerDamp(.75);
        superPowerUsed = true;
        return name + " uses " + superPowerName +" and weakens your attacks!";
    }

    return "Superpower already used.";
}