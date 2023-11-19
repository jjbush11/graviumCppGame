//
// Created by James  Bush on 9/13/23.
//

#ifndef M1AP_VILLAIN_H
#define M1AP_VILLAIN_H

#include "Character.h"
#include <string>

/**
 * Villain class
 */
class Villain : public Character{

public:

    Villain(std::string pName, std::string pType);

    /**
     * Damps the opponents attacks for as long as villain is alive
     * @param opponent
     * @return
     */
    std::string superPower(Character* opponent) override;

private:
    bool superPowerUsed;
};

#endif //M1AP_VILLAIN_H
