#include "VectorMyJosephus.h"
#include <iostream>
#include <vector>
#include <string>

VectorJosephus::VectorJosephus()
{
    this->vectM = 0;
    this->vectN = 0;
    this->vectDestinations.clear();
}

VectorJosephus::VectorJosephus(int newM, int newN)
{
    this->vectM = newM;
    this->vectN = newN;
    this->vectDestinations.clear();
    cout << "Vector created, M = " << newM << " and N = " << newN << endl;
}

VectorJosephus::~VectorJosephus()
{
    this->vectDestinations.clear();
}

void VectorJosephus::clear()
{
    this->vectDestinations.clear();
}

int VectorJosephus::currentSize()
{
    return this->vectDestinations.size();
}

bool VectorJosephus::isEmpty()
{
    return this->vectDestinations.empty();
}

void VectorJosephus::printAllDestinations()
{
    for(Destination printDest : vectDestinations)
    {
        printDest.printDestinationName();
        cout << endl;
    }
}

vector<Destination> VectorJosephus::getDestinations()
{
    return this->vectDestinations;
}

void VectorJosephus::loadDestinations()
{
    ifstream infile("destinations.csv", ios::in);
    if(infile)
    {
        string destination = "";
        int position =0;
        int destCount =1;
        while(getline(infile,destination,';'))
        {
            Destination *newDest = new Destination(position, destination);
            this->vectDestinations.push_back(*newDest);
            destCount++;
            position++;
            if(destCount > this->vectN)
            {
                break;
            }
        }
        infile.close();
    }
}

int VectorJosephus::eliminateDestination(vector<Destination>::iterator &currentItem)
{
    vector<Destination>::iterator tempItem;
    int i = 0, deletePos =0;
    while(i < this->vectM)
    {
        if(currentItem == --this->vectDestinations.end())
        {
            currentItem = this->vectDestinations.begin();
            i++;
        }
        else{
            ++currentItem;
            i++;
        }   
    }
    tempItem = currentItem;
    deletePos =  tempItem->getPosition();

    currentItem = this->vectDestinations.erase(tempItem);
    if(currentItem == --this->vectDestinations.end() || currentItem == this->vectDestinations.end() )
    {
        currentItem = this->vectDestinations.begin();
    } 
    return deletePos;
}

vector<Destination>::iterator VectorJosephus::pickDest()
{
    fstream outfile("outputSequence.log", ios::app);
    vector<Destination>::iterator currentDest = this->vectDestinations.begin();
    outfile << "Initial Size: " <<  this->vectN << "\t\tElimination Interval: " << this->vectM<< endl;
    int returnPos=0;
    if(this->isEmpty())
    {
        cout << "Error empty list" << endl;
        currentDest = vectDestinations.end();
    }
    else
    {
        while(this->currentSize() > 1)
        {
            returnPos = this->eliminateDestination(currentDest);
            outfile << returnPos << " ";
        }
    }
    outfile << endl << "Destination: " << this->vectDestinations.begin()->getName() << endl;
    outfile << "Position: " << this->vectDestinations.begin()->getPosition() << endl; 
    outfile.close();
    return this->vectDestinations.begin();
}