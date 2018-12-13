#ifndef Core_HPP_
#define Core_HPP_

// Maciej Zwoliński
// 22 / 05 / 2018

// The heart of a simulation
// It holds all populations
// Has main game loop and event handling in it
// Also contains the config variables

#include <geneticAlgorithm.hpp>
// game loop handling clock repo
#include <fpsClock.hpp>
#include "population.hpp"
#include <sstream>

// functions helping in statistics showing
std::string toString( double );
std::string toString( int );

class Core {
    // it contains a few population which sompete in each other
    std::vector< Population > teams;
    // also the obstacles
    std::vector< Floating* > objects;
    int lifeTime;
    unsigned int generation;
    bool pause;
    // stats displaying
    sf::Font font;
    sf::Text texts[7];
    std::string s[21];

    public:
    Core();
    ~Core();
    // game loop
    void play( sf::RenderWindow& win, fpsClock& clock );
    bool handleEvents( sf::RenderWindow& win );
    // Those are basicaly a methods that invokes same population's methods for each team
    void update( int counter );
    void judge( Floating* target );
    void stats( sf::RenderWindow& win );
    void display( sf::RenderWindow& win );
    void reset();
};

#endif