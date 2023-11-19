//
// Created by James  Bush on 9/12/23.
//

#ifndef M1AP_HERO_H
#define M1AP_HERO_H

#include "Character.h"
#include <string>
#include <iostream>

/**
 * Hero class
 */
class Hero : public Character{

public:

    Hero(std::string pName, std::string pType);

    int getEnergy();
    void setEnergy(int pEnergy);

    /**
     *
     * @return
     */
    std::string superPower(Character* opponent) override;

};

#endif //M1AP_HERO_H
