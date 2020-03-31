//
// Created by benja on 3/18/2019.
//
#include "Population.hpp"

#ifndef ASSIGNMENT2_GENETICALGO_HPP
#define ASSIGNMENT2_GENETICALGO_HPP

typedef pair<char, pair<double,double>> oneCity;
class GeneticAlgo : public Population{
private:
    double start;
    double current;

public:
    GeneticAlgo(vector<City*> cities, int numberOfCity);
    void selection();
    void mutation(vector<City*> &tour);
    void crossOver();
    void printProgress();
    double getStart();
    double getCurrent();
};

#endif //ASSIGNMENT2_GENETICALGO_HPP
