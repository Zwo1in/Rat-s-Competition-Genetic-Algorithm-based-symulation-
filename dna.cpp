#include "dna.hpp"

DNA::DNA() {}

DNA::DNA( int lifeTime_, double offset, double rate, double probability ) {
    mutationRate = rate;
    mutationProbability = probability;
    lifeTime = lifeTime_;
    // randomAngle from -180 to 180 degrees
    double randomAngle = double(rand()%1000) / 1000 * 2 * M_PI;
    double random;
    genes.push_back( randomAngle );
    for ( int i = 1; i < lifeTime; i++ ) {
        // random angle from -offset to offset
        random = double(rand()%100) / 100;
        randomAngle = random * 2 * offset - offset;
        genes.push_back( randomAngle );
    }
}

void DNA::cross( DNA* other ) {
    for ( int i = 0; i < lifeTime; i++ ) {
        genes[i] = (*other)(i);
    }
}

int DNA::getLifeTime() {
    return lifeTime;
}

double DNA::operator() ( unsigned int n ) {
    //rare big mutation
    if ( double(rand()%10000) / 10000 <= 0.002 )
        return genes[n] + double(rand()%1000) / 1000  - 0.5;
    
    //normal mutation
    if ( double(rand()%1000) / 1000 <= mutationProbability )
        return genes[n] + double(rand()%1000) / 1000 * 2*mutationRate - mutationRate;

    //no mutation
    return genes[n];
}

double DNA::operator[] ( unsigned int n ) {
    return genes[n];
}