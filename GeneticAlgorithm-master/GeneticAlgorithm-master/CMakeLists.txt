cmake_minimum_required(VERSION 3.13)
project(assignment2)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "$(CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_executable(assignment2 main.cpp CityCreation.hpp CityCreation.cpp Population.hpp Population.cpp GeneticAlgo.hpp GeneticAlgo.cpp City.hpp City.cpp Tour.hpp Tour.cpp)