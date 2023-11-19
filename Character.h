//
// Created by James  Bush on 10/3/23.
//

#ifndef M1OP_CHARACTER_H
#define M1OP_CHARACTER_H

#include <string>
#include <iostream>

class Character {
public:

    Character();

    //Getters
    std::string getName();
    std::string getType();
    std::string getSuperPowerName();
    int getHealth();
    int getPrimaryAttack();
    int getSecondaryAttack();
    float getPowerDamp();
    bool getSuperPowerUsed();

    //Setters
    void setHealth(int pHealth);
    void setPowerDamp(float pDamp);
    void setSuperPowerUsed(bool pSuperPowerUsed);

    /**
     * prints out character in the following format:
     * Name
     * Character Type: type
     * Health: health
     * Primary Attack: primaryAttack
     * Secondary Attack: secondaryAttack
     */
    void printCharacter();

    /**
     * returns a string of the character information in the following format:
     * Name
     * Character Type: type
     * Health: health
     * Primary Attack: primaryAttack
     * Secondary Attack: secondaryAttack
     * @return
     */
    std::string characterToString();

    /**
     * User is allowed to use one super power per battle
     * Each derived class will have a unique super power
     * @return
     */
    virtual std::string superPower(Character* opponent) = 0;

protected:
    std::string name;
    std::string type;
    std::string superPowerName;
    int health;
    int primaryAttack;
    int secondaryAttack;
    int energy;
    float powerDamp;
    bool superPowerUsed;
};

#endif //M1OP_CHARACTER_H
