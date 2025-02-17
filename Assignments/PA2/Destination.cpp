#include "Destination.h"

Destination::Destination()
{
    this->position = 0;
    this->name = "";
}

Destination::Destination(int newPosition, string newName)
{
    this->position = newPosition;
    this->name = newName;
}

Destination::~Destination()
{

}

void Destination::printPosition()
{
    cout << this->position;
}

void Destination::printDestinationName()
{
    cout << this->name;
}

int Destination::getPosition() const
{
    return this->position;
}

string Destination::getName() const
{
    return this->name;
}