#ifndef VECTORMYJOSEPHUS_H
#define VECTORMYJOSEPHUS_H

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

#include "Destination.h"

class VectorJosephus
{
    public:
        VectorJosephus();
        VectorJosephus(int newM, int newN);
        ~VectorJosephus();

        void clear();
        int currentSize();
        bool isEmpty();
        void printAllDestinations();
        void loadDestinations();
        vector<Destination> getDestinations();
        int eliminateDestination(vector<Destination>::iterator &currentItem);
        vector<Destination>::iterator pickDest();

    private:
        int vectM; //Elimination Interval
        int vectN; //Total initial destinations
        vector<Destination> vectDestinations;


};

#endif