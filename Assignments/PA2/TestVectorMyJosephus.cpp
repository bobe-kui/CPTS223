#include "header.h"
#include <random>
#include <ctime>

double testVectorMain()
{
    ofstream outfile("results.log", ios::app);
    fstream sequenceOut("outputSequence.log", ios::app);
    vector<Destination>::iterator printDest;
    int size = 1;
    int step = 0;
    clock_t start, end, k;
    double times[1000] = {0.0};
    double sum = 0;
    double average = 0;
    sequenceOut << "~~~~~~~~Vector output sequences~~~~~~~~" << endl;
    for(size = 1; size < 1001; size++)
    {
        cout << "~~~~~Case N = " << size << "~~~~~"<<endl;
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> dstr(1, size);
        step = dstr(eng);

        VectorJosephus *testVect = new VectorJosephus(step, size);
        testVect->loadDestinations();
        k = clock();
        do start = clock();
        while(start == k);
        printDest = testVect->pickDest();
        end = clock();
        sequenceOut << endl;
        cout << "Destination: ";
        printDest->printDestinationName();
        cout << endl << "Position: ";
        printDest->printPosition();
        cout << endl;
        times[size] = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        sum+= times[size];
        cout << "Time Elapsed: " << times[size] << endl << endl;
        outfile << "Vector," << size << "," << times[size] << endl;
        delete testVect;
    }
    average = sum / (size-1);
    outfile.close();
    sequenceOut.close();
    return average;
}
