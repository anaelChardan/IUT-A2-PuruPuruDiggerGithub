#ifndef __PuruPuruDigger__ButtonGraphic__
#define __PuruPuruDigger__ButtonGraphic__

#include <iostream>
#include "GraphicElement.h"


class ButtonGraphic : public GraphicElement {
    protected :
        static sf::Image my_image ;
        static sf::Font my_font;
    
        sf::String my_string;
    
    public :
        virtual void setImageToSprite();
        virtual void setSpriteAndDraw( int x, int y, sf::RenderWindow * _window, std::string );
        void setHover();
        void reset();
        virtual void draw(sf::RenderWindow* _window) const;    
        virtual void mouseMoved(sf::Event event);
        virtual void mouseButtonPressed(sf::Event event);
        virtual void changeTheme( std::string theme );
};

#endif /* defined(__PuruPuruDigger__ButtonGraphic__) */
