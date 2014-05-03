#ifndef __PuruPuruDigger__CellTextGraphic__
#define __PuruPuruDigger__CellTextGraphic__

#include <iostream>
#include "CellBaseGraphic.h"

class CellTextGraphic : public CellBaseGraphic {
    protected :
        static sf::Font my_font;
        sf::String my_string;
    public :
        virtual void setSpriteAndDraw( int x, int y, sf::RenderWindow * _window, std::string _string );
        virtual void setImageToSprite();
        virtual void changeTheme( std::string theme ); 
};

#endif /* defined(__PuruPuruDigger__CellTextGraphic__) */
