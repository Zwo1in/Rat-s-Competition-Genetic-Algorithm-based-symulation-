#include "drawable.hpp"

Floating::Floating( sf::Vector2f pos_, double rotation_, double velocity_ ) {
    pos = pos_;
    startPos = pos_;
    velocity = velocity_;
    startVel = velocity;
    rotation = M_PI * rotation_ / 180;
    startRot = rotation;
    gravity = 0;
    startGrav = gravity;
}
sf::Vector2f Floating::getPos() {
    return pos;
}

Rectangle::Rectangle( double x, double y, double width_, double height_, double rotation_, double velocity, sf::Color color ) :
  Floating( sf::Vector2f( x, y ), rotation_, velocity ) {
    width = width_;
    height = height_;
    velocity = -10;
    gravity = 5;
    startGrav = gravity;
    startVel = velocity;
    // graphical representation setting
    drawing.setSize( sf::Vector2f( width, height ) );
    drawing.setOrigin( width/2, height/2 );
    drawing.setRotation( rotation_ );
    drawing.setPosition( pos );
    drawing.setFillColor( color );
    // virtual body setting
    body = sat::Rect( pos.x, pos.y, width, height, rotation );
}
bool Rectangle::colCheck( sat::Triangle* tri ) {
    return sat::Colision::check( *tri, body );
}
void Rectangle::draw( sf::RenderWindow& win ) {
    win.draw( drawing );
}
void Rectangle::update( int timePoint ) {
}
void Rectangle::reset() {
    pos = startPos;
    rotation = startRot;
    gravity = startGrav;
    velocity = startVel;
    drawing.setPosition( pos );
    drawing.setRotation( rotation * 180 / M_PI );
    body.setPosition( pos.x, pos.y );
    body.setRotation( rotation );
}

Triangle::Triangle( double x, double y, double width, double height, double rotation_, double velocity, sf::Color color ) :
  Floating( sf::Vector2f( x, y ), rotation_, velocity ) {
    // graphical representation and virtual body setting
    drawing.setPointCount( 3 );
    // setting points local positions
    drawing.setPoint(0, sf::Vector2f( x, y ));
    drawing.setPoint(1, sf::Vector2f( x + width/2, y + height ));
    drawing.setPoint(2, sf::Vector2f( x - width/2, y + height ));
    body = sat::Triangle( drawing.getPoint(0), drawing.getPoint(1), drawing.getPoint(2), 0 );
    // setting positions
    drawing.setOrigin( body.center );
    drawing.setPosition( x, y );
    drawing.setRotation( rotation_ );
    body.setPosition( x, y );
    body.setRotation( rotation );
    drawing.setFillColor( color );
}
bool Triangle::colCheck( sat::Triangle* tri ) {
    return sat::Colision::check( *tri, body );
}
void Triangle::draw( sf::RenderWindow& win ) {
    win.draw( drawing );
}
void Triangle::update( int timePoint ) {

}
void Triangle::reset() {
    pos = startPos;
    rotation = startRot;
    drawing.setPosition( pos );
    drawing.setRotation( rotation * 180 / M_PI );
    body.setPosition( pos.x, pos.y );
    body.setRotation( rotation );
}


Circle::Circle( double x, double y, double radius_, double velocity, sf::Color color ) :
  Floating( sf::Vector2f( x, y ), 0, velocity ) {
    radius = radius_;
    // graphical representation setting
    drawing.setRadius( radius_ );
    drawing.setOrigin( radius, radius );
    drawing.setPosition( pos );
    drawing.setFillColor( color );
    // virtual body setting
    body = sat::Circle( pos.x, pos.y, radius );
}
bool Circle::colCheck( sat::Triangle* tri ) {
    return sat::Colision::check( *tri, body );
}
void Circle::draw( sf::RenderWindow& win ) {
    win.draw( drawing );
}
void Circle::update( int timePoint ) {}
void Circle::reset() {
    pos = startPos;
    drawing.setPosition( pos );
    body.setPosition( pos.x, pos.y );
}