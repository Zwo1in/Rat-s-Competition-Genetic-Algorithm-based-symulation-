#ifndef DRAWABLE_HPP_
#define DRAWABLE_HPP_

// Maciej Zwoliński
// 22 / 05 / 2018

// Those are the base classes for each object in symulation 

// Colision detection based on SAT repo
// https://github.com/Zwo1in/Colsion-detection-based-on-SAT
#include "separatedAxisTheorem.hpp"
#include "SFML/Graphics.hpp"
#include <cmath>


// The parent of each drawable object in symulation
class Floating {
    protected:
    // physix variables 
    double velocity;
    double startVel;
    double gravity;
    double startGrav;
    // rotation and position
    double rotation;
    double startRot;
    sf::Vector2f pos;
    sf::Vector2f startPos;
    Floating( sf::Vector2f pos_, double rotation_, double velocity_ );
    public:
    // returns global boundings of center
    sf::Vector2f getPos();
    
    virtual bool colCheck( sat::Triangle* tri ) {};
    virtual void draw( sf::RenderWindow& win ) {};
    virtual void update( int timePoint ) {};
    virtual void reset() {};
};

class Rectangle :public Floating {
    protected:
    double width;
    double height;
    sf::RectangleShape drawing;
    sat::Rect body;

    public:
    Rectangle( double x, double y, double width_, double height_, double rotation_, double velocity = 0, sf::Color color = sf::Color(0, 38, 153, 200) );
    bool colCheck( sat::Triangle* tri );
    void draw( sf::RenderWindow& win );
    void update( int timePoint );
    void reset();
};

class Triangle :public Floating {
    protected:
    sf::ConvexShape drawing;
    sat::Triangle body;

    public:
    Triangle( double x, double y, double width, double height, double rotation_, double velocity = 0, sf::Color color = sf::Color(0, 102, 153, 200) );
    bool colCheck( sat::Triangle* tri );
    void draw( sf::RenderWindow& win );
    void update( int timePoint );
    void reset();
};

class Circle :public Floating {
    protected:
    double radius;
    sf::CircleShape drawing;
    sat::Circle body;

    public:
    Circle( double x, double y, double radius_, double velocity = 0, sf::Color color = sf::Color( 180, 180, 180, 200 ) );
    bool colCheck( sat::Triangle* tri );
    void draw( sf::RenderWindow& win );
    void update( int timePoint );
    void reset();
};

#endif