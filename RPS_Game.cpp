// RPS_Game.cpp : Play a hand of Rock Paper Scissors
//

#include <iostream>
#include <string>
#include <vector>

#include "MythicalCreature.h"
#include "RPS_Game.h"

using namespace std;

// All creatures play against the group, single game
int groupPlay_RockPaperScissors(vector<MythicalCreature>&creatures)
{
    // Assumes srand() has already been called
 
    // Have each creature make a RPS choice
    cout << "New Game:" << endl;
    for (int creatureNum = 0; creatureNum < (int)creatures.size(); creatureNum++)
    {
        creatures[creatureNum].chooseRPS();
        cout << "\t";
        creatures[creatureNum].showChoice();
    }

    // Rock beats scissors (0 vs 2), Scissors beats paper (2 vs 1), Paper beats rock (1 vs 0);
    // give credit for each time a choice of rock encounters a scissors, etc.
    for (MythicalCreature& creature1 : creatures)
    {
        // What does this creature beat
        int beats = (creature1.getCurrentChoice() + 2) % 3;
        for (int creatureNum2 = 0; creatureNum2 < (int)creatures.size(); creatureNum2++)
        {
            if (creatures[creatureNum2].getCurrentChoice() == beats)
            {
                creature1.won();
                cout << creature1.getName() << " beat " << creatures[creatureNum2].getName() << endl;
            }
        }
    }

    return 0;
}

// Two players from two teams play one game.
// Wins updated for both player and team
// Return 0 on success
int matchPlay_RockPaperScissors(Team& team1, int player1Num,\
    Team& team2, int player2Num)
{
    // Make sure player numbers are legit
    if (! (0 <= player1Num && player1Num < (int)team1.members.size()))
    {
        cerr << "matchplay_RockPaperScissors() called with invalid "
            << "team 1 player num: " << player1Num << endl;
        return -1;
    }
    if (! (0 <= player2Num  && player2Num < (int)team2.members.size()))
    {
        cerr << "matchplay_RockPaperScissors() called with invalid "
            << "team 2 player num: " << player1Num << endl;
        return -1;
    }

    // Assumes srand() has already been called
 
    // Have each creature make a RPS choice
    team1.startGame();
    team2.startGame();
    cout << "New Game:" << endl;

    // Repeat until someone wins:
    do {
        team1.members[player1Num].chooseRPS();
        cout << "\tTeam " << team1.getID() << ": ";
        team1.members[player1Num].showChoice();
        team2.members[player2Num].chooseRPS();
        cout << "\tTeam " << team2.getID() << ": ";
        team2.members[player2Num].showChoice();

        int oneBeats = (team1.members[player1Num].getCurrentChoice() + 2) % 3;
        int twoBeats = (team2.members[player2Num].getCurrentChoice() + 2) % 3;

        if (team2.members[player2Num].getCurrentChoice() == oneBeats) {
            team1.members[player1Num].won();
            team1.won();
            cout << "Team " << team1.getID() << " player "
                << team1.members[player1Num].getName()
                << " won" << endl;
            return 0;
        }
        if (team1.members[player1Num].getCurrentChoice() == twoBeats) {
            team2.members[player2Num].won();
            team2.won();
            cout << "Team " << team2.getID() << " player "
                << team2.members[player2Num].getName()
                << " won" << endl;
            return 0;
        }
        cout << "Draw.  Trying again:" << endl;
    } while (true);

    return 0;
}