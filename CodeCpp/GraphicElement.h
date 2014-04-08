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

class GraphicElement : public sf::Drawable {
    protected :
        sf::Sprite sprite;
    public :
        virtual bool setTeacherMode() = 0;
        virtual bool setAnanasMode() = 0;
        virtual void draw() = 0;
        virtual void Render( sf::RenderTarget &target ) const;
};

#endif /* defined(__PuruPuruDigger__GraphicElement__) */
