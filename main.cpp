#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Hero.h"
#include "Villain.h"
#include "GameOperation.h"

using namespace std;

//Struct of defualt hero team
struct GoodGuys {
    Hero hero1;
    Hero hero2;
    Hero hero3;
    Hero hero4;

    GoodGuys() : hero1("Kora", "Avatar"),
                 hero2("Luke Skywalker", "Jedi"),
                 hero3("Wanda", "Avenger"),
                 hero4("Trinity", "Matrix") {}
};

//struct of defauklt villain team
struct BadGuys {
    Villain villain1;
    Villain villain2;
    Villain villain3;
    Villain villain4;

    BadGuys() : villain1("Ozai", "Fire Lord"),
                 villain2("Darth Vader", "Sith"),
                 villain3("Thanos", "Thanos"),
                 villain4("Agent Smith", "Agent") {}
};

// Different OSs use different CLI commands to run Python
#ifdef _WIN32
// If your Windows machine runs Python in CLI with "python" instead of "py", update this line.
const string python = "py";
#else
// If your Mac/Linux machine runs Python in CLI with "python3" instead of "python", update this line.
const string python = "python3";
#endif

int main() {
    //Keeps the while loop going unless quit is selected
    bool keepPlaying = true;

    //Vectors
    vector<string> heroTypes = {"Avatar", "avatar", "Jedi", "jedi", "Avenger", "avenger", "Matrix", "matrix"};
    vector<string> menuOptions = {"1: View your team.", "2: Create a new team.", "3: Battle!","0: Quit."};
    vector<string> createTeamOptions = {"1: Create a new team.", "2: View current Hero list.", "0: Go Back."};
    vector<string> lookingAtHeroesMenu = {"1: Continue.", "0: Back to main menu."};
    vector<string> goingIntoBattleMenu = {"1: Yes!", "0: No I'm scared..."};



    //Vector of heros, used to print out heros
    GoodGuys defualtGoodGuys;
    vector<Hero> heroes = {defualtGoodGuys.hero1, defualtGoodGuys.hero2, defualtGoodGuys.hero3, defualtGoodGuys.hero4};

    //Vector of villains
    BadGuys defualtBadGuys;
    vector<Villain> villains = {defualtBadGuys.villain1, defualtBadGuys.villain2, defualtBadGuys.villain3, defualtBadGuys.villain4};

    GameOperation game = GameOperation();
    game.startUpMenu(); //display start menu

    while(keepPlaying){
        game.selectMenu(menuOptions);
        int userInput = GameOperation::getIntFromUser(menuOptions.size());
        string command;
        if (userInput == 1){ //print out current hero team
            for (int i=0; i<heroes.size(); ++i){
                cout << "-----------------------" << endl;
                heroes[i].printCharacter();
                command = python + " ../art.py " + heroes[i].getType();
                system(command.c_str());
            }
            cout << "-----------------------" << endl;
        } else if (userInput == 2){ //create new hero team
            game.selectMenu(createTeamOptions);
            int userTeamChoice = GameOperation::getIntFromUser(createTeamOptions.size());

            if(userTeamChoice == 1){
                for (int i=0; i<heroes.size(); ++i){
                    ofstream outFile("../Heroes.txt", ios::app);
                    string name = game.getNameFromUser();
                    string type = game.getTypeFromUser(heroTypes);
                    heroes[i] = Hero(name, type);
                    outFile << heroes[i].characterToString() + "\n" << endl;
                    outFile.close();
                }
                cout << "Team of Heroes created!" << endl;
            } else if (userTeamChoice == 2){
                cout << "\n";
                ifstream outFile("../Heroes.txt", ios::in); //open file in read mode
                string line;
                int count = 1;
                while (getline(outFile, line)){
                    cout << line << endl;

                    // Prints out only 2 at time, asks user if they want to see more or quit
                    if (line == "" && count % 4 == 0){
                        game.selectMenu(lookingAtHeroesMenu);
                        int seeMore = GameOperation::getIntFromUser(lookingAtHeroesMenu.size());
                        if (seeMore == 0){
                            cout << "\n";
                            break;
                        }
                        cout << "\n";
                    }
                    ++count;
                }
                cout << "\nHeroes displayed!\nBack to main menu...\n" << endl;
            } else if (userTeamChoice == 0){
                cout << "<-- <--\n" << endl;
            }
        } else if (userInput == 3){
            for (int i=0; i<heroes.size(); ++i){
                cout << "-----------------------" << endl;
                heroes[i].printCharacter();
            }
            cout << "\nThis is your team, are you ready to battle?" << endl;
            game.selectMenu(goingIntoBattleMenu);
            int userBattleInput = GameOperation::getIntFromUser(goingIntoBattleMenu.size());

            if(userBattleInput==1){
                game.battle(heroes, villains);
            } else if (userBattleInput == 0){
                cout << "<-- <--\n" << endl;
            }

        } else if (userInput == 0){ //quit
            keepPlaying = false;
        }
    }

    return 0;
}