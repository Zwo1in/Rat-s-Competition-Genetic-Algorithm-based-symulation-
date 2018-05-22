#include "geneticAlgorithm.hpp"

const double maxDistance = sat::distance( 0, 0, 800, 800 );

double GeneticAlgorithm::calculateFitness( std::vector< LabRat >& rats, Floating* target ) {
    double sum = 0;
    double maxFitness = 0;
    for ( auto& rat : rats ) {
        rat.genes() -> fitness = pow( maxDistance - rat.score( target ), 2 );
        sum += rat.genes() -> fitness;
        if ( rat.genes() -> fitness > maxFitness )
            maxFitness = rat.genes() -> fitness;
    }
    for ( auto& rat : rats )
        rat.genes() -> fitness /= maxFitness;
    return sum/maxFitness;
}

double GeneticAlgorithm::calculatePropability( double sum, DNA* dna ) {
    dna -> propability = dna -> fitness / sum;
}

LabRat GeneticAlgorithm::getParent( std::vector< LabRat >& rats ) {
    double diceRoll1 = rand()%rats.size();
    double diceRoll2 = double(rand()%1000) / 1000;
    while ( diceRoll2 > 0 ) {
        diceRoll2 -= rats[diceRoll1].genes() -> propability;
        if ( ++diceRoll1 >= rats.size() )
            diceRoll1 = 0;
    }
    return rats[ diceRoll1 ];
}

void GeneticAlgorithm::evolve( std::vector< LabRat >& rats, Floating* target ) {
    std::vector< LabRat > pool( rats );
    // Calculate fitness and propability
    double sum = calculateFitness( pool, target );
    for ( auto& rat : pool )
        calculatePropability( sum, rat.genes() );
    // Kill worst 10% of population
    QuickSort::sort( pool, 0, pool.size()-1 );
    pool.erase( pool.begin(), pool.begin()+int(pool.size()/10));
    // Evolve
    for ( auto& rat : rats )
        rat.genes() -> cross( getParent(pool).genes() );
}