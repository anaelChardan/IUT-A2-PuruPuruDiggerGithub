#ifndef __PuruPuruDigger__CellTextGraphic__
#define __PuruPuruDigger__CellTextGraphic__

#include <iostream>
#include "CellBaseGraphic.h"

class CellTextGraphic : public CellBaseGraphic {
    protected :
        static sf::Font my_font;
        sf::String my_string;
    public :
        virtual ~CellTextGraphic();
        virtual void setAnanasMode();
        virtual void setTeacherMode();
        virtual void setSpriteAndDraw( int x, int y, sf::RenderWindow * _window, std::string _string );
        virtual void setImageToSprite();
};

#endif /* defined(__PuruPuruDigger__CellTextGraphic__) */
