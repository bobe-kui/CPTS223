#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
using namespace std;

class Player
{
    private:
    
    string m_name;
    int m_points;
    int m_questions;

    public: 
    Player();
    Player(string name, int points, int questions);
    ~Player();

    string getName() const;
    int getPoints() const;
    int getQuestions() const;
    void setName(string newName);
    void setPoints(int newPoints);
    void setQuestions(int newQuestions);


        friend ostream &operator<<(ostream &os, const Player &rhs)
    {
        os << rhs.getName() << endl;
        return os;
    }
    
};


Player::Player()
{
    this->m_name = "";
    this->m_points = 0;
    this->m_questions = 0;
}

Player::Player(string name, int points, int questions)
{
    this->m_name = name;
    this->m_points = points;
    this->m_questions = questions;
}

Player::~Player()
{
    this->m_name = "";
    this->m_points = 0;
    this->m_questions = 0;
}

string Player::getName() const
{
    return this->m_name;
}

int Player::getPoints() const
{
    return this->m_points;
}

int Player::getQuestions() const
{
    return this->m_questions;
}

void Player::setName(string newName)
{
    this->m_name = newName;
}

void Player::setPoints(int newPoints)
{
    this->m_points = newPoints;
}

void Player::setQuestions(int newQuestions)
{
    this->m_questions = newQuestions;
}

#endif