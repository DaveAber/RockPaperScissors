#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <ctime>
#include <limits>
#include <sstream>

using namespace std;

int generate_probabilities(double p[3]);

class Creature
{
public:
    Creature(string name = "");
    ~Creature();

    int init_RPS_probabilities();
    int chooseRPS();    // 0 = Rock, 1 = Paper, 3 = Scissors
    int getCurrentChoice();
    void showChoice();
    int won();      // Won an individual player, returns total win count
    string setName(string name) {
        _name = name;
        return _name;
    }
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
    string display() {
        ostringstream os;
        os << getName() << " with RPS prob's of " << probStr() << " won " << getWinCount()
            << " of " << getGamesPlayed();
        return os.str();
    }

    static int _nextCreatureID;
    static bool _srandSeeded;

private:
    string _name;
    double _RPS_probabilities[3];
    int _gamesPlayed;
    int _gamesWon;
    int _curRPS_choice;
};

#endif  // CREATURE_H