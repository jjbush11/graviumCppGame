//
// Created by James  Bush on 9/14/23.
//

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <random>

#include "GameOperation.h"
using namespace std;

GameOperation::GameOperation() {}

void GameOperation::startUpMenu() {
    cout << "Welcome to 'Gravium: Defense Against The Obsidian'" << endl;
    cout << "Your goal is build a team to defeat the The Obsidian" << endl;
    cout << "The Obsidian is a group of the most powerful villains in existence.\n"
            "At their formation, their goal was to gain control of a previously undiscovered island that is home to\n"
            "an extensive supply of Gravium, a precious metal that gives its holder the power to manipulate gravity.\n"
            "Build your team and begin the battle against The Obsidian!" << endl;
}

void GameOperation::selectMenu(vector<string> menuOptions) {
    for (int i=0; i<menuOptions.size(); ++i){
        cout << menuOptions[i] << endl;
    }
}

int GameOperation::getIntFromUser(int numOfOptions) {

    //User prompts
    string prompt = "Enter a number (0-" + to_string(numOfOptions-1) + "): ";
    string invalidInput = "Invalid input. ";
    string noInput = "No input. ";

    string static userInput;
    int userInputInt;
    stringstream ss;

    cout << prompt;
    getline(cin, userInput);

    if (userInput.empty() || userInput == " ") {//Make sure input is not blank
        cout << noInput;
        getIntFromUser(numOfOptions);
    } else { //Makes sure input can be converted to an int and doesn't have non-numeric values with the number
        try {
            int inputToInt = stoi(userInput);
            if (to_string(inputToInt).length() != userInput.length()){ //by checking length ensures invalid messages shows when 45 hgh is entered
                cout << invalidInput;
                getIntFromUser(numOfOptions);
            }
        } catch (invalid_argument& e) {
            cout << invalidInput;
            getIntFromUser(numOfOptions);
        }
    }

    if (stoi(userInput) >  numOfOptions) {
        cout << invalidInput;
        getIntFromUser(numOfOptions);
    }

    ss << userInput;
    ss >> userInputInt;

    return userInputInt;
}

/**
 * get word from user
 * @return string
 */
string GameOperation::getNameFromUser() {

    //User prompts
    string prompt = "Enter a name for your Hero: ";
    string invalidInput = "Invalid input. ";
    string noInput = "No input. ";

    string static userInput;

    cout << prompt;
    getline(cin, userInput);

    if (userInput.empty() || userInput == " ") { //Make sure input is not blank
        cout << noInput;
        getNameFromUser();
    } else if (userInput.length()<=1){ //Make sure input is at least one char
        cout << invalidInput;
        getNameFromUser();
    } else { //Checks that input is not a number
        try {
            stoi(userInput);
            cout << invalidInput;
            getNameFromUser();
        } catch (invalid_argument& e) {}
    }

    return userInput;
}

/**
 * get type of hero from user
 * @return string
 */
string GameOperation::getTypeFromUser(vector<string> heroTypes) {

    //User prompts

    string prompt = "Hero Types: Avatar, Jedi, Avenger, Matrix.\n"
                    "Enter a hero type: ";
    string invalidInput = "Invalid input. ";
    string noInput = "No input. ";

    string static userInput;
    bool match = false;

    cout << prompt;
    getline(cin, userInput);

    if (userInput.empty() || userInput == " ") { //Make sure input is not blank
        cout << noInput;
        getTypeFromUser(heroTypes);
    } else{ //Check that user input matches needed type
        for (int i=0; i<heroTypes.size(); ++i){
            if (userInput == heroTypes[i]){
                match = true;
            }
        }
    }

    if(!match){
        cout << invalidInput;
        getTypeFromUser(heroTypes);
    }

    return userInput;
}

void GameOperation::battle(vector<Hero> heroes, vector<Villain> villains) {
    int heroIndex = 0, villainIndex = 0, userAttackOp, randNum;
    bool heroSuperPowerFlag = false, villainSuperPowerUsed = false;

    cout << heroes[heroIndex].getName() << " is enter battle against " << villains[villainIndex].getName() << "!\n" << endl;
    while (heroIndex < heroes.size() && villainIndex < villains.size()){

        // When the superpower is used once, no one else on the team can use theirs
        if(heroes[heroIndex].getSuperPowerUsed()) {
            heroSuperPowerFlag = true;
        }
        if(villains[villainIndex].getSuperPowerUsed()) {
            villainSuperPowerUsed = true;
        }

        // User option  menu
        cout << "Choose attack! Current energy level: " << heroes[heroIndex].getEnergy() << endl;
        cout << "0: Primary Attack (-3 energy): " << heroes[heroIndex].getPrimaryAttack() << endl;
        cout << "1: Secondary Attack (-1 energy): " << heroes[heroIndex].getSecondaryAttack() << endl;

        // Offer a third option if superpower hasn't been used
        if(!heroSuperPowerFlag){
            cout << "2: Super Power (can only be used once)" << endl;
            userAttackOp = GameOperation::getIntFromUser(3);
        } else {
            userAttackOp = GameOperation::getIntFromUser(2);
        }

        // Subtract the hero's attack power from the villain's health
        if (userAttackOp == 0) {
            cout << "\n" << heroes[heroIndex].getName() << " does " + to_string(heroes[heroIndex].getPrimaryAttack());
            villains[villainIndex].setHealth(heroes[heroIndex].getPrimaryAttack());
            heroes[heroIndex].setEnergy(3);
            cout << " units of damage!" << endl;
        } else if (userAttackOp == 1){
            cout << "\n" << heroes[heroIndex].getName() << " does " + to_string(heroes[heroIndex].getSecondaryAttack());
            villains[villainIndex].setHealth(heroes[heroIndex].getSecondaryAttack());
            heroes[heroIndex].setEnergy(1);
            cout << " units of damage!" << endl;
        } else if (userAttackOp == 2) {
            cout << "\n" << heroes[heroIndex].superPower(&villains[villainIndex]) << endl;
        }

        // Get random number for each villain move
        random_device rand;
        mt19937 gen(rand());
        if(!villainSuperPowerUsed) {
            uniform_int_distribution<int> distribution(0, 2);
            randNum = distribution(gen);
        } else {
            uniform_int_distribution<int> distribution(0, 1);
            randNum = distribution(gen);
        }

        // Actions for the villain depending on random number
        if (randNum == 0){
            cout << villains[villainIndex].getName() << " does " + to_string(heroes[heroIndex].getPrimaryAttack());
            heroes[heroIndex].setHealth(heroes[heroIndex].getPrimaryAttack());
            cout << " units of damage!\n" << endl;
        } else if (randNum == 1){
            cout << villains[villainIndex].getName() << " does " + to_string(heroes[heroIndex].getSecondaryAttack());
            heroes[heroIndex].setHealth(heroes[heroIndex].getSecondaryAttack());
            cout << " units of damage!\n" << endl;
        } else if (randNum == 2) {
            cout << "\n" << villains[villainIndex].superPower(&heroes[heroIndex]) << endl;
        }

        // Print out remaining health of each character
        cout << heroes[heroIndex].getName() << " has " + to_string(heroes[heroIndex].getHealth()) + " remaining health." << endl;
        cout << villains[villainIndex].getName() << " has " + to_string(villains[villainIndex].getHealth()) + " remaining health.\n" << endl;

        // If character has been defeated, another character enters the battle
        if (heroes[heroIndex].getHealth() <= 0){
            cout << heroes[heroIndex].getName() + " has been defeated!" << endl;
            if (heroIndex < heroes.size()){
                ++heroIndex;
                cout << heroes[heroIndex].getName() + " has entered the battle!\n" << endl;
            }
        }
        if (villains[villainIndex].getHealth() <= 0){
            cout << villains[villainIndex].getName() + " has been defeated!" << endl;
            if (villainIndex < villains.size()){
                ++villainIndex;
                cout << villains[villainIndex].getName() + " has entered the battle!\n" << endl;
            }
        }
    }
}
