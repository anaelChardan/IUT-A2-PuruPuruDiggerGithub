#ifndef __PuruPuruDigger__GraphicAudibleElement__
#define __PuruPuruDigger__GraphicAudibleElement__

#include <iostream>
#include "GraphicElement.h"


class GraphicAudibleElement : public GraphicElement {
    protected :
        bool isOn;
        static sf::Image my_image ;
    public :
        virtual void setImageToSprite();
        virtual void reverse() = 0;
    
        virtual void changeTheme( std::string theme );
        virtual void mouseButtonPressed(sf::Event event);
};

#endif /* defined(__PuruPuruDigger__GraphicAudibleElement__) */
