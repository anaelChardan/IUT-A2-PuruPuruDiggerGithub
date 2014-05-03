#ifndef __PuruPuruDigger__GraphicElement__
#define __PuruPuruDigger__GraphicElement__

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "../Observers/EventObserver.h"

class GraphicElement : public EventObserver {
    protected :
        sf::Sprite my_sprite;
    public :
        virtual ~GraphicElement();
        virtual void setImageToSprite() = 0; // On associt l'image à son sprite
        virtual void setSpriteAndDraw( int x, int y, sf::RenderWindow * _window );
        virtual void draw( sf::RenderWindow* _window ) const ;
        bool isInZone( int x, int y ) const;
        int getXPos() const;
        int getYPos() const;

    
        virtual void mouseMoved(sf::Event event);
        virtual void keyPressed(sf::Event event);
        virtual void textEntered(sf::Event event);
        virtual void mouseButtonPressed(sf::Event event);
        virtual void preDisplay();
        virtual void postDisplay();
        virtual void changeTheme( std::string theme );
    
};

#endif /* defined(__PuruPuruDigger__GraphicElement__) */
