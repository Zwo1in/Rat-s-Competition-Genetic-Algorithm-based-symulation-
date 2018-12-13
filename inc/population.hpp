#ifndef POPULATION_HPP_
#define POPULATION_HPP_

// Maciej Zwoliński
// 22 / 05 / 2018

// This class groups rats into a populations, which evolve in their own society
// Each population is judged and gets score base of % of succesful rat's runs
// While creating new population you choose a goal amount, which after reached, stops later evolution as population is now treated as trained

#include "geneticAlgorithm.hpp"
#include "separatedAxisTheorem.hpp"

class Population {
    std::vector< LabRat > rats;
    double goal;
    bool evolved;
    bool active;
    public:
    Population(){};
    Population( int amount, double goal_, int lifeTime, double x, double y, double offset, double mutRate, double mutProb, sf::Color color );
    void update( int timePoint );
    void colCheck( std::vector< Floating* > objects );
    double judge( Floating* target );
    void evolve( Floating* target );
    void reset();
    void display( sf::RenderWindow& win );
    // toggle population displaying
    void toggle();
};

#endif