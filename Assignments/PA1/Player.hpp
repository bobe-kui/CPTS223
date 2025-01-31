#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
using namespace std;

class Player
{
    private:
    
    string name;
    int points;

    public: 
    Player();
    Player(string name, int points);
    ~Player();

    
};

#endif