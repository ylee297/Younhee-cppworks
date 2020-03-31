//
// Created by benja on 3/21/2019.
//

#ifndef ASSIGNMENT2_TOUR_HPP
#define ASSIGNMENT2_TOUR_HPP
#include <iostream>
#include <vector>
#include "City.hpp"

using namespace std;

class Tour{
public:
    vector<City*> cities;
    Tour();
    Tour(vector<City*> cities);
};
#endif //ASSIGNMENT2_TOUR_HPP
