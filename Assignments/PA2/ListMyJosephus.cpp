#include "ListMyJosephus.h"
#include <iostream>
#include <list>
#include <string> 

ListJosephus::ListJosephus()
{
    this->listM = 0;
    this->listN = 0;
    this->listDestinations.clear();
}

ListJosephus::ListJosephus(int newM, int newN)
{
    this->listM = newM;
    this->listN = newN;
    this->listDestinations.clear();
    cout << "List created, M = " << newM << " and N = " << newN << endl;
}

ListJosephus::~ListJosephus()
{
    this->clear();
}

void ListJosephus::clear()
{
    this->listDestinations.clear();
}

int ListJosephus::currentSize()
{
    return this->listDestinations.size();
}

bool ListJosephus::isEmpty()
{
    return this->listDestinations.empty();
}

void ListJosephus::printAllDestinations()
{
    for(Destination printDest : listDestinations)
    {
        printDest.printDestinationName(); 
        cout << endl;
    }
}

list<Destination> ListJosephus::getDestinations() const
{
    return this->listDestinations;
}

void ListJosephus::loadDestinations()
{
    ifstream infile("destinations.csv", ios::in);
    if(infile)
    {
        string destination = "";
        int position = 0;
        int destCount = 1;
        while(getline(infile, destination, ';'))
        {
            Destination *newDest = new Destination(position, destination);
            this->listDestinations.push_back(*newDest);
            destCount++;
            position++;
            if(destCount > this->listN)
            {
                break;
            }    
        }
        infile.close();
    }
}

int ListJosephus::eliminateDestination(list<Destination>::iterator &currentItem)
{
    list<Destination>::iterator tempItem;
    int i = 0, deletePos = 0;
    while(i < this->listM)
    {
        if(currentItem == --this->listDestinations.end())
        {
            currentItem = this->listDestinations.begin();
            i++;
        }
        else{
            ++currentItem;
            i++;
        }
    }
    tempItem = currentItem;
    deletePos = tempItem->getPosition();

    currentItem = this->listDestinations.erase(tempItem);
    if(currentItem == --this->listDestinations.end() || currentItem == this->listDestinations.end() )
    {
        currentItem = this->listDestinations.begin();
    } 
    return deletePos;
}

list<Destination>::iterator ListJosephus::pickDest()
{
    fstream outfile("outputSequence.log", ios::app);
    list<Destination>::iterator currentDest = this->listDestinations.begin();
    outfile << "Initial Size: " <<  this->listN << "\t\tElimination Interval: " << this->listM<< endl;
    int returnPos = 0;
    if(this->isEmpty())
    {
        cout << "Error empty list" << endl;
        currentDest = listDestinations.end();
    }
    else
    {
        while(this->currentSize() > 1)
        {
            returnPos = this->eliminateDestination(currentDest); // eliminates a destination until there is only one left
            outfile << returnPos << " ";
        }
    }
    outfile << endl << "Destination: " << this->listDestinations.begin()->getName() << endl;
    outfile << "Position: " << this->listDestinations.begin()->getPosition() << endl;
    outfile.close();
    return this->listDestinations.begin(); //returns final destination in list
}