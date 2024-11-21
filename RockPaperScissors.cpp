// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <limits>
#include <vector>

#include "MythicalCreature.h"
#include "RPS_Game.h"
#include "Tournament.h"

using namespace std;


int main()
{
    std::cout << "Hello World!\n";
    double p[3];
    enum GamePlay {
        GP_GROUP,
        GP_TOURNAMENT
    } gamePlay = GP_TOURNAMENT;

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

    // Give the creatures their names
    creatures[0].setName("Bubblocto");
    creatures[1].setName("Skyfin");
    creatures[2].setName("Akama");
    creatures[3].setName("Bearmantle");
    creatures[4].setName("Gelbin");

    // Initialize the creatures RPS tenancies
    for (MythicalCreature& creature : creatures)
    {
        creature.init_RPS_probabilities();
    }

    if (gamePlay == GP_GROUP)
    {
        // Play some games
        for (int gameNum = 0; gameNum < 20; gameNum++)
        {
            play_RockPaperScissors(creatures);
        }

        // Tally the wins
        int totalWins = 0;
        for (MythicalCreature& creature : creatures)
            totalWins += creature.getWinCount();

        for (MythicalCreature& creature : creatures)
            cout << creature.getName() << " with RPS prob's of " << creature.probStr() << " won " << creature.getWinCount() << " of " << creature.getGamesPlayed() << endl;

        cout << "Total wins: " << totalWins << endl;
    } else if (gamePlay == GP_TOURNAMENT)
    {
        Tournament tourney;

        // Add all the players
        for (MythicalCreature& creature: creatures)
        {
            tourney.addPlayer(creature);
        }
        tourney.dumpPlayers();

    }
    
    return 0;
}


