#pragma once

#include <vector>
#include "MythicalCreature.h"
#include "RPS_Game.h"

class Team
{
public:
    Team() {};
    ~Team() {};
    vector<MythicalCreature> members;

    // Add a player from the pool, to this particular team
    int addPlayer(MythicalCreature& player) { members.push_back(player); return members.size(); }

    void dumpPlayers();
};

class Tournament
{
    vector<MythicalCreature> players;
    vector<Team> teams;

public:
    Tournament() {};
    ~Tournament() {};

    // Players for the entire tournament.  Teams to be created from player pool, once all players added
    int addPlayer(MythicalCreature& player) { players.push_back(player); return players.size(); }

    void dumpPlayers();
};

