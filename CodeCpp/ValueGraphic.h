//
//  ValueGraphic.h
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 08/04/2014.
//
//

#ifndef __PuruPuruDigger__ValueGraphic__
#define __PuruPuruDigger__ValueGraphic__

#include <iostream>
#include "GraphicElement.h"

class ValueGraphic : public GraphicElement {
    protected :
        static sf::Font my_font;
        sf::String my_string;
        static sf::Image my_image;
    public :
        virtual bool setAnanasMode();
        virtual bool setTeacherMode();
        virtual void SetTextAndDraw( std::string text );
        virtual void draw( sf::RenderWindow * _window );
};

#endif /* defined(__PuruPuruDigger__ValueGraphic__) */
