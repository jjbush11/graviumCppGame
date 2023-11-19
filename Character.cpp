//
// Created by James  Bush on 10/3/23.
//

#include "Character.h"
using namespace std;

Character::Character() {
    name = "Default";
    type = "Default";
    superPowerName = "DefaultSuperPower";
    health = 0;
    primaryAttack = 0;
    secondaryAttack = 0;
    energy = 0;
    superPowerUsed = false;
}

//Getters
string Character::getName() {
    return name;
}

std::string Character::getType() {
    return type;
}

int Character::getHealth() {
    return health;
}

int Character::getPrimaryAttack() {
    return primaryAttack * powerDamp;
}

int Character::getSecondaryAttack() {
    return secondaryAttack * powerDamp;
}

string Character::getSuperPowerName(){
    return superPowerName;
}

float Character::getPowerDamp() {
    return powerDamp;
}

bool Character::getSuperPowerUsed() {
    return superPowerUsed;
}

//Setters
void Character::setHealth(int pHealth) {
    health -= pHealth;
}

void Character::setPowerDamp(float pDamp) {
    powerDamp = pDamp;
}

void Character::setSuperPowerUsed(bool pSuperPowerUsed) {
    superPowerUsed = pSuperPowerUsed;
}

void Character::printCharacter() {
    std::cout << name << std::endl;
    std::cout << "Hero Type: " << type << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Primary Attack: " << primaryAttack << std::endl;
    std::cout << "Secondary Attack: " << secondaryAttack << std::endl;
}

string Character::characterToString() {
    return name + "\nHero Type: " + type + "\n"
    + "Health: " + to_string(health) + "\n"
    + "Primary Attack: " + to_string(primaryAttack) + "\n"
    + "Secondary Attack: " + to_string(secondaryAttack);
}