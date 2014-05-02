#ifndef __PuruPuruDigger__LanguageGraphic__
#define __PuruPuruDigger__LanguageGraphic__

#include <iostream>
#include "GraphicElement.h"

class LanguageGraphic : public GraphicElement {
    protected :
        static sf::Image my_image ;
    public :
        virtual void setImageToSprite();
        virtual void setTeacherMode();
        virtual void setAnanasMode();
        void setHover();
        void reset();
    
    
        virtual void mouseMoved(sf::Event event);
        virtual void keyPressed(sf::Event event);
        virtual void textEntered(sf::Event event);
        virtual void mouseButtonPressed(sf::Event event);
        virtual void preDisplay();
        virtual void postDisplay();
};

#endif /* defined(__PuruPuruDigger__LanguageGraphic__) */
