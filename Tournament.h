#pragma once

#include <vector>
#include "MythicalCreature.h"
#include "RPS_Game.h"

class Tournament
{
    vector<MythicalCreature> players;

public:
    Tournament() {};
    ~Tournament() {};

    int addPlayer(MythicalCreature& player) { players.push_back(player); return players.size(); }

    void dumpPlayers();
};

