#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <vector>
#include "MythicalCreature.h"


class Team
{
    static int lastID;
public:
    Team(): _gamesPlayed(0), _gamesWon(0) { _id = ++lastID; };
    ~Team() {};
    vector<MythicalCreature> members;

    // Add a player from the pool, to this particular team
    int addPlayer(MythicalCreature& player) {
        members.push_back(player);
        return members.size();
    }

    // Increment won count for the team
    int startGame() {
        return ++_gamesPlayed;
    }
    int won() {
        return ++_gamesWon;
    }
    int getGamesPlayed() const {
        return _gamesPlayed;
    }
    int getWinCount() const {
        return _gamesWon;
    }
    int getID() const {
        return _id;
    }

    void dump();

private:
    int _id;
    int _gamesPlayed;
    int _gamesWon;
};

class Tournament
{
    vector<MythicalCreature> players;
    vector<Team> teams;

public:
    Tournament() {};
    ~Tournament() {};

    // Players for the entire tournament.  Teams to be created from player pool, once all players added
    int addPlayer(MythicalCreature& player) {
        players.push_back(player);
        return players.size();
    }

    void dumpPlayers();
};

#endif  // TOURNAMENT_H