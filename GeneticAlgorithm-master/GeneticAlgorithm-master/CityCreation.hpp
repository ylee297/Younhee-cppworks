//
// Created by benja on 3/12/2019.
//
#ifndef ASSIGNMENT2_CITYCREATION_HPP
#define ASSIGNMENT2_CITYCREATION_HPP
#include <map>
#include "City.hpp"


using namespace std;


class CityCreation {
private:
    vector<City*> cities;
    int numberOfCity;
public:
    CityCreation();
    string randomName(int length);
    void print();
    vector<City*> getCities();
    int getNumberOfCity();
};

#endif //ASSIGNMENT2_CITYCREATION_HPP