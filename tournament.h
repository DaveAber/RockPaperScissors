#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <vector>
#include "creature.h"


class Team
{
    static int lastID;
public:
    Team(): _gamesPlayed(0), _gamesWon(0), _disabled(false) { _id = ++lastID; };
    ~Team() {};
    vector<Creature> members;

    // Add a player from the pool, to this particular team
    int addPlayer(Creature& player) {
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
    bool disablePlay() {
        _disabled = true;
        return _disabled;
    }
    bool isDisabled() {
        return _disabled;
    }
    int setWinCount(int wins) { // For testing of a tie
        return _gamesWon = wins;
    }

    void dump();

private:
    int _id;
    int _gamesPlayed;
    int _gamesWon;
    bool _disabled;
};

class Tournament
{
    vector<Creature> players;
    vector<Team> teams;

public:
    Tournament() {};
    ~Tournament() {};

    // Players for the entire tournament.  Teams to be created from player pool, once all players added
    int addPlayer(Creature& player) {
        players.push_back(player);
        return players.size();
    }

    // Make teams from the pool of players
    int makeTeams();

    // Have teams play games
    int teamPlay();

    void dumpPlayers();

    void showResults();

    int num_active_teams() {
        int active_teams = 0;
        for (Team& team: teams) {
            if (! team.isDisabled())
                active_teams++;
        }
        return active_teams;
    }
};

#endif  // TOURNAMENT_H