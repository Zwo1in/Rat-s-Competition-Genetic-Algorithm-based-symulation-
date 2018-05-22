#include "core.hpp"

// Maciej Zwoliński
// 22 / 05 / 2018

// Graphical library used: SFML 2.4.2
// Not much else to say, if you've read other header files.
// It's simple simulaiton of 5 teams of triangles ( called "rats" ) competing in finding way to the target
// The goal is to make 60% of rats in team make it to the target
// Teams evolves separately
// The weakness is a control system which lacks a ANN
// It uses some of my other repos: Game loop handler, SAT colsiion detection and sorts
// Enjoy watching!


int main() {
    srand( time( NULL ) );
    sf::RenderWindow win( sf::VideoMode( 800, 800 ), "Genetic Algorithm");
    auto clock = fpsClock( 60 );
    Core core;
    core.play( win, clock );
    return 0;
}