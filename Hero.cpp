//
// Created by James  Bush on 9/13/23.
//
#include <iostream>

#include "Hero.h"
using namespace std;

Hero::Hero(string pName, string pType) : Character(){
    name = pName;
    type = pType;
    energy = 12;
    powerDamp = 1;
    superPowerUsed = false;
    if (type == "Avatar" || type == "avatar"){
        superPowerName = "Avatar State";
        health = 100;
        primaryAttack = 30;
        secondaryAttack = 15;
    } else if (type == "Jedi" || type == "jedi"){
        superPowerName = "Jedi Focus";
        health = 120;
        primaryAttack = 40;
        secondaryAttack = 10;
    } else if (type == "Avenger" || type == "avenger"){
        superPowerName = "Comedic One Liner";
        health = 150;
        primaryAttack = 30;
        secondaryAttack = 15;
    } else if (type == "Matrix" || type == "matrix"){
        superPowerName = "The Red Pill";
        health = 80;
        primaryAttack = 60;
        secondaryAttack = 15;
    }
}

void Hero::setEnergy(int pEnergy) {
    energy -= pEnergy;
    if (getEnergy() <= 0){
        Character::setHealth(200);
    }
}

int Hero::getEnergy() {
    return energy;
}

string Hero::superPower(Character* opponent) {
    if (!superPowerUsed) {
        opponent->setHealth(100);
        superPowerUsed = true;
        return name + " uses " + superPowerName +" and delivers a big blow!";
    }
    return "Superpower already used.";
}

