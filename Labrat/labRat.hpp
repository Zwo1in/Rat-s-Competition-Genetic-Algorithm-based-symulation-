#ifndef LABRAT_HPP_
#define LABRAT_HPP_

// Maciej Zwoliński
// 25 / 05/ 2018

// Class for the learning triangles

#include "drawable.hpp"
#include "dna.hpp"

class LabRat :public Triangle {
    // Determines if the rat is still in action
    bool crashed;
    // The dna of an object
    DNA dna;
    public:

    LabRat( double x, double y, double width, double height, double rotation_, int lifeTime, double offset = 0.15, double rate = 0.05, 
            double probability = 0.01, double velocity = 6, sf::Color color = sf::Color( rand()%255, rand()%255, rand()%255 ) );
    // returns dna's pointer
    DNA* genes();
    // I need to cover this to not be an abstract class
    bool colCheck( sat::Triangle* body );
    // Collision check with polymorphic pointer
    void colCheck( Floating* object );
    // calculate score based on distance to given target
    double score( Floating* target );
    // updates rat's position based on given time point
    void update( int timePoint );
    // resets rat to the starting position
    void reset();
};

#endif

