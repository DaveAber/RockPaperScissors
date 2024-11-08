// RPS_Game.cpp : Play a hand of Rock Paper Scissors
//

#include <iostream>
#include <string>
#include <vector>

#include "MythicalCreature.h"
#include "RPS_Game.h"

using namespace std;

int play_RockPaperScissors(vector<MythicalCreature>&creatures)
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
