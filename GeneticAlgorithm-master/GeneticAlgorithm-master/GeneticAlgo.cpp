//
// Created by benja on 3/18/2019.
//
#include <iostream>
#include <random>
#include "GeneticAlgo.hpp"
#include "Population.hpp"
using namespace std;

//constructor
GeneticAlgo::GeneticAlgo(vector<City*> cities, int numberOfCity)
: Population(cities, numberOfCity)
{
    selection();
    start = distance(tours.at(0));
    current = distance(tours.at(0));
}


void GeneticAlgo::selection(){


    for(int i = 0; i < tours.size(); i++){
        if(distance(tours.at(i)) < distance(tours.at(0))){
            swap(tours.at(i), tours.at(0));
        }

    }
}

void GeneticAlgo::mutation(vector<City*> &Atour){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(1, 20);

    // 15% mutating until the element before last one
    for(unsigned i = 0; i < numberOfCity - 1; i++){
        if(dis(gen) <= 3){
            swap(Atour.at(i), Atour.at(i + 1));
        }
    }

    // 15% mutating for last one
    if(dis(gen) <= 3){
        swap(Atour.at(numberOfCity - 1), Atour.at(0));
    }
}




void GeneticAlgo::crossOver() {
//    cout << "start point : " << distance(tours.at(0)) << "    ";
    vector<Tour*> tempTours;


    // save an elite

    tempTours.push_back(tours.at(0));



    vector<City*> candidate1;
    vector<City*> candidate2;


    random_device rd;
    mt19937 gen(rd());
    int lastIndex = numberOfTour - 1;
    uniform_real_distribution<> dis(1, lastIndex);


    Tour* tempTour;

    for(unsigned addIndex = 1; addIndex < numberOfCity; addIndex++)
    {
//        cout << distance(tempTours.at(0)) << "   ";
        candidate1 = tours.at(dis(gen))->cities;
        for (int i = 1; i < 5; i++) {
            vector<City*> temp = tours.at(dis(gen))->cities;
            double tempDistance = distance(new Tour(temp));
            if ( tempDistance < distance(new Tour(candidate1))) {
                candidate1 = temp;
            }
        }

        candidate2 = tours.at(dis(gen))->cities;
        for (int i = 1; i < 5; i++) {
            vector<City*> temp = tours.at(dis(gen))->cities;
            double tempDistance = distance(new Tour(temp));
            if ( tempDistance < distance(new Tour(candidate2))) {
                candidate2 = temp;
            }
        }


        random_device rd2;
        mt19937 gen2(rd2());
        uniform_real_distribution<> dis2(1, numberOfCity - 1);
        int middle = (int) dis2(gen2);

        vector<City*> crossedTour;

        for (int i = 0; i < middle; i++) {
            crossedTour.push_back(candidate1.at(i));
        }

        bool isAcceptable;



        for (int i = 0; i < numberOfCity; i++) {
            isAcceptable = true;
            for (int j = 0; j < middle; j++) {
                if (candidate2.at(i) == crossedTour.at(j)) {
                    isAcceptable = false;
                }
            }
            if (isAcceptable) {
                crossedTour.push_back(candidate2.at(i));
            }
        }

        // mutation
        mutation(crossedTour);
//        cout << distance(tempTours.at(0)) << endl;




        //vector to pointer
        tempTour = new Tour(crossedTour);

        tempTours.push_back(tempTour);


    }

    tours = tempTours;

    selection();
    current = distance(tours.at(0));

}

void GeneticAlgo::printProgress() {
    cout << "Base Distance : " << start << endl;
    cout << "Best Distance : " << current << endl;
    cout << "Progression : " << (start / current) * 100 << "%" << endl;
    cout << endl;
}

double GeneticAlgo::getStart(){return start;}
double GeneticAlgo::getCurrent(){return current;}

