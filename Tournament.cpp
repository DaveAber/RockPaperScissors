#include "tournament.h"


int Team::lastID = 0;

void Team::dump()
{
    cout << "Team " << _id << " with " << members.size() << " players"
        << " won " << _gamesWon << " of " << _gamesPlayed << " matches:"<< endl;
    for (Creature& member: members)
    {
        cout << "\t" << member.display() << endl;
    }
}

void Tournament::dumpPlayers()
{
    cout << "Tournament play, " << players.size() << " players:" << endl;
    for (Creature& player: players)
    {
        cout << "\t" << player.display() << endl;
    }
}