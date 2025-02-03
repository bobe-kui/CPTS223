#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <iostream>
#include <string>
using namespace std;

class Command
{
    private:
        string m_command;
        string m_description;
        int m_points;
    public:
        Command();
        Command(string command, string description, int points);
        ~Command();

        string getCommand() const;
        string getDescription() const;
        int getPoints() const;

        void setCommand(string newCommand);
        void setDescription(string newDescription);
        void setPoints(int newPoints);

        friend ostream &operator<<(ostream &os, const Command &rhs)
        {
            os << rhs.getCommand() << " - " << rhs.getDescription() << " - " << rhs.getPoints() << endl;
            return os;
        }

        bool operator==(const Command &rhs) const
        {
            if(this->getCommand() == rhs.getCommand() && this->getDescription() == rhs.getDescription() && this->getPoints() == rhs.getPoints())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
};

Command::Command()
{
    this->m_command = "";
    this->m_description = "";
    this->m_points = 0;
}

Command::Command(string command, string description, int points)
{
    this->m_command = command;
    this->m_description = description;
    this->m_points = points;
}

Command::~Command()
{
    this->m_command = "";
    this->m_description = "";
    this->m_points = 0;
}

string Command::getCommand() const
{
    return this->m_command;
}

string Command::getDescription() const
{
    return this->m_description;
}

int Command::getPoints() const
{
    return this->m_points;
}

void Command::setCommand(string newCommand)
{
    this->m_command = newCommand;
}

void Command::setDescription(string newDescription)
{
    this->m_description = newDescription;
}

void Command::setPoints(int newPoints)
{
    this->m_points = newPoints;
}



#endif