#include <iostream>
#include <algorithm>
#include <math.h>
#include "Tour.hpp"
#include "City.hpp"
#include "Population.hpp"

using namespace std;
typedef pair<char, pair<double,double>> oneCity;

Population::Population() {}

Population::Population(vector<City*> cities, int numberOfCity)
    : cities(cities), numberOfCity(numberOfCity)
{
    createTours();
}


void Population::printTours(){
    for(Tour* a : tours){
        for(City* b : a->cities){
            cout << b->name << " ";
        }
        cout << distance(a);
        cout << endl;
    }
}
void Population::printATour(Tour* a){
    for(City* b : a->cities){
        cout << b->name << " ";
    }
}

double Population::distance(Tour* tour){
    double totalDistance = 0;
    for(unsigned i = 0; i < numberOfCity - 1; i++){
        double height = abs(tour->cities.at(i)->x - tour->cities.at(i + 1)->x);
        double width = abs(tour->cities.at(i)->y - tour->cities.at(i + 1)->y);
        totalDistance += sqrt(pow(height, 2.0) + pow(width, 2.0));
    }

    return totalDistance;
}

void Population::createTours(){
    numberOfTour = 32;
    Tour* tour;
    for(int i = 0; i < numberOfTour; i++) {
        std::random_shuffle(cities.begin(), cities.end());
        tour = new Tour(cities);
        tours.push_back(tour);
    }
}

vector<Tour*> Population::getTours(){
    return tours;
}