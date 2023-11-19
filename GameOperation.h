//
// Created by James  Bush on 9/14/23.
//

#ifndef M1AP_GAMEOPERATION_H
#define M1AP_GAMEOPERATION_H

#include "Hero.h"
#include "Villain.h"
#include <string>
#include <vector>

/**
 * Methods for moving the game along
 */
class GameOperation {

public:

    GameOperation();

    /**
     * Introduces games and gives brief background of lore
     */
    void startUpMenu();

    /**
     * prints out number menu, showing user what input each number will do
     * @param pMenuOptions
     */
    void selectMenu(std::vector<std::string> pMenuOptions);

    /**
     * gets integer user input from user
     * @param numOfOptions
     * @return int
     */
    static int getIntFromUser(int numOfOptions);

    /**
     * gets name string from user, used to get desried name for new hero
     * @return string
     */
    std::string getNameFromUser();

    /**
     * gets type of hero from user, types are:
     * Avatar (as in Avavtar The Lasrt AirBender)
     * Avenger (as in Marvel)
     * Jedi (as in Star Wars)
     * Matrix (as in the The Matrix)
     * @param pHeroTypes
     * @return string
     */
    std::string getTypeFromUser(std::vector<std::string> pHeroTypes);

    /**
     * Performs simple battle between the hero and villain teams
     * @param heroes
     * @param villains
     */
    void battle(std::vector<Hero> heroes, std::vector<Villain> villains);

};

#endif //M1AP_GAMEOPERATION_H
