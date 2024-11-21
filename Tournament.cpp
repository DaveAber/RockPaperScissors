#include "Tournament.h"


void Team::dumpPlayers()
{
    cout << "Team with " << members.size() << " players:" << endl;
    for (MythicalCreature& members: members)
    {
        cout << "\t" << members.display() << endl;
    }
}


void Tournament::dumpPlayers()
{
    cout << "Tournament play, " << players.size() << " players:" << endl;
    for (MythicalCreature& player: players)
    {
        cout << "\t" << player.display() << endl;
    }
}