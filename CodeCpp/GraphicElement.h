#ifndef __PuruPuruDigger__GraphicElement__
#define __PuruPuruDigger__GraphicElement__

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class GraphicElement {
    protected :
        sf::Sprite my_sprite;
    public :
        virtual ~GraphicElement();
        virtual void setTeacherMode() = 0; // On change l'image
        virtual void setAnanasMode() = 0; // On change l'image
        virtual void setImageToSprite() = 0; // On associt l'image à son sprite
        virtual void setSpriteAndDraw( int x, int y, sf::RenderWindow * _window );
        virtual void draw( sf::RenderWindow* _window ) const ;
        bool isInZone( int x, int y ) const;
        int getXPos() const;
        int getYPos() const;
};

#endif /* defined(__PuruPuruDigger__GraphicElement__) */
