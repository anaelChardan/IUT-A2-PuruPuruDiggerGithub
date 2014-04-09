//
//  GraphicElement.h
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 08/04/2014.
//
//

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
        virtual bool setTeacherMode() = 0;
        virtual bool setAnanasMode() = 0;
        virtual void draw( sf::RenderWindow * _window ) const = 0;
        virtual void setSpriteAndDraw( int x, int y, sf::RenderWindow * _window ) = 0;
};

#endif /* defined(__PuruPuruDigger__GraphicElement__) */
