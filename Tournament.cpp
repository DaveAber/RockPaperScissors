#include "Tournament.h"

void Tournament::dumpPlayers()
{
    cout << "Tournament play, " << players.size() << " players:" << endl;
    for (MythicalCreature& player: players)
    {
        cout << "\t" << player.display() << endl;
    }
}