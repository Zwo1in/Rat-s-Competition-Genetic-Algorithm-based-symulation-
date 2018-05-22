#include "population.hpp"

Population::Population( int amount, double goal_, int lifeTime, double x, double y, double offset, double mutRate, double mutProb, sf::Color color ){
    goal = goal_;
    evolved = false;
    active = true;
    for ( int i = 0; i < amount; i++ ) {
        rats.emplace_back( LabRat( x, y, 10, 15, 0, lifeTime, offset, mutRate, mutProb, 6, color ) );
    }
}
void Population::update( int timePoint ) {
    for ( auto& rat : rats )
        rat.update( timePoint );
}
void Population::colCheck( std::vector< Floating* > objects ) {
    for ( auto& rat : rats )
        for ( auto* obj : objects )
            rat.colCheck( obj );
}
double Population::judge( Floating* target ) {
    int counter = 0;
    // calculates how many rats've reached the target
    for ( auto& rat : rats )
        if ( !rat.score( target ) )
            counter ++;    
    // normalize value and checks for goal
    double score = double(counter)/rats.size();
    if ( score >= goal )
        evolved = true;
    else
        evolve( target );
    return score;
}
void Population::evolve( Floating* target ) {
    if ( !evolved )
        GeneticAlgorithm::evolve( rats, target );
}
void Population::reset() {
    for ( auto& rat : rats )
        rat.reset();
}
void Population::display( sf::RenderWindow& win ) {
    if ( active )
        for ( auto& rat : rats )
            rat.draw( win );
}
void Population::toggle() {
    active = !active;
}