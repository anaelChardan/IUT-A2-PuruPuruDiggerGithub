#ifndef __PuruPuruDigger__GraphicMusic__
#define __PuruPuruDigger__GraphicMusic__

#include <iostream>
#include "GraphicAudibleElement.h"

class GraphicMusic : public GraphicAudibleElement {
    public :
        virtual void setImageToSprite();
        GraphicMusic();
        virtual void reverse();
        static sf::Music my_musicLevel;
  
        virtual void mouseMoved(sf::Event event);
        virtual void keyPressed(sf::Event event);
        virtual void textEntered(sf::Event event);
        virtual void mouseButtonPressed(sf::Event event);
        virtual void preDisplay();
        virtual void postDisplay();
};

#endif /* defined(__PuruPuruDigger__GraphicMusic__) */
