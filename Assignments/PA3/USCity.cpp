#include "USCity.h"

USCity::USCity()
{
    this->lat=0.0;
    this->lng=0.0;
    this->city="";
    this->state_id="";
    this->state_name="";
    this->zcta=false;
    this->parent_zcta=0;
    this->population=0;
    this->density=0.00;
    this->county_fips=0;
    this->county_name="";
    this->county_weights={{0, 0.0}};
    this->county_names_all={""};
    this->county_fips_all={0};
    this->imprecise=false;
    this->military=false;
    this->timezone="";
}

USCity::USCity(double newLat, double newLng, string newCity, string newStateID, string newStateName,
    bool newZcta, int newParentZcta, int newPop, double newDensity, int newCountyFips,
    string newCountyName, vector<pair<int, double>> newCountyWeights, vector<string> newCountyNamesAll, vector<int> newCountyFipsAll, bool newImprecise,
    bool newMilitary, string newTimezone)
{
    this->lat=newLat;
    this->lng=newLng;
    this->city=newCity;
    this->state_id=newStateID;
    this->state_name=newStateName;
    this->zcta=newZcta;
    this->parent_zcta=newParentZcta;
    this->population=newPop;
    this->density=newDensity;
    this->county_fips=newCountyFips;
    this->county_name=newCountyName;
    this->county_weights=newCountyWeights;
    this->county_names_all=newCountyNamesAll;
    this->county_fips_all=newCountyFipsAll;
    this->imprecise=newImprecise;
    this->military=newMilitary;
    this->timezone=newTimezone;
}

USCity::~USCity()
{
}