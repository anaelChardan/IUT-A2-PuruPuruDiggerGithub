#ifndef __PuruPuruDigger__LanguageGraphic__
#define __PuruPuruDigger__LanguageGraphic__

#include <iostream>
#include "GraphicElement.h"

class LanguageGraphic : public GraphicElement {
    protected :
        static sf::Image my_image ;
    public :
        virtual void setImageToSprite();
        void setHover();
        void reset();
        virtual void mouseMoved(sf::Event event);
        virtual void changeTheme( std::string theme );

};

#endif /* defined(__PuruPuruDigger__LanguageGraphic__) */
