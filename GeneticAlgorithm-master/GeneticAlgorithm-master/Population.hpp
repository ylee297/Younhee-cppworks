//
// Created by benja on 3/14/2019.
//

#ifndef ASSIGNMENT2_POPULATION_HPP
#define ASSIGNMENT2_POPULATION_HPP
#include <map>
#include <vector>
#include "City.hpp"
#include "Tour.hpp"


using namespace std;

class Population{
protected:
    vector<City*> cities;
    vector<Tour*> tours;
    int numberOfCity;
    int numberOfTour;
public:
    Population();
    Population(vector<City*> cities, int numberOfCity);
    void printTours();
    void printATour(Tour* a);
    double distance(Tour *tour);
    void createTours();

    vector<Tour*> getTours();
};


#endif //ASSIGNMENT2_POPULATION_HPP
