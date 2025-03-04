#include "header.h"
#include <fstream>
#include <thread>
#include <ctime>
int main(void)
{


fstream outfile("results.log", ios::out);
AVLMap<int, USCity> testAVLMap;
map<int, USCity> testMap;
vector<int> randList;
list<int> zipList;
int numCities = 0;
clock_t start, end, k;
double AVLTime = 0.0;
double AVLTimeSum = 0.0;
double AVLTimeAvg = 0.0;
double mapTime = 0.0;
double mapTimeSum = 0.0;
double mapTimeAvg = 0.0;

numCities = loadCities(&testAVLMap, &testMap, &zipList);
randList = loadRandInts(numCities);
for(int i =0; i < randList.size(); i++)
{
    auto it = zipList.begin();
    for(int j = 0; j < randList[i]; j++)
    {
        ++it;
    }
        //start time
        k = clock();
        do start = clock();
        while(start == k);
        testAVLMap.find(*it);
        //end time
        end = clock();
        AVLTime =  static_cast<double>(end - start) / CLOCKS_PER_SEC;
       
        //start time
        k = clock();
        do start = clock();
        while(start == k);
        testMap.find(*it);
        //end time
        end = clock();
        mapTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        outfile << "Finding " << randList[i] << endl << "AVL Time: "<< AVLTime << endl << "Map Time: " << mapTime << endl << endl;
        
        AVLTimeSum += AVLTime;
        mapTimeSum += mapTime;
}
AVLTimeAvg = AVLTimeSum/randList.size();
mapTimeAvg = mapTimeSum/randList.size();

outfile << "AVL Average Time: " << AVLTimeAvg << endl << "Map Average Time: " << mapTimeAvg;
outfile.close();
cout << "Results printed to results.log";
return 0;
}