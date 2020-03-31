//
// Created by benja on 3/12/2019.
//
#include <iostream>
#include <random>
#include <vector>
#include "CityCreation.hpp"

using namespace std;

typedef std::vector<City*>::iterator Iter;

CityCreation::CityCreation() {
    //random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1000);

    //length of city name
    numberOfCity = 32;


    vector<char> names = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                         'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                          't', 'u', 'v', 'w', 'x', 'y', 'z'};

    char name;
    int index;
    int size = 52;



    City* ptr;

    for(int i = 0; i < numberOfCity; i++) {
        index = rand() % size--;
        name = names.at(index);

        double xCoordinate = dis(gen);
        double yCoordinate = dis(gen);
        ptr = new City(xCoordinate, yCoordinate, name);


        cities.push_back(ptr);

        names.erase(names.begin() + index);
    }

    cout << endl;
}



void CityCreation::print(){
    for(Iter it = cities.begin(); it != cities.end(); it++){
        cout << (*it)->name << " " << (*it)->x << " " << (*it)->y << endl;
    }
}

vector<City*> CityCreation::getCities(){
    return cities;
}

int CityCreation::getNumberOfCity() {
    return numberOfCity;
}