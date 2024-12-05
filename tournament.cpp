#include "tournament.h"
#include "rpsgame.h"


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

// Make teams from the pool of players
int Tournament::makeTeams()
{
    const int MAX_TEAMS=8;
    bool teamChoices[MAX_TEAMS];
    size_t num_teams = MAX_TEAMS;
    // From the number of players, decide the # teams such that there are up to 8 teams
    if (players.size() / 2 < num_teams)
        num_teams = players.size() / 2;
    teams.resize(num_teams);

    int poolSize = 0;   // Used to help trigger resetting pool in loop
    size_t team_num;       // Team number picked
    // Create a team with each player
    for (Creature& player : players)
    {
        // Generate a pool of teams left to pick from, if needed
        if (poolSize == 0) {
            for (size_t i = 0; i < num_teams; i++)
                teamChoices[i] = true;  // Team left to be picked
            poolSize = num_teams;
        }

        // Pick a random team
        team_num = makeRand(num_teams);

        // Use this team_num or the next one not picked from the pool
        while (teamChoices[team_num] == false) {
            team_num++;
            if (team_num >= num_teams)
                team_num = 0;
        }

        // Remove from the pool
        teamChoices[team_num] = false, poolSize--;

        teams[team_num].addPlayer(player);
    }
    return 0;
}

    // Have teams play games
int Tournament::teamPlay()
{
    // Play some games.  Each player from each team will play each player from the other team.
    // All teams will play all other teams.

    for (size_t teamA=0; teamA < teams.size(); teamA++)
    {
        if (teams[teamA].isDisabled())
            continue;
        for (size_t teamB=teamA+1; teamB < teams.size(); teamB++)
        {
            if (teams[teamB].isDisabled())
                continue;
            for (size_t playerA=0; playerA < teams[teamA].members.size(); playerA++)
            {
                for (size_t playerB=0; playerB < teams[teamB].members.size(); playerB++)
                {
                    matchPlay_RockPaperScissors(teams[teamA], playerA, teams[teamB], playerB);
                }
            }
        }
    }

    // Find the most wins for a team
    Team* winningTeam = nullptr;
    int mostWins = 0;
    for (Team& team: teams) {
        if (team.getWinCount() > mostWins) {
            mostWins = team.getWinCount();
            winningTeam = &team;
        }
    }

    bool force_a_tie = num_active_teams() > 2;

    // Check for a single winning team; disable any known losing teams in case we need
    // to run another mini-tournament
    int num_winning_teams = 0;
    for (Team& team: teams) {
        if (force_a_tie && team.getID() != winningTeam->getID()) {
            team.setWinCount(mostWins);
            force_a_tie = false;
        }
        if (team.getWinCount() == mostWins) {
            num_winning_teams++;
        } else {
            team.disablePlay(); // Won't be included in a mini-tournament
        }
    }

    // Do we need a mini-tournament?
    if (num_winning_teams > 1) {
        teamPlay();
    }

    return 0;
}

void Tournament::showResults()
{
    Team* winningTeam = nullptr;
    int mostWins = 0;
    for (Team& team: teams) {
        if (team.isDisabled())
            continue;
        team.dump();
        if (team.getWinCount() > mostWins) {
            mostWins = team.getWinCount();
            winningTeam = &team;
        }
    }

    // Double check that another team didn't tie
    for (Team& team: teams) {
        if (team.isDisabled())
            continue;
        if (team.getID() != winningTeam->getID()) {
            if (team.getWinCount() >= mostWins) {
                cout << "TYING TEAM: " << team.getID() << " has " << team.getWinCount() << " wins" << endl;
            }
        }
    }
    cout << "Team " << winningTeam->getID() << " won with " << mostWins << " wins!" << endl;
}