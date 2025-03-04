#ifndef USCITY_H
#define USCITY_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class USCity
{
    public:
        USCity();
        USCity(double newLat, double newLng, string newCity, string newStateID, string newStateName,
            bool newZcta, int newParentZcta, int newPop, double newDensity, int newCountyFips,
            string newCountyName, vector<pair<int, double>> newCountyWeights, vector<string> newCountyNamesAll, vector<int> newCountyFipsAll, bool newImprecise,
            bool newMilitary, string newTimezone);
        ~USCity();

    private:
        double lat;
        double lng;
        string city;
        string state_id;
        string state_name;
        bool zcta;
        int parent_zcta;
        int population;
        double density;
        int county_fips;
        string county_name;
        vector<pair<int, double>> county_weights;
        vector<string> county_names_all;
        vector<int> county_fips_all;
        bool imprecise;
        bool military;
        string timezone;

};


#endif