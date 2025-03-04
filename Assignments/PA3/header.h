#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <list>
#include <map>
#include  "USCity.h"
#include "avl_map.h"
using namespace std;

int loadCities(AVLMap<int, USCity>* testAVLMap, map<int, USCity>* testMap, list<int>* zipList);
vector<int> loadRandInts(int numItems);
string removeQuotes(string line);
vector<pair<int, double>> translateCountyWeights(string &line);
vector<string> translateCountyNames(string &line);
vector<int> translateCountyFips(string &line);
#endif