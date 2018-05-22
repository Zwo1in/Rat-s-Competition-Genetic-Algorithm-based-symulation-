#ifndef DNA_HPP_
#define DNA_HPP_

// Maciej Zwoliński
// 22 / 05 / 2018

// The DNA's class
// That's the greatest weakness of whole simulation, as it just begs for the neural network
// Haven't made any yet, so I implemented it similiar to "The Coding Train" channel on youtube ( the smart rockets video )
// https://www.youtube.com/user/shiffman

// There is a vector given, with te length of the live time of the rats
// each cell has a certain rotation that rat uses at each time point
// to make this work I had to give up on crossing DNA's and I'm just replacing the dnas with the other one after mutations



#include <vector>
#include <ctime>
#include <cmath>

class DNA {
    std::vector< double > genes;
    int lifeTime;
    // determines how much does mutation affects angles 
    double mutationRate;
    // determines the chance of mutation
    double mutationProbability;

    public:
    // determines rat's fitness to the target purposes
    double fitness;
    // determines propability of being choosen from entire population
    double propability;

    DNA();
    DNA( int lifeTime_, double offset = 0.15, double rate = 0.05, double probability = 0.01 );
    // crosses genes with other DNA
    void cross( DNA* other );
    int getLifeTime();
    // return certain gene with mutation included
    double operator() ( unsigned int n );
    // return the exact gene from given position
    double operator[] ( unsigned int n );
};
#endif