#ifndef DESTINATION_H
#define DESTINATION_H
#include <iostream>
#include <string>
using namespace std;


class Destination
{
    public:
        Destination();
        Destination(int newPosition, string newName);
        ~Destination();

        void printPosition();
        void printDestinationName();

        int getPosition() const;
        string getName() const;


        bool operator==(Destination const& rhs) const
        {
            if(rhs.name == this->name && rhs.position == this->position)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    private:
    int position;
    string name;


};

#endif