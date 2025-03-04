#include "header.h"
#include <random>

int loadCities(AVLMap<int, USCity>* testAVLMap, map<int, USCity>* testMap, list<int>* zipList)
{
    fstream infile("uszips.csv", ios::in);
    string newLine = "";
    int items =0;
    int newZip;
    double newLat;
    double newLng;
    string newCityName;
    string newStateID;
    string newStateName;
    bool newZcta;
    int newParentZcta;
    int newPop;
    double newDensity;
    int newCountyFips;
    string newCountyName;
    vector<pair<int, double>> newCountyWeights;
    vector<string> newCountyNamesAll;
    vector<int> newCountyFipsAll;
    bool newImprecise;
    bool newMilitary;
    string newTimezone;
    getline(infile, newLine, '\n');
    while(getline(infile, newLine, ',')) //read zipcode
    {
        if(removeQuotes(newLine).length() != 0)
        {newZip = stoi(removeQuotes(newLine));} //add zipcode
        if(!getline(infile,newLine,',')) break; //read latitude
        if(removeQuotes(newLine).length() != 0){newLat = stod(removeQuotes(newLine));} //add latitude
        if(!getline(infile,newLine,',')) break; //read longitude
        if(removeQuotes(newLine).length() != 0){newLng = stod(removeQuotes(newLine));} //add longitude
        if(!getline(infile,newLine,',')) break; //read City
        if(removeQuotes(newLine).length() != 0){newCityName = removeQuotes(newLine);} //add city
        if(!getline(infile,newLine,',')) break; //read state abbreviation
        if(removeQuotes(newLine).length() != 0){newStateID = removeQuotes(newLine);} //add state abbreviation
        if(!getline(infile,newLine,',')) break; //read state name
        if(removeQuotes(newLine).length() != 0){newStateName = removeQuotes(newLine);} //add state name
        if(!getline(infile,newLine,',')) break; //read zcta status
        if(removeQuotes(newLine) == "TRUE")
            {newZcta = true;}//add zcta status
        else 
            {newZcta = false;}
        if(!getline(infile,newLine,',')) break; //read parent_zcta
        if(newZcta == false) // add if zcta false
        {
            newParentZcta = stoi(removeQuotes(newLine));
        }
        else //else set to 0
        {
            newParentZcta = 0;
        }
        if(!getline(infile,newLine,',')) break; //read population
        if(removeQuotes(newLine).length() != 0){newPop = stoi(removeQuotes(newLine));} //add population
        if(!getline(infile,newLine,',')) break; //read density
        if(removeQuotes(newLine).length() != 0){newDensity = stod(removeQuotes(newLine));} //add density
        if(!getline(infile,newLine,',')) break; //read county fips
        if(removeQuotes(newLine).length() != 0){newCountyFips = stoi(removeQuotes(newLine));} //add county fips
        if(!getline(infile,newLine,',')) break; //read county name
        if(removeQuotes(newLine).length() != 0){newCountyName = removeQuotes(newLine);} //add county name
        if(!getline(infile,newLine,'}')) break; //read county weights
        if(removeQuotes(newLine).length() != 0){newCountyWeights = translateCountyWeights(newLine);} //add county weights
        if(!getline(infile,newLine,','));//bypass ", after closing bracket;
        if(!getline(infile,newLine,',')) break; //read all county names
        if(removeQuotes(newLine).length() != 0){newCountyNamesAll = translateCountyNames(newLine);} //add all county names
        if(!getline(infile,newLine,',')) break; //read all county fips
        if(removeQuotes(newLine).length() != 0){newCountyFipsAll = translateCountyFips(newLine);} //add all county fips
        if(!getline(infile,newLine,',')) break; //read imprecise
        if(removeQuotes(newLine) == "TRUE"){newImprecise = true;} //set imprecise
        else{newImprecise = false;}
        if(!getline(infile,newLine,',')) break; //read military
        if(removeQuotes(newLine) == "TRUE"){newMilitary = true;} //add military
        else{newMilitary = false;}
        if(!getline(infile,newLine,'\n')) break; //read timezone
        if(removeQuotes(newLine).length() != 0){
            newLine.pop_back();
            newTimezone = removeQuotes(newLine);} //add timezone
        USCity newCity(newLat, newLng, newCityName, newStateID, newStateName, newZcta, newParentZcta, newPop, newDensity, newCountyFips, newCountyName, newCountyWeights, newCountyNamesAll, newCountyFipsAll, newImprecise, newMilitary, newTimezone);
        testAVLMap->insert(newZip, newCity);
        testMap->insert({newZip, newCity});
        zipList->push_back(newZip);
        items++;
        cout << items << " of 33783" << endl;
    }
    system("clear");
    cout << items << "Cities loaded" << endl;
    return items;
}

vector<int> loadRandInts(int numItems)
{
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<> dstr(1, numItems);
    vector<int> randInts;
    srand((unsigned)time(0));
    for(int i = 0; i < 1000; i++)
    {
        randInts.push_back(dstr(eng));
    }
    return randInts;
}

string removeQuotes(string line)
{
    if(!line.empty() && line.front() == '"')
    {
        line.erase(0, 1);
    }
    if(!line.empty() && line.back() == '"')
    {
        line.pop_back();
    }  
    return line;
}

vector<pair<int, double>> translateCountyWeights(string &line)
{
    int newZip;
    double newWeight;
    string tempString;
    vector<pair<int, double>> weightList;
    line.push_back(',');
    if(!line.empty() && line.front() == '\"')
    {
        line.erase(0,1);
    }
    while(!line.empty())
    {
        //Case 1: First term
        if(!line.empty() && line.front() == '{')
        {
            line.erase(0,1);
        }
        if(!line.empty() && line.front() == ' ')
        {
            line.erase(0,1);
        }
        tempString = line.substr(0, line.find(','));
        line.erase(0, line.find(',')+1);
        newZip = stoi(removeQuotes(removeQuotes(tempString.substr(0, tempString.find(':')))));
        newWeight = stod(tempString.substr(tempString.find(":")+1, tempString.find(',')));
        weightList.push_back({newZip, newWeight});
    }
    return weightList;
}

vector<string> translateCountyNames(string &line)
{
    vector<string> countyNames;
    line = removeQuotes(line);
    line.push_back('|');
    while(!line.empty())
    {
        countyNames.push_back(line.substr(0, line.find('|')));
        line.erase(0, line.find('|')+1);
    }
    return countyNames;
}

vector<int> translateCountyFips(string &line)
{
    vector<int> countyNames;
    line = removeQuotes(line);
    line.push_back('|');
    while(!line.empty())
    {
        countyNames.push_back(stoi(line.substr(0, line.find('|'))));
        line.erase(0, line.find('|')+1);
    }
    return countyNames;
}

