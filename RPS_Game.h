#ifndef RPS_GAME_H
#define RPS_GAME_H

#include "MythicalCreature.h"
#include "Tournament.h"

// All creatures play against the group, single game
int groupPlay_RockPaperScissors(vector<MythicalCreature>&creatures);

// Two players from two teams play one game.
// Wins updated for both player and team
int matchPlay_RockPaperScissors(Team& team1, int player1Num,\
    Team& team2, int player2Num);

#endif  // RPS_GAME_H