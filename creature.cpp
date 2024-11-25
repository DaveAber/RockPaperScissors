// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <random>
#include <limits>

#include "creature.h"

using namespace std;

string RPS(int choice)
{
    switch (choice) {
        case 0:
        return "Rock";
        case 1:
        return "Paper";
        case 2:
        return "Scissors";
        default:
        return "Unknown";
    }
    return "";
}

int generate_probabilities(double p[3])
{
    // Assume srand() has already been called

    // Generate random probabilities for the 3
    double total = 0.0;
    for (int i = 0; i < 3; i++)
    {
        p[i] = static_cast<double>(rand()) / static_cast<double>(numeric_limits<int>::max());
        total += p[i];
    }

    // Normalize
    for (int i = 0; i < 3; i++)
    {
        p[i] /= total;
    }

    return 0;
}


int Creature::_nextCreatureID = 0;
bool Creature::_srandSeeded = 0;

Creature::Creature(string name):
    _name(name), _gamesPlayed(0), _gamesWon(0), _curRPS_choice(-1)
{
    ostringstream os;
    os << "Creature #" << _nextCreatureID++;
    _name = os.str();
}

Creature::~Creature()
{
    //cout << "Destroying: " << _name << endl;
}

int Creature::init_RPS_probabilities()
{
    if (!_srandSeeded)
    {
        // use current time as seed for random generator
        time_t timeseed = time(NULL);
        srand((unsigned int)timeseed);
        _srandSeeded = true;
    }

    generate_probabilities(_RPS_probabilities);
    return 0;
}

int Creature::chooseRPS()
{
    _gamesPlayed++;         // Consider this a game played

    // Assume srand has already been called

    // From a new random number, figure out where in the spectrum of the 3 accumulated probabilities
    // it falls
    double p = static_cast<double>(rand());
    p /= static_cast<double>(numeric_limits<int>::max());

    double rps_total = 0.0;
    for (int i = 0; i < 3; i++)
    {
        rps_total += _RPS_probabilities[i];
        if (p <= rps_total)
        {
            _curRPS_choice = i;
            return _curRPS_choice;
        }
    }
    return -1;  // Something went wrong
}

void Creature::showChoice()
{
    cout << _name << ": picked " << RPS(_curRPS_choice) << endl;
}

int Creature::getCurrentChoice()
{
    return _curRPS_choice;
}

int Creature::won()
{
    return ++_gamesWon;
}

string Creature::probStr()
{
    ostringstream os;
    os << this->_RPS_probabilities[0] << "," << this->_RPS_probabilities[1] << "," << this->_RPS_probabilities[2];
    return os.str();
}