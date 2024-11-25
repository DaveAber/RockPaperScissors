// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <limits>
#include <vector>

#include "creature.h"
#include "rpsgame.h"
#include "tournament.h"

using namespace std;


int main()
{
    std::cout << "Hello World!\n";
    enum GamePlay {
        GP_GROUP,
        GP_TOURNAMENT
    } gamePlay = GP_TOURNAMENT;

    // Seed random number generator
    srand(time(nullptr));

    // Create some creatures
    vector<Creature>creatures;

    creatures.resize(5);

    // Give the creatures their names
    creatures[0].setName("Bubblocto");
    creatures[1].setName("Skyfin");
    creatures[2].setName("Akama");
    creatures[3].setName("Bearmantle");
    creatures[4].setName("Gelbin");

    // Initialize the creatures RPS tenancies
    for (Creature& creature : creatures)
    {
        creature.init_RPS_probabilities();
    }

    if (gamePlay == GP_GROUP)
    {
        // Play some games
        for (int gameNum = 0; gameNum < 20; gameNum++)
        {
            groupPlay_RockPaperScissors(creatures);
        }

        // Tally the wins
        int totalWins = 0;
        for (Creature& creature : creatures)
            totalWins += creature.getWinCount();

        for (Creature& creature : creatures)
            cout << creature.getName() << " with RPS prob's of " << creature.probStr() << " won " << creature.getWinCount() << " of " << creature.getGamesPlayed() << endl;

        cout << "Total wins: " << totalWins << endl;
    } else if (gamePlay == GP_TOURNAMENT)
    {
        Tournament tourney;

        // Add all the players
        for (Creature& creature: creatures)
        {
            tourney.addPlayer(creature);
        }
        tourney.dumpPlayers();

        // Test code for tournament game 1 team player vs 1 team player
        {
            vector<Team> teams;
            // Create a team with each player
            for (Creature& creature : creatures)
            {
                Team team;
                team.addPlayer(creature);
                teams.push_back(team);
            }

            // For each pair of teams, have them play just their first
            // (and only) player
            for (int team1Num=0; team1Num < int(teams.size()); team1Num++)
            {
                 for (int team2Num=team1Num+1; team2Num < int(teams.size()); team2Num++)
                 {
                    matchPlay_RockPaperScissors(teams[team1Num], 0,
                        teams[team2Num], 0);
                 }
            }

            // Dump wins
            for (Team& team: teams)
            {
                team.dump();
            }
        }

        // Run a tournament
        // tourney.runTournament(parameters)

    }
    
    return 0;
}