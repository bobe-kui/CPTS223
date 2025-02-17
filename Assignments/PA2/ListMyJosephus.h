#ifndef LISTMYJOSEPHUS_H
#define LISTMYJOSEPHUS_H

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

#include "Destination.h"


class ListJosephus
{
    public:
        ListJosephus();
        ListJosephus(int newM, int newN);
        ~ListJosephus();

        list<Destination> getDestinations() const;
        

        void clear();
        int currentSize();
        bool isEmpty();
        int eliminateDestination(list<Destination>::iterator &currentItem);
        void printAllDestinations();

        void loadDestinations();
        list<Destination>::iterator pickDest();

    private:
        int listM; //Elimination interval
        int listN; //Total initial destinations
        list<Destination> listDestinations;
};



#endif