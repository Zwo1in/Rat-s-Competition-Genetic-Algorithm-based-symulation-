#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP

// Maciej Zwoliński
// 22 / 05 / 2018

// This class is the static Genetic Algorithm system
// It calculates how well does unit does in the given environment
// Calculates unit's propability of being chosen for a dna's giver for next evolution
// Has implemented algorithm of choosing a random parent
// evolves whole population, basicaly the main function which gets everything done 

#include "dna.hpp"
#include "labRat.hpp"
#include "quicksort.hpp"

class GeneticAlgorithm {
    GeneticAlgorithm(){}
    public:
    // calculate fitness based on a square function to enlarge differences
    static double calculateFitness( std::vector< LabRat >& rats, Floating* target );
    // gets the sum of all fitnesses of the population and calculates propabilities in a way that the sum of them equals 1
    static double calculatePropability( double sum, DNA* dna );
    // gambles a random double from 0 to 1, then a random unit in population, and iterates through vector substracting unit's propabilities from given float
    // it returns unit at which that double stops being a positive number
    static LabRat getParent( std::vector< LabRat >& rats );
    // applies all those functions to the population and cross the dnas
    // it also kills the worst x% of population for better results as the rat controls aren't optimal
    static void evolve( std::vector< LabRat >& rats, Floating* target );
};
#endif