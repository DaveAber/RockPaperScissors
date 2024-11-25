#ifndef RPSGAME_H
#define RPSGAME_H

#include "creature.h"
#include "tournament.h"

// All creatures play against the group, single game
int groupPlay_RockPaperScissors(vector<Creature>&creatures);

// Two players from two teams play one game.
// Wins updated for both player and team
int matchPlay_RockPaperScissors(Team& team1, int player1Num,\
    Team& team2, int player2Num);

#endif  // RPSGAME_H