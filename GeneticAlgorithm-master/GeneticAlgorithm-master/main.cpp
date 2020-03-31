#include <iostream>
#include <vector>
#include <random>
#include "City.hpp"
#include "Tour.hpp"
#include "CityCreation.hpp"
#include "Population.hpp"
#include "GeneticAlgo.hpp"

typedef pair<char, pair<double,double>> oneCity;
using namespace std;
int main() {
    // number of how many to loop
    int numberOfLoop = 1000;
    //goal of progression percentage
    double goal = 200;
    CityCreation cityInit;
    GeneticAlgo tourInit(cityInit.getCities(), cityInit.getNumberOfCity());


    Tour* firstTour = tourInit.getTours().at(0);

    for(int i = 0; i < numberOfLoop; i++){
        if(((tourInit.getStart()/tourInit.getCurrent()) * 100) < goal) {
            cout << "Iteration number : " << i + 1 << endl;
            tourInit.crossOver();
            tourInit.printProgress();
        } else {
            break;
        }
    }

    if(tourInit.getCurrent() >= goal){
        cout << "------Improvement achieved-------" << endl;
    }
    cout << "Base Tour : ";
    tourInit.printATour(firstTour);
    cout << "distance : " << tourInit.distance(firstTour);
    cout << endl;
    cout << "Improved Tour : ";
    tourInit.printATour(tourInit.getTours().at(0));
    cout << "distance : " << tourInit.distance(tourInit.getTours().at(0));




    return 0;
}