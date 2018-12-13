#include <core.hpp>
#include <iostream>
std::string toString( double a ) {
    std::ostringstream os;
    os << a;
    return os.str();
}
std::string toString( int a ) {
    std::ostringstream os;
    os << a;
    return os.str();
}

Core::Core() {
    pause = false;
    lifeTime = 200;
    generation = 0;

    // Green
    double rate1 = 0.03, prop1 = 0.2; 
    teams.emplace_back( Population( 40, 0.6, lifeTime, 400, 750, 0.25, rate1, prop1, sf::Color(26, 255, 26, 200) ) );
    // Orange
    double rate2 = 0.035, prop2 = 0.15; 
    teams.emplace_back( Population( 40, 0.6, lifeTime, 400, 750, 0.25, rate2, prop2, sf::Color(255, 102, 0, 200) ) );
    // Blue
    double rate3 = 0.03, prop3 = 0.15; 
    teams.emplace_back( Population( 40, 0.6, lifeTime, 400, 750, 0.25, rate3, prop3, sf::Color(0, 204, 255, 200) ) );
    // Yellow
    double rate4 = 0.015, prop4 = 0.4; 
    teams.emplace_back( Population( 40, 0.6, lifeTime, 400, 750, 0.25, rate4, prop4, sf::Color(255, 255, 0, 200) ) );
    // Purple
    double rate5 = 0.025, prop5 = 0.17; 
    teams.emplace_back( Population( 40, 0.6, lifeTime, 400, 750, 0.25, rate5, prop5, sf::Color(204, 51, 255, 200) ) );
    // Obstacles
    objects.push_back( new Triangle( 650, 650, 100, 150, 0 ) );
    objects.push_back( new Circle( 300, 600, 25 ) );
    objects.push_back( new Circle( 500, 600, 25 ) );
    objects.push_back( new Triangle( 150, 650, 100, 150, 0 ) );
    objects.push_back( new Triangle( 400, 443, 200, 180, 180 ) );
    objects.push_back( new Rectangle( 175, 225, 200, 25, 30 ) );
    objects.push_back( new Rectangle( 625, 225, 200, 25, -30 ) );
    //Target
    objects.push_back( new Circle( 400, 100, 30, 0, sf::Color(102, 255, 255) ) );

    // stats displaying 
    font.loadFromFile( "NotoSansCJK-Bold.ttc" );
    for ( auto& text : texts ) {
        text.setFont( font );
        text.setCharacterSize( 12 );
    }
    texts[0].setColor( sf::Color::White );
    texts[1].setColor( sf::Color(26, 255, 26, 200) );
    texts[2].setColor( sf::Color(255, 102, 0, 200) );
    texts[3].setColor( sf::Color(0, 204, 255, 200) );
    texts[4].setColor( sf::Color(255, 255, 0, 200) );
    texts[5].setColor( sf::Color(204, 51, 255, 200) );
    texts[6].setColor( sf::Color::White );
    texts[6].setCharacterSize(15);
    texts[0].setPosition(20,  720);
    texts[1].setPosition(150, 720);
    texts[2].setPosition(200, 720);
    texts[3].setPosition(260, 720);
    texts[4].setPosition(305, 720);
    texts[5].setPosition(360, 720);
    texts[6].setPosition(650, 750);
    s[0] = toString( int(generation) );
    s[1] = "Green";
    s[2] = toString( rate1 );
    s[3] = toString( prop1 );
    s[4] = "0";
    s[5] = "Orange";
    s[6] = toString( rate2 );
    s[7] = toString( prop2 );
    s[8] = "0";
    s[9] = "Blue";
    s[10] = toString( rate3 );
    s[11] = toString( prop3 );
    s[12] = "0";
    s[13] = "Yellow";
    s[14] = toString( rate4 );
    s[15] = toString( prop4 );
    s[16] = "0";
    s[17] = "Purple";
    s[18] = toString( rate5 );
    s[19] = toString( prop5 );
    s[20] = "0";
}
Core::~Core() {
    while ( !objects.empty() ) {
        delete objects.back();
        objects.pop_back();
    }
}
void Core::play( sf::RenderWindow& win, fpsClock& clock ) {
    // the simulation time point counter
    int counter = 0;
    while ( win.isOpen() ) {
        handleEvents( win );
        // at the clock tick
        if( clock.tick() && !pause ) { 
            // update rats
            update( counter );
            // display 'em
            display( win );
            // if the life time is reached
            if ( counter++ > lifeTime + 10 ) {
                generation++;
                // judge and evolve
                judge( objects.back() );
                reset();
                counter = 0;
            }
        }
    }
}
bool Core::handleEvents( sf::RenderWindow& win ) {
    sf::Event event;
    while ( win.pollEvent( event ) ) {
        switch ( event.type ) {
            case sf::Event::Closed:
                win.close();
                break;
            case sf::Event::KeyPressed:
                if ( event.key.code == sf::Keyboard::Space )
                    pause = !pause;
                else if ( event.key.code == sf::Keyboard::Num1 )
                    teams[0].toggle();
                else if ( event.key.code == sf::Keyboard::Num2 )
                    teams[1].toggle();
                else if ( event.key.code == sf::Keyboard::Num3 )
                    teams[2].toggle();
                else if ( event.key.code == sf::Keyboard::Num4 )
                    teams[3].toggle();
                else if ( event.key.code == sf::Keyboard::Num5 )
                    teams[4].toggle();
                break;
        }
    }
}
void Core::update( int counter ) {
    for ( auto* obj : objects )
        obj -> update( counter );

    for ( auto& team : teams ) {
        team.update( counter );
        team.colCheck( objects );
    }
}
void Core::judge( Floating* target ) {
    s[0] = toString( int(generation) );
    for ( int i = 0; i < 5; i++ ) {
        s[ 4*(i + 1) ] = toString( teams[i].judge( target ) );
    }
}
void Core::stats( sf::RenderWindow& win ) {
    texts[0].setString( "                          Team\nMutation Strength\n   Mutation Chance\n                          Score" );
    texts[1].setString( s[1] + "\n" + s[2] + "\n" + s[3] + "\n" + s[4] );
    texts[2].setString( s[5] + "\n" + s[6] + "\n" + s[7] + "\n" + s[8] );
    texts[3].setString( s[9] + "\n" + s[10] + "\n" + s[11] + "\n" + s[12] );
    texts[4].setString( s[13] + "\n" + s[14] + "\n" + s[15] + "\n" + s[16] );
    texts[5].setString( s[17] + "\n" + s[18] + "\n" + s[19] + "\n" + s[20] );
    texts[6].setString( "Generation " + s[0] );
    for ( auto& text : texts ) 
        win.draw(text);
}
void Core::display( sf::RenderWindow& win ) {
    win.clear( sf::Color(51, 51, 51) );
    for ( auto& team : teams )
        team.display( win );
    for ( auto* obj : objects )
        obj -> draw( win );
    stats( win );
    win.display();
}
void Core::reset() {
    for ( auto& team : teams )
        team.reset();
    for ( auto* obj : objects )
        obj -> reset();
}