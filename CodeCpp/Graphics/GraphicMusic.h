#ifndef __PuruPuruDigger__GraphicMusic__
#define __PuruPuruDigger__GraphicMusic__

#include <iostream>
#include "GraphicAudibleElement.h"

class GraphicMusic : public GraphicAudibleElement {
    public :
        virtual void setImageToSprite();
        GraphicMusic();
        virtual void reverse();
    
        virtual void mouseButtonPressed(sf::Event event);
};

#endif /* defined(__PuruPuruDigger__GraphicMusic__) */
