#include "labRat.hpp"

LabRat::LabRat( double x, double y, double width, double height, double rotation_, int lifeTime, double offset, double rate, double probability, double velocity, sf::Color color ) :
    Triangle( x, y, width, height, rotation_, velocity, color ) {
    dna = DNA( lifeTime, offset, rate, probability );
    crashed = false;
}

DNA* LabRat::genes() {
    return &dna;
}

bool LabRat::colCheck( sat::Triangle* body ) {
    return 0;
}

void LabRat::colCheck( Floating* object ) {
    if ( pos.x < 0 || pos.x > 800 || pos.y < 0 || pos.y > 800 || object -> colCheck( &body ) )
        crashed = true;
}

double LabRat::score( Floating* target ) {
    if ( target -> colCheck( &body ) )
        return 0;
    return sat::distance( pos, target -> getPos() );
}

void LabRat::update( int timePoint ) {
    if ( timePoint < dna.getLifeTime() && !crashed ) {
        // rotates of the given angle
        rotation += dna[ timePoint ];
        // move forward depending on rotation
        pos.x += velocity * sin( rotation );
        pos.y -= velocity * cos( rotation );
        body.setRotation( rotation );
        body.setPosition( pos.x, pos.y );
        drawing.setRotation( rotation * 180 / M_PI );
        drawing.setPosition( pos.x, pos.y );
    }
}

void LabRat::reset() {
    pos = startPos;
    rotation = startRot;
    drawing.setPosition( pos );
    drawing.setRotation( rotation );
    body.setPosition( pos.x, pos.y );
    body.setRotation( rotation );

    crashed = false;
}

