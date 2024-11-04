#pragma once

#include <iostream>
#include <ctime>
#include <limits>

using namespace std;

int generate_probabilities(double p[3]);

class MythicalCreature
{
public:
    MythicalCreature(string name = "");
    ~MythicalCreature();

    int init_RPS_probabilities();
    int chooseRPS();    // 0 = Rock, 1 = Paper, 3 = Scissors
    int getCurrentChoice();
    int won();      // Won an individual player, returns total win count
    string getName() {
        return _name;
    }
    int getWinCount() {
        return _gamesWon;
    }
    int getGamesPlayed() {
        return _gamesPlayed;
    }
    string probStr();
    static int _nextCreatureID;
    static bool _srandSeeded;

private:
    string _name;
    double _RPS_probabilities[3];
    int _gamesPlayed;
    int _gamesWon;
    int _curRPS_choice;
};
