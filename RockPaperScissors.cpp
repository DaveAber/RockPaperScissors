// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <limits>
#include <vector>

#include "MythicalCreature.h"
#include "RPS_Game.h"

using namespace std;


int main()
{
    std::cout << "Hello World!\n";
    double p[3];

    if (0)
    {
        generate_probabilities(p);

        cout << "Rock:\t\t" << p[0] << endl;
        cout << "Paper:\t\t" << p[1] << endl;
        cout << "Scissors:\t" << p[2] << endl;
    }

    // Create some creatures
    vector<MythicalCreature>creatures;

    creatures.resize(5);

    // Initialize the creatures RPS tenancies
    for (MythicalCreature& creature : creatures)
    {
        creature.init_RPS_probabilities();
    }
    for (MythicalCreature& creature : creatures)
    {
        creature.init_RPS_probabilities();
    }

    // Play some games
    for (int gameNum = 0; gameNum < 20; gameNum++)
    {
        play_RockPaperScissors(creatures);
    }

    for (MythicalCreature& creature : creatures)
        cout << creature.getName() << " with RPS prob's of " << creature.probStr() << " won " << creature.getWinCount() << " of " << creature.getGamesPlayed() << endl;


    return 0;
}


